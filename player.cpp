#include "player.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


void Player::Damage (Player* player)const
{

    if ((player->HP - DMG) >= 0)
    {
        player->HP -= DMG;

    }
    else { player->HP = 0; }

}

void Player::Fight(Player* otherplayer)
{
    
    this->Damage(otherplayer);
    double atkcdownThis = this->getAtkCoolDown(); double atkcdownOther = otherplayer->getAtkCoolDown();
    double cooldownCounterThis = 0, cooldownCounterOther = 0;
   
    while (this->getHP() > 0 && otherplayer->getHP() > 0)
    {
        if (cooldownCounterThis + atkcdownThis < atkcdownOther + cooldownCounterOther) {
            
            cooldownCounterThis += atkcdownThis; 
            this->Damage(otherplayer);
           
            
        }
        else {
            if (cooldownCounterThis + atkcdownThis > atkcdownOther + cooldownCounterOther) {
                 cooldownCounterOther += atkcdownOther;
                 otherplayer->Damage(this);
            }
            else {//ha egyszerre ütnének akkor az üt amelyik a Fight-ot idította
                
                cooldownCounterThis += atkcdownThis;
                this->Damage(otherplayer);
            }
        }

    }
}

Player* Player::parseUnit(const std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> data;
    std::string newLine, name;
    int hp, dmg;
    double atkcd;
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
            else if (data[i][c + 1] == 'a') {
                c = data[i].find(':');
                std::string temp;
                temp = data[i].substr(c + 2, data[i].length());
                temp = temp.substr(0, temp.length());
                atkcd = atof(temp.c_str());
            }
        }
    }
    else {
        throw std::runtime_error("There is a problem with the file: " + filename);
    }
    return new Player(name, hp, dmg, atkcd);
}

std::ostream& operator<<(std::ostream& o, Player& d)
{
    return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}

