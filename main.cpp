#include <iostream>
#include <fstream>
#include <vector>
#include "player.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        throw std::runtime_error("Bad input data.");
    }
    else {
    Player* Player1 = Player::parseUnit(argv[1]);
    Player* Player2 = Player::parseUnit(argv[2]);
    
    while (Player1->getHP() > 0 && Player2->getHP() > 0)
    {
        Player1->Damage(Player2);
        if (Player2->getHP() > 0) {
            Player2->Damage(Player1);
        }
    }
    if (Player1->getHP() == 0) {
            cout << Player2->getName() << " wins." << " Remaining HP: " << Player2->getHP() << ".";
        }
        else if (Player2->getHP() == 0) {
            cout << Player1->getName() << " wins." << " Remaining HP: " << Player1->getHP() << ".";;
        }
    }

    return 0;
}
