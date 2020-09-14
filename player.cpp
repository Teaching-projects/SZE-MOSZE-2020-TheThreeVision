#include "player.h"

void Player::Damage(Player* player)
{
	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
	else { player->HP = 0; }
}
void Player::DamagePrint(Player* player)
{
	std::cout << Nev << " -> " << player->getNev() << "\n";
	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
	else { player->HP = 0; }
	std::cout << *this << "\n" << *player << "\n";
}

std::ostream & operator<<(std::ostream & o, Player & d)
{
	return o << d.getNev() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}
