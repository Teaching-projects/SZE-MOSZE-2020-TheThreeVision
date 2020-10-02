#include <iostream>
#include <fstream>
#include <vector>
#include "player.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Bad input data." << endl;
        return 1;
    }
    else {
        Player* Player1, * Player2;
        try {
            Player1 = Player::parseUnit(argv[1]);
            Player2 = Player::parseUnit(argv[2]);
        }
        catch (std::runtime_error& e) {
            cerr << e.what();
            return 2;
        }


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
