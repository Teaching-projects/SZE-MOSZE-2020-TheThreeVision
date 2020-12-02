#include "Hero.h"

void Hero::levelup(int levels)
{
	for (int i = 0; i < levels; i++)
	{
       
		maxHP += (int)Health_point_bonus_per_level;
        setDMG(getDamage()+ Damage_bonus_per_level);
        setDefense((int)(getDefense() + Defense_bonus_per_level));
        setAtkCoolDown(getAttackCoolDown()* Cooldown_multiplier_per_level);
		setHP(maxHP);
        Level++;
	}

}

void Hero::fightTilDeath(Monster& m)
{
    double atkcdownThis = this->getAttackCoolDown(); double atkcdownOther = m.getAttackCoolDown();
    double cooldownCounterThis = 0, cooldownCounterOther = 0;

    while (this->isAlive() && m.isAlive())
    {
        if (cooldownCounterThis + atkcdownThis < atkcdownOther + cooldownCounterOther) {

            cooldownCounterThis += atkcdownThis;
            this->Damage(&m);


        }
        else {
            if (cooldownCounterThis + atkcdownThis > atkcdownOther + cooldownCounterOther) {
                cooldownCounterOther += atkcdownOther;
                m.Damage(this);
            }
            else {//ha egyszerre ütnének akkor az üt amelyik a Fight-ot id�totta

                cooldownCounterThis += atkcdownThis;
                this->Damage(&m);
            }
        }

    }

}

void Hero::increaseXP(damage dmg)
{
	XP += dmg.physical+ dmg.magical;
}

void Hero::Damage(Monster* monster)
{
        int thiXP = getXP();
        damage damage = getDamage();
    //magical (always)
        if ((monster->getHealthPoints() - getDamage().magical) >= 0)
        {
            monster->setHP(monster->getHealthPoints() - getDamage().magical);
        }
        else {
            damage.magical = monster->getHealthPoints();
            monster->setHP(0);
        }
    //physical (with defense calc)

        //realDMG is always positive
        int realDMG=getDamage().physical - monster->getDefense();
        if (realDMG < 0) { realDMG = 0; }
        //do the physical damage
        if ((monster->getHealthPoints() - realDMG) >= 0)
        {
            monster->setHP(monster->getHealthPoints() - realDMG);
        }
        else {
            damage.physical = monster->getHealthPoints();
            monster->setHP(0);
        }
        //XP and levels
        this->increaseXP(damage);//this xp-je n� annyival, amenyi sebz�st a M�SIK szenvedett
        this->levelup(this->getXP() / (int)Experience_per_level - thiXP / (int)Experience_per_level);

}

Hero Hero::parse(const std::string toParse)
{
    JSON Data = JSON::ParseJsonFilename(toParse);
    return Hero(
        Data.get<std::string>("name"),
        Data.get<int>("points"),
        damage(Data.get<int>("damage"), Data.get<int>("\"magical-damage\"") ),
        Data.get<double>("defense"),
        Data.get<double>("cooldown"),        
        Data.get<double>("experience_per_level"),
        Data.get<double>("health_point_bonus_per_level"),
        damage(Data.get<int>("damage_bonus_per_level"), Data.get<int>("magical-damage_bonus_per_level")),
        Data.get<double>("defense_bonus_per_level"),
        Data.get<double>("cooldown_multiplier_per_level")
    );
}