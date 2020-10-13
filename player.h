#pragma once
#include <iostream>
/**
* \class Player
* \brief Player class
*/
class Player
{
	const std::string Name;
	int HP;
	const int DMG;
	double AtkCoolDown;

	void Damage (Player* player)const;
public:
	Player(std::string name, int hp, int dmg, double atkCoolDown) :Name(name), HP(hp), DMG(dmg), AtkCoolDown(atkCoolDown) {}


	std::string getName() const { return Name; }
	int	getHP() const { return HP; }
	int getDMG() const { return DMG; }
	double getAtkCoolDown() const { return AtkCoolDown; }
	void setAtkCoolDown(int atkCoolDown)  {  AtkCoolDown=  atkCoolDown; }

	friend std::ostream& operator<<(std::ostream& o, Player& d);
	void Fight(Player* player);
	static Player* parseUnit(const std::string file);
};
