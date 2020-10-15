#include "player.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

void Player::Damage(Player* player)const
{

	if ((player->HP - DMG) >= 0)
	{
		player->HP -= DMG;

	}
	else { player->HP = 0; }

}

void Player::Fight(Player* otherplayer)
{
	 while (this->getHP() > 0 && otherplayer->getHP() > 0)
	 {
		 this->Damage(otherplayer);
		 if (otherplayer->getHP() > 0) {
			 otherplayer->Damage(this);
		 }
	 }
}

Player* Player::parseUnit(const std::string filename) {
	std::ifstream file(filename);
	std::vector<std::string> data;
	std::string newLine, name;
	int hp, dmg;
	if (file.good()) {
		while (getline(file, newLine)) {
			data.push_back(newLine);
		}
		data[0].erase();
		data[data.size() - 1].erase();
		for (int i = 0; i < data.size(); i++) {
			int c;
			c = data[i].find('"');
			if (data[i][c + 1] == 'n') {
				c = data[i].find(':');
				std::string temp;
				temp = data[i].substr(c + 3, data[i].length());
				name = temp.substr(0, temp.length() - 2);
			}
			else if (data[i][c + 1] == 'h') {
				c = data[i].find(':');
				std::string temp;
				temp = data[i].substr(c + 2, data[i].length());
				temp = temp.substr(0, temp.length() - 1);
				hp = atoi(temp.c_str());
			}
			else if (data[i][c + 1] == 'd') {
				c = data[i].find(':');
				std::string temp;
				temp = data[i].substr(c + 2, data[i].length());
				temp = temp.substr(0, temp.length());
				dmg = atoi(temp.c_str());
			}
		}
	}
	else {
		throw std::runtime_error("There is a problem with the file: " + filename);
	}
	return new Player(name, hp, dmg);
}



std::ostream& operator<<(std::ostream& o, Player& d)
{
	return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}

void AdventurerPlayer::levelup(int levels)
{
	for (int i = 0; i < levels; i++)
	{
		maxHP = (int)round((double)maxHP * 1.1);
		setDMG((int)round((double)getDMG() * 1.1));
		setHP(maxHP);
	}

}

void AdventurerPlayer::Fight(AdventurerPlayer* otherplayer)
{
	while (this->getHP() > 0 && otherplayer->getHP() > 0)
	{
		int othHP = otherplayer->getHP(), thiHP = this->getHP();
		int othXP = otherplayer->getXP(), thiXP = this->getXP();

		this->Damage(otherplayer);
		this->increaseXP(othHP - otherplayer->getHP());//this xp-je nõ annyival, amenyi sebzést a MÁSIK szenvedett
		this->levelup(this->getXP() / 100 - thiXP / 100);


		if (otherplayer->getHP() > 0) {
			otherplayer->Damage(this);
			otherplayer->increaseXP(thiHP - this->getHP());//otherplayer xp-je nõ annyival, amenyi sebzést a this szenvedett
			otherplayer->levelup(otherplayer->getXP() / 100 - othXP / 100);
		}
	}

}



void AdventurerPlayer::increaseXP(int dmg)
{
	XP += dmg;
}

AdventurerPlayer* AdventurerPlayer::parseUnit(const std::string filename)
{
	std::ifstream file(filename);
	std::vector<std::string> data;
	std::string newLine, name;
	int hp, dmg;
	if (file.good()) {
		while (getline(file, newLine)) {
			data.push_back(newLine);
		}
		data[0].erase();
		data[data.size() - 1].erase();
		for (int i = 0; i < data.size(); i++) {
			int c;
			c = data[i].find('"');
			if (data[i][c + 1] == 'n') {
				c = data[i].find(':');
				std::string temp;
				temp = data[i].substr(c + 3, data[i].length());
				name = temp.substr(0, temp.length() - 2);
			}
			else if (data[i][c + 1] == 'h') {
				c = data[i].find(':');
				std::string temp;
				temp = data[i].substr(c + 2, data[i].length());
				temp = temp.substr(0, temp.length() - 1);
				hp = atoi(temp.c_str());
			}
			else if (data[i][c + 1] == 'd') {
				c = data[i].find(':');
				std::string temp;
				temp = data[i].substr(c + 2, data[i].length());
				temp = temp.substr(0, temp.length());
				dmg = atoi(temp.c_str());
			}
		}
	}
	else {
		throw std::runtime_error("There is a problem with the file: " + filename);
	}
	return new AdventurerPlayer(name, hp, dmg);

}
