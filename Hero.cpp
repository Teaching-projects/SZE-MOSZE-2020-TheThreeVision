#include "Hero.h"


void Hero::levelup(int levels)
{
	for (int i = 0; i < levels; i++)
	{
		maxHP = (int)round((double)maxHP * 1.1);
		setDMG((int)round((double)getDamage() * 1.1));
        setAtkCoolDown(getAttackCoolDown()*0.9);
		setHP(maxHP);
        Level++;
	}

}

void Hero::Fight(Hero* otherplayer)
{
    this->Damage(otherplayer);
    double atkcdownThis = this->getAttackCoolDown(); double atkcdownOther = otherplayer->getAttackCoolDown();
    double cooldownCounterThis = 0, cooldownCounterOther = 0;

    while (this->getHealthPoints() > 0 && otherplayer->getHealthPoints() > 0)
    {
        if (cooldownCounterThis + atkcdownThis < atkcdownOther + cooldownCounterOther) {

            cooldownCounterThis += atkcdownThis;
            this->Damage(otherplayer);


        }
        else {
            if (cooldownCounterThis + atkcdownThis > atkcdownOther + cooldownCounterOther) {
                cooldownCounterOther += atkcdownOther;
                otherplayer->Damage(this);
            }
            else {//ha egyszerre ütnének akkor az üt amelyik a Fight-ot id�totta

                cooldownCounterThis += atkcdownThis;
                this->Damage(otherplayer);
            }
        }

    }

}

void Hero::fightTilDeath(Monster m)
{
    this->Damage(&m);
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

void Hero::Damage(Hero* player) 
{
    int othXP = player->getXP(), thiXP = this->getXP();
    int damage = getDamage();
    if ((player->getHealthPoints() - getDamage()) >= 0)
    {
        player->setHP(player->getHealthPoints() - getDamage());
    }
    else {
        damage = player->getHealthPoints();
        player->setHP(0); 
    }

    this->increaseXP(damage);//this xp-je n� annyival, amenyi sebz�st a M�SIK szenvedett
    this->levelup(this->getXP() / 100 - thiXP / 100);

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
    this->levelup(this->getXP() / 100 - thiXP / 100);

}

Hero* Hero::parse(const std::string toParse)
{
    std::map<std::string, std::string> Map;
    
    Map = JSON::ParseJsonFilename(toParse);
    
    return new Hero(Map["name"], stoi(Map["base_health_points"]), stoi(Map["base_damage"]), stod(Map["base_attack_cooldown"]));
}