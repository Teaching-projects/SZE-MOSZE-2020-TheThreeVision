#include "Monster.h"
#include "JSON.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
//TODO (something like in the hero)
void Monster::Damage(Monster* monster)const
{
 //magical
	if ((monster->HP - DMG.magical) >= 0)
	{
		monster->HP -= DMG.magical;

	}
	else { monster->HP = 0; }
 //physical
    //realDMG is always positive
    int realDMG = DMG.physical - monster->Defense;
    if (realDMG < 0) { realDMG = 0; }
    //do the physical damage
    if ((monster->HP - realDMG) >= 0)
    {
        monster->HP -= realDMG;
    }
    else { monster->HP = 0; }
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
        for (unsigned int i = 1; i < toParse.length()-1; i++)
        {
            toGo += toParse[i];
        }
    }else{
        toGo = toParse;
    }
    
    JSON Data = JSON::ParseJsonFilename(toGo);

    return Monster(
        Data.get<std::string>("name"),
        Data.get<int>("points"),
        damage(Data.get<int>("damage"), Data.get<int>("\"magical-damage\"")),
        Data.get<double>("defense"),
        Data.get<double>("cooldown")
    );
}



std::ostream& operator<<(std::ostream& o, Monster& d)
{
	return o << d.getName() << ": HP: " << d.getHealthPoints() << ", DMG: " << d.getDamage();
}



