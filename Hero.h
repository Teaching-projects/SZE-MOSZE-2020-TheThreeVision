#include "Monster.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <any>
/**
 * \class Hero
 *
 * \brief Hero class
 *
 * \author radvanszkyI
 *
 * \date 2020.11.06. 0:30
 *
 * \note A Hero can fight with a monster while one of them is alive.
 * The end of the fight depends on the HealthPoints, Damages and the Attackcooldowns.
 */
class Hero : public Monster
{
private:
	int XP = 0;///< the ExperiencePoints of the hero
	int maxHP; ///< the maximum of the hero's HealthPoints
	int Level = 1;
	double Experience_per_level;
	double Health_point_bonus_per_level;
	double Damage_bonus_per_level;
	double Cooldown_multiplier_per_level;
	/// a simple getter to the Experience per level
	double getExperience_per_level() { return Experience_per_level; }
	/// a simple getter to the Health point bonus per level
	double	getHealth_point_bonus_per_level() { return Health_point_bonus_per_level; }
	/// a simple getter to the Damage bonus per level
	double	getDamage_bonus_per_level() { return Damage_bonus_per_level; }
	/// a simple getter to the Cooldown multiplier per level
	double	getCooldown_multiplier_per_level() { return Cooldown_multiplier_per_level; }
	/**
	 * \brief This method damages a monster.
	 * \note this method does the increaseXP and the levelup
	 */
	void Damage(Monster* monster/**[in] the monster whitch is injured*/);
protected:

	
	/// this method increases maxHP, DMG and decreases AtkCoolDown and sets the HP to maximum
	void levelup(int levels/**[in] is the number of the level increases*/);
	/// add more XP to XP
	void increaseXP(int dmg/**[in] is the number of the added XP*/);

public:
	/**
	 * \brief fight with a monster while one of them is die
	 */
	void fightTilDeath(Monster& m/**[in] is the monster*/);
	/// Hero construct, what put the input parameters to the data members
	Hero(std::string name, int hp, int dmg, double atkCoolDown,
		int experience_per_level, int health_point_bonus_per_level, int damage_bonus_per_level, double cooldown_multiplier_per_level)
		: Monster(name, hp, dmg, atkCoolDown),
		maxHP(hp), Experience_per_level(experience_per_level),
		Health_point_bonus_per_level(health_point_bonus_per_level),
		Damage_bonus_per_level(damage_bonus_per_level),
		Cooldown_multiplier_per_level(cooldown_multiplier_per_level) {};
	/// copy construct, what make a copy from the parameter
	Hero(Hero* h) :Monster(h), maxHP(h->getMaxHealthPoints()), 
		Experience_per_level(h->getExperience_per_level()),
		Health_point_bonus_per_level(h->getHealth_point_bonus_per_level()),
		Damage_bonus_per_level(h->getDamage_bonus_per_level()),
		Cooldown_multiplier_per_level(h->getCooldown_multiplier_per_level()) {};
	/// a simple getter to the ExperiencePoints
	int getXP() { return XP; }
	/// a simple getter to the Level
	int getLevel() { return Level; }
	/// a simple getter to the MaxHealthPoints
	int getMaxHealthPoints() { return maxHP; }
	/**
	 * \brief This method use the parser class, and reads a .json file, and get the keys and the attached data and returns a new AdventurerPlayer object
	 * \return return with an Hero object
	 * \throw throw a "runtime_error" if something wrong
	 */
	static Hero parse(const std::string file/**[in] is the .json file's name*/);
};