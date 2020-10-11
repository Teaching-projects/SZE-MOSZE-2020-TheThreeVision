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
        AdventurerPlayer* Player1, * Player2;
        try {
            Player1 = AdventurerPlayer::parseUnit(argv[1]);
            Player2 = AdventurerPlayer::parseUnit(argv[2]);
        }
        catch (std::runtime_error& e) {
            cerr << e.what();
            return 2;
        }

         Player1->Fight(Player2);
       
        if (Player1->getHP() == 0) {
          
            cout << Player2->getName() << " wins." << " Remaining HP: " << Player2->getHP() << "."<<"All XP: " << Player2->getXP();
            
        }
        else if (Player2->getHP() == 0) {
            cout << Player1->getName() << " wins." << " Remaining HP: " << Player1->getHP() << "." << "All XP: " << Player1->getXP();
        }
    }

    return 0;
}
