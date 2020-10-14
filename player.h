#pragma once
#include <iostream>
/**
 * \class Player
 * 
 * \brief Player class
 * 
 * \author radvanszkyI
 *
 * \date 2020.10.13. 22:22
 *
 * \note A player can fight with an other player while one of them is die.
 * The fight end is depend on the two player's HealPoints, Damages, and the AttackCooldowns.
 */
class Player
{
private:
	const std::string Name; ///< the Name of the player
	int HP;					///< the HealPoints of the player
	const int DMG;			///< the Damage of the player
	double AtkCoolDown;		///< the player's Attack Cooldown shows that after how many seconds he/she can hit again. 

	/// this method damage the other player
	void Damage (Player* player/**[in] the player who is injured*/)const;
public:
	
	/// player construct, what put the input parameters to the data members
	Player(std::string name, int hp, int dmg, double atkCoolDown) :Name(name), HP(hp), DMG(dmg), AtkCoolDown(atkCoolDown) {}

	///simple getter to the Name
	std::string getName() const { return Name; }
	///simple getter to the HealPoint
	int	getHP() const { return HP; }
	///simple getter to the Damage
	int getDMG() const { return DMG; }
	///simple getter to the AttackCooldown
	double getAtkCoolDown() const { return AtkCoolDown; }
	/// simple setter to the AttackCooldown
	void setAtkCoolDown(int atkCoolDown)  {  AtkCoolDown=  atkCoolDown; }

	
	/// easy way to print an player
	friend std::ostream& operator<<(std::ostream& o/**[in] is the output stream*/, Player& d/**[in] is the printed player*/);
	/**
	 * \brief fight with another player while one of them is die
	 */
	void Fight(Player* player/**[in] is the other player*/);
	/**
	 * \brief This method reads a .json file and get the useful informations.
	 * \return return with a Player object
	 * \throw throw a "runtime_error" if something wrong
	 */
	static Player* parseUnit(const std::string file/**[in] is the .json file's name*/);
};
