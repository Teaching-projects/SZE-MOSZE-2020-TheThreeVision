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


bool Monster::isAlive()
{
    if (this->getHealthPoints() > 0)
    {
        return true;
    }
    return false;
}
/*
void Monster::Fight(Monster* otherplayer)
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
            else {//ha egyszerre �tn�nek akkor az �t amelyik a Fight-ot id�totta
                
                cooldownCounterThis += atkcdownThis;
                this->Damage(otherplayer);
            }
        }

    }
}

*/
Monster Monster::parse(const std::string toParse) {

    std::string toGo = "";
    if (toParse[0] == '"' && toParse[toParse.length()-1] == '"')
    {
        for (int i = 1; i < toParse.length()-1; i++)
        {
            toGo += toParse[i];
        }
    }
    
    JSON Data = JSON::ParseJsonFilename(toGo);

    return Monster(
        Data.get<std::string>("name"),
        Data.get<int>("points"),
        Data.get<int>("damage"),
        Data.get<double>("cooldown")
    );
}



std::ostream& operator<<(std::ostream& o, Monster& d)
{
	return o << d.getName() << ": HP: " << d.getHealthPoints() << ", DMG: " << d.getDamage();
}



