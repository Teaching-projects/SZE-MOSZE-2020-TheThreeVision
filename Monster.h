#pragma once
#include <iostream>
#include "Damage.h"
/**
 * \class Monster
 * 
 * \brief Monster class
 * 
 * \author radvanszkyI
 *
 * \date 2020.10.13. 22:22
 *
 * \note A monster can fight with an other monster while one of them is alive.
 * The end of the fight depends on the HealthPoints, Damages, Defense and the Attackcooldowns of the two monsters.
 */
class Monster
{
	const std::string Name; ///< the Name of the monster
	int HP;					///< the HealthPoints of the monster
	damage DMG;			///< the Damage of the monster
	int Defense;
	double AtkCoolDown;		///< the monster's Attack Cooldown shows that after how many seconds he/she can hit again. 
	const std::string Texture;
protected:
	
	/// simple setter to the Damage
	void setDMG(damage d) { DMG = d; }
	/// simple setter to the Defense
	void setDefense(int def) { Defense = def; }
	/// simple setter to the AttackCooldown
	void setAtkCoolDown(double atkCoolDown)  {  AtkCoolDown=  atkCoolDown; }

public:
	/// monster construct, what put the input parameters to the data members
	Monster(std::string name, int hp, damage dmg,int defense, double atkCoolDown, std::string texture) :Name(name), HP(hp), DMG(dmg),Defense(defense), AtkCoolDown(atkCoolDown) , Texture(texture){}
	/// copy construct, what make a copy from the parameter
	Monster(Monster* monster) :Name(monster->getName()), HP(monster->getHealthPoints()), DMG(monster->getDamage()), Defense(monster->getDefense()), AtkCoolDown(monster->getAttackCoolDown()), Texture(monster->getTexture()){};
	/// this method damage an other monster
	void Damage(Monster* monster/**[in] the monster witch is injured*/)const;
	///simple getter to the Name
	std::string getName() const { return Name; }
	///simple getter to the HealthPoints
	int	getHealthPoints() const { return HP; }
	///simple getter to the Damage
	damage getDamage() const { return DMG; }
	///simple getter to the Defense
	int getDefense() const { return Defense; }
	///simple getter to the AttackCooldown
	double getAttackCoolDown() const { return AtkCoolDown; }
	///simple getter to the Texture
	std::string getTexture() const { return Texture; }
	/**
	 * \brief This method decide the monster is alive or died
	 * \return return with true if the monster is alive else return with false
	 */
	bool isAlive();
	/// simple setter to the HealthPoints
	void setHP(int h) { HP = h; }
	
	
	/// easy way to print a monster
	friend std::ostream& operator<<(std::ostream& o/**[in] is the output stream*/, Monster& d/**[in] is the printed monster*/);
	
	/**
	 * \brief This method use the parser class, and reads a .json file, and get the keys and the attached data and returns a new Monster object
	 * \return return with a Monster object
	 * \throw throw a "runtime_error" if something wrong
	 */
	static Monster parse(const std::string file/**[in] is the .json file's name*/);
};

