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
	
	/// simple setter to the Damage
	void setDMG(int d) { DMG = d; }
	/// simple setter to the AttackCooldown
	void setAtkCoolDown(int atkCoolDown)  {  AtkCoolDown=  atkCoolDown; }

public:
	/// player construct, what put the input parameters to the data members
	Monster(std::string name, int hp, int dmg, double atkCoolDown) :Name(name), HP(hp), DMG(dmg), AtkCoolDown(atkCoolDown) {}
	//TODO
	Monster(Monster* monster) :Name(monster->getName()), HP(monster->getHealthPoints()), DMG(monster->getDamage()), AtkCoolDown(monster->getAttackCoolDown()) {};
	/// this method damage the other monster
	void Damage(Monster* monster/**[in] the player witch is injured*/)const;
	///simple getter to the Name
	std::string getName() const { return Name; }
	///simple getter to the HealthPoints
	int	getHealthPoints() const { return HP; }
	///simple getter to the Damage
	int getDamage() const { return DMG; }
	///simple getter to the AttackCooldown
	double getAttackCoolDown() const { return AtkCoolDown; }
	bool isAlive();
	/// simple setter to the HealthPoints
	void setHP(int h) { HP = h; }

	
	/// easy way to print a player
	friend std::ostream& operator<<(std::ostream& o/**[in] is the output stream*/, Monster& d/**[in] is the printed player*/);
	/**
	 * \brief fight with another player while one of them is die
	 */
	/*void Fight(Monster* player/**[in] is the other player);*/
	/**
	 * \brief This method use the parser class, and reads a .json file, and get the keys and the attached data and returns a new Monster object
	 * \return return with a Monster object
	 * \throw throw a "runtime_error" if something wrong
	 */

	static Monster parse(const std::string file/**[in] is the .json file's name*/);
};

