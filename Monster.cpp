#include "Monster.h"
#include "JSON.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

void Monster::Damage(Monster* player)const
{

	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
	else { player->HP = 0; }

}

void Monster::Fight(Monster* otherplayer)
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


Monster* Monster::parseUnit(const std::string toParse) {
    std::map<std::string, std::string> Map;
    
    Map = JSON::ParseJsonFilename(toParse);
    
    return new Monster(Map["name"], stoi(Map["hp"]), stoi(Map["dmg"]), stod(Map["atkcd"]));
}



std::ostream& operator<<(std::ostream& o, Monster& d)
{
	return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}



