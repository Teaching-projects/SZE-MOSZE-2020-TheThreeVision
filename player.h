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
	void setHP(int hp) { HP = hp; }
	int	getHP() const { return HP; }
	int getDMG() const { return DMG; }

	friend std::ostream& operator<<(std::ostream& o,Player& d);
	std::string Damage(Player* player);
	
};
