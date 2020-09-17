#include "player.h"
#include <iostream>
#include <sstream>


std::string Player::Damage(Player* player)
{
	
	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
    else { player->HP = 0; }
	
    std::ostringstream abc;
    
    abc << Name << " -> " << player->getName() << "\n" << *this << "\n" << *player << "\n";
    
    std::string str = abc.str();
    
    return str;
}

std::ostream & operator<<(std::ostream & o, Player & d)
{
	return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}
