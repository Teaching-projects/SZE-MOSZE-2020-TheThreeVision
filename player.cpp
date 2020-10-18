#include "player.h"
#include "parser.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

void Player::Damage(Player* player)const
{

	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
	else { player->HP = 0; }

}



void Player::Fight(Player* otherplayer)
{
    
    this->Damage(otherplayer);
    double atkcdownThis = this->getAtkCoolDown(); double atkcdownOther = otherplayer->getAtkCoolDown();
    double cooldownCounterThis = 0, cooldownCounterOther = 0;
   
    while (this->getHP() > 0 && otherplayer->getHP() > 0)
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
            else {//ha egyszerre �tn�nek akkor az �t amelyik a Fight-ot id�totta
                
                cooldownCounterThis += atkcdownThis;
                this->Damage(otherplayer);
            }
        }

    }
}


Player* Player::parseUnit(const std::string toParse) {
    std::map<std::string, std::string> Map;
    
    Map = Parser::ParseJsonFilename(toParse);

    return new Player(Map["name"], stoi(Map["hp"]), stoi(Map["dmg"]), stod(Map["atkcd"]);
}



std::ostream& operator<<(std::ostream& o, Player& d)
{
	return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}

void AdventurerPlayer::levelup(int levels)
{
	for (int i = 0; i < levels; i++)
	{
		maxHP = (int)round((double)maxHP * 1.1);
		setDMG((int)round((double)getDMG() * 1.1));
        setAtkCoolDown(getAtkCoolDown()*0.9);
		setHP(maxHP);
	}

}

void AdventurerPlayer::Fight(AdventurerPlayer* otherplayer)
{
    this->Damage(otherplayer);
    double atkcdownThis = this->getAtkCoolDown(); double atkcdownOther = otherplayer->getAtkCoolDown();
    double cooldownCounterThis = 0, cooldownCounterOther = 0;

    while (this->getHP() > 0 && otherplayer->getHP() > 0)
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



void AdventurerPlayer::increaseXP(int dmg)
{
	XP += dmg;
}

void AdventurerPlayer::Damage(AdventurerPlayer* player) 
{
    int othXP = player->getXP(), thiXP = this->getXP();
    int damage = getDMG();
    if ((player->getHP() - getDMG()) >= 0)
    {
        player->setHP(player->getHP() - getDMG());
    }
    else {
        damage = player->getHP();
        player->setHP(0); 
    }

    this->increaseXP(damage);//this xp-je n� annyival, amenyi sebz�st a M�SIK szenvedett
    this->levelup(this->getXP() / 100 - thiXP / 100);

}

AdventurerPlayer* AdventurerPlayer::parseUnit(const std::string filename)
{
    std::map<std::string, std::string> Map;
    
    Map = Parser::ParseJsonFilename(toParse);

    return new AdventurePlayer(Map["name"], stoi(Map["hp"]), stoi(Map["dmg"]), stod(Map["atkcd"]);
}

