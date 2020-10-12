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
    std::cout << "\t" << "  \t" << this->getHP() << " " << otherplayer->getHP() << "\n";
    this->Damage(otherplayer);
    double a = this->getAtkCoolDown(); double b = otherplayer->getAtkCoolDown();
    double sa = 0, sb = 0;
   
    while (this->getHP() > 0 && otherplayer->getHP() > 0)
    {
        if (sa + a < b + sb) {
            
            sa += a; 
            this->Damage(otherplayer);
            std::cout << a << "\t" << sa << "  \t"
            <<this->getHP()<<" "<< otherplayer->getHP() <<"\t";
            
        }
        else {
            if (sa + a > b + sb) {
                 sb += b;
                 otherplayer->Damage(this);
                 std::cout << b << "\t  " << sb << "\t" 
                 << this->getHP() << " " << otherplayer->getHP() << "\t";
            }
            else {//ha egyszerre ütnének akkor az üt amelyik a Fight-ot idította
                
                sa += a;
                this->Damage(otherplayer);
                std::cout << a << "\t" << sa << "  \t" 
                << this->getHP() << " " << otherplayer->getHP() << "\t";
            }
        }
        std::cout /*<< sa << " " << sb */<< std::endl;

    }
   /* while (this->getHP() > 0 && otherplayer->getHP() > 0)
    {
        this->Damage(otherplayer);
        if (otherplayer->getHP() > 0) {
            otherplayer->Damage(this);
        }
    }*/
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
    return new Player(name, hp, dmg,1);
}

std::ostream& operator<<(std::ostream& o, Player& d)
{
    return o << d.getName() << ": HP: " << d.getHP() << ", DMG: " << d.getDMG();
}

