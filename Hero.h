#include "Monster.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <any>

class Hero : public Monster
{
private:
	int XP = 0;///< the ExperiencePoints of the adventurerPlayer
	int maxHP; ///< the maximum of the adventurerPlayer's HealthPoints

protected:
	/// this method increases maxHP, DMG and decreases AtkCoolDown and sets the HP to maximum
	void levelup(int levels/**[in] is the number of the level increases*/);
	/// add more XP to XP
	void increaseXP(int dmg/**[in] is the number of the added XP*/);
	/**
	 * \brief This method damages the other adventurerPlayer.
	 * \note this method does the increaseXP and the levelup 
	 */	
	void Damage(Hero* player/**[in] the adventurerPlayer who is injured*/);
public:
	/**
	 * \brief fight with another player while one of them is die
	 */
	void Fight(Hero* otherplayer/**[in] is the other player*/);
	/// adventurerPlayer construct, what put the input parameters to the data members
	Hero(std::string name, int hp, int dmg, double atkCoolDown) : Monster(name, hp, dmg, atkCoolDown), maxHP(hp) {};
	/// a simple getter to the ExperiencePoints
	int getXP() { return XP; }
	/**
	 * \brief This method use the parser class, and reads a .json file, and get the keys and the attached data and returns a new AdventurerPlayer object
	 * \return return with an AdventurerPlayer object
	 * \throw throw a "runtime_error" if something wrong
	 */
	static Hero* parseUnit(const std::string file/**[in] is the .json file's name*/);
};