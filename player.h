#pragma once
#include <iostream>
#include <string>


class Player
{
	const std::string Name;
	int HP;
	int DMG;

protected:
	void Damage(Player* player)const;
	void setHP(int h) { HP = h; }

	void setDMG(int d) { DMG = d; }

public:
	Player(std::string name, int hp, int dmg) :Name(name), HP(hp), DMG(dmg) {}

	std::string getName() const { return Name; }

	int  getDMG()const { return DMG; }
	int	getHP() { return HP; }
	friend std::ostream& operator<<(std::ostream& o, Player& d);
	void Fight(Player* player);
	static Player* parseUnit(const std::string file);


};

class AdventurerPlayer : public Player
{
private:
	int XP = 0;
	int maxHP;

protected:
	void levelup(int levels);
	void increaseXP(int dmg);

public:

	void Fight(AdventurerPlayer* otherplayer);
	AdventurerPlayer(std::string name, int hp, int dmg) :Player(name, hp, dmg), maxHP(hp) {};

	int getXP() { return XP; }
	static AdventurerPlayer* parseUnit(const std::string file);
};