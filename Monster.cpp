#include "Monster.h"
#include "JSON.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
//something like in the hero
void Monster::Damage(Monster *monster) const
{
    //magical
    if ((monster->HP - DMG.magical) >= 0)
    {
        monster->HP -= DMG.magical;
    }
    else
    {
        monster->HP = 0;
    }
    //physical
    //realDMG is always positive
    int realDMG = DMG.physical - monster->Defense;
    if (realDMG < 0)
    {
        realDMG = 0;
    }
    //do the physical damage
    if ((monster->HP - realDMG) >= 0)
    {
        monster->HP -= realDMG;
    }
    else
    {
        monster->HP = 0;
    }
}

bool Monster::isAlive()
{
    if (this->getHealthPoints() > 0)
    {
        return true;
    }
    return false;
}

Monster Monster::parse(const std::string toParse)
{

    std::string toGo = "";
    if (toParse[0] == '"' && toParse[toParse.length() - 1] == '"')
    {
        for (unsigned int i = 1; i < toParse.length() - 1; i++)
        {
            toGo += toParse[i];
        }
    }
    else
    {
        toGo = toParse;
    }

    JSON Data = JSON::ParseJsonFilename(toGo);

    return Monster(
        Data.get<std::string>("name"),
        Data.get<int>("points"),
        damage(Data.get<int>("damage"), Data.get<int>("\"magical-damage\"")),
        Data.get<double>("defense"),
        Data.get<double>("cooldown"),
        Data.get<std::string>("texture"));
}

std::ostream &operator<<(std::ostream &o, Monster &d)
{
    return o << d.getName() << ": HP: " << d.getHealthPoints() << ", DMG: " << d.getDamage();
}
