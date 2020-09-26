#pragma once
#include <iostream>

class Player
{
	const std::string Name;
	int HP;
	const int DMG;
public:
	Player(std::string name, int hp, int dmg) :Name(name), HP(hp), DMG(dmg) {}

	std::string getName() const { return Name; }
	int	getHP() const { return HP; }
	int getDMG() const { return DMG; }

	friend std::ostream& operator<<(std::ostream& o, Player& d);
	void Damage(Player* player);
	static Player* parseUnit(const std::string file);
};
