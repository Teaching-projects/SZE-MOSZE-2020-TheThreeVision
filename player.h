#pragma once
#include <iostream>

class Player
{
	std::string Nev;
	int HP;
	int DMG;
public:
	Player(std::string nev, int hp, int dmg) :Nev(nev), HP(hp), DMG(dmg) {}
	void setNev(std::string nev) { Nev = nev; }
	std::string getNev() const { return Nev; }
	void setHP(int hp) { HP = hp; }
	int	getHP() const { return HP; }
	void setDMG(int dmg) { DMG = dmg; }
	int getDMG() const { return DMG; }

	friend std::ostream& operator<<(std::ostream& o,Player& d);
	void Damage(Player* player);
	void DamagePrint(Player* player);
};
