#include "Hero.h"


void Hero::levelup(int levels)
{
	for (int i = 0; i < levels; i++)
	{
		maxHP += (int)Health_point_bonus_per_level;
		setDMG((int)(getDamage()+ Damage_bonus_per_level));
        setAtkCoolDown(getAttackCoolDown()* 0.9);
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

void Hero::increaseXP(int dmg)
{
	XP += dmg;
}

void Hero::Damage(Monster* monster)
{
    int thiXP = getXP();
    int damage = getDamage();
    if ((monster->getHealthPoints() - getDamage()) >= 0)
    {
        monster->setHP(monster->getHealthPoints() - getDamage());
    }
    else {
        damage = monster->getHealthPoints();
        monster->setHP(0);
    }

    this->increaseXP(damage);//this xp-je n� annyival, amenyi sebz�st a M�SIK szenvedett
    this->levelup(this->getXP() / (int)Experience_per_level - thiXP / (int)Experience_per_level);

}

Hero Hero::parse(const std::string toParse)
{
    JSON Data = JSON::ParseJsonFilename(toParse);

    return Hero(
        Data.get<std::string>("name"),
        Data.get<int>("points"),
        Data.get<int>("damage"),
        Data.get<double>("cooldown"),
        Data.get<double>("experience_per_level"),
        Data.get<double>("health_point_bonus_per_level"),
        Data.get<double>("damage_bonus_per_level"),
        Data.get<double>("cooldown_multiplier_per_level")
    );
}