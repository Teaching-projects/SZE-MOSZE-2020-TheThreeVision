#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Player
{
	const std::string Name;
	int HP;
	int DMG;
protected:
	void Damage(Player* player)const;
public:
	Player(std::string name, int hp, int dmg) :Name(name), HP(hp), DMG(dmg) {}
	void setHP(int h) { HP = h; }
	std::string getName() const { return Name; }
	int	getHP() { return HP; }
	void setDMG(int d) { DMG = d; }
	int  getDMG()const { return DMG; }

	friend std::ostream& operator<<(std::ostream& o, Player& d);
	void Fight(Player* player);
	static Player* parseUnit(const std::string file);


};

class AdventurerPlayer : public Player
{
private:
	int XP=0;
	int maxHP;

public:
	void levelup(int levelnew);
	void Fight(AdventurerPlayer* otherplayer);
	AdventurerPlayer(std::string name, int hp, int dmg) :Player(name, hp, dmg), maxHP(hp){};
	void increaseXP(int dmg);
	int getXP() { return XP; }
	static AdventurerPlayer* parseUnit(const std::string file);
};