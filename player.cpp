#include "player.h"
#include "parser.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


void Player::Damage(Player* player)
{

    if ((player->HP - DMG) >= 0)
    {
        player->HP -= DMG;

    }
    else { player->HP = 0; }

}

Player* Player::parseUnit(const std::string toParse) {
    std::map<std::string, std::string> Map;

    Map = Parser::ParseJson(toParse);
    
    return new Player(Map["name"], stoi(Map["hp"]), stoi(Map["dmg"]));
}

std::ostream& operator<<(std::ostream& o, Player& d)
{
    return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}

