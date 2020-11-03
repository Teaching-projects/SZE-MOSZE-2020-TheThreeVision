#pragma once
#include <iostream>

/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * \author radvanszkyI
 *
 * \date 2020.10.13. 22:22
 *
 * \note A player can fight with an other player while one of them is alive.
 * The end of the fight depends on the HealthPoints, Damages and the Attackcooldowns of the two Players
 */
class Monster
{
	const std::string Name; ///< the Name of the player
	int HP;					///< the HealthPoints of the player
	int DMG;			///< the Damage of the player
	double AtkCoolDown;		///< the player's Attack Cooldown shows that after how many seconds he/she can hit again. 

protected:
	/// this method damage the other player
	void Damage (Monster* player/**[in] the player who is injured*/)const;
	/// simple setter to the HealthPoints
	void setHP(int h) { HP = h; }
	/// simple setter to the Damage
	void setDMG(int d) { DMG = d; }
	/// simple setter to the AttackCooldown
	void setAtkCoolDown(int atkCoolDown)  {  AtkCoolDown=  atkCoolDown; }
	
public:
	/// player construct, what put the input parameters to the data members
	Monster(std::string name, int hp, int dmg, double atkCoolDown) :Name(name), HP(hp), DMG(dmg), AtkCoolDown(atkCoolDown) {}

	///simple getter to the Name
	std::string getName() const { return Name; }
	///simple getter to the HealthPoints
	int	getHP() const { return HP; }
	///simple getter to the Damage
	int getDMG() const { return DMG; }
	///simple getter to the AttackCooldown
	double getAtkCoolDown() const { return AtkCoolDown; }


	
	/// easy way to print a player
	friend std::ostream& operator<<(std::ostream& o/**[in] is the output stream*/, Monster& d/**[in] is the printed player*/);
	/**
	 * \brief fight with another player while one of them is die
	 */
	void Fight(Monster* player/**[in] is the other player*/);
	/**
	 * \brief This method use the parser class, and reads a .json file, and get the keys and the attached data and returns a new Monster object
	 * \return return with a Monster object
	 * \throw throw a "runtime_error" if something wrong
	 */
	static Monster* parseUnit(const std::string file/**[in] is the .json file's name*/);
};

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
	Hero(std::string name, int hp, int dmg, double atkCoolDown) :Monster(name, hp, dmg, atkCoolDown), maxHP(hp) {};
	/// a simple getter to the ExperiencePoints
	int getXP() { return XP; }
	/**
	 * \brief This method use the parser class, and reads a .json file, and get the keys and the attached data and returns a new AdventurerPlayer object
	 * \return return with an AdventurerPlayer object
	 * \throw throw a "runtime_error" if something wrong
	 */
	static Hero* parseUnit(const std::string file/**[in] is the .json file's name*/);
};