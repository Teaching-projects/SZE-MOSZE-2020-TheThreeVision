#include "player.h"
#include <iostream>


void Player::Damage(Player* player)
{
	
	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
    else { player->HP = 0; }
	
}

void Player::print(Player* player){
    std::cout << Name << " -> " << player->getName() << std::endl;
    std::cout << *this << '\n' << *player << '\n';
}

std::ostream & operator<<(std::ostream & o, Player & d)
{
	return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}

