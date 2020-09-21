#include <iostream>
#include "player.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc >= 7) {
        Player Player1(argv[1],atoi(argv[2]),atoi(argv[3]));
        Player Player2(argv[4],atoi(argv[5]),atoi(argv[6]));
        cout<<Player1 << endl << Player2 << endl;
        while (Player1.getHP() > 0 && Player2.getHP() > 0)
        {
            Player1.Damage(&Player2);
            Player1.print(&Player2);
            if (Player2.getHP() > 0) {
                Player2.Damage(&Player1);
                Player2.print(&Player1);
            }
        }
        if (Player1.getHP() == 0) {
            cout << Player2.getName() << " wins.";
        }else if(Player2.getHP() == 0){
            cout << Player1.getName() << " wins.";
        }
    } else{
        cout << "Bad input data" << endl;
    }
	cin.get();
}
