#include "Game.h"
#include <string.h>

using namespace std;


void Game::setMap(Map NewMap){
    if (hasUnits)
    {
        if (!running){
            map = NewMap;
            if (!hasMap) hasMap = true;
        }else 
            throw GameAlreadyStartedException("Game already started, you cant set a new Map!");
       
    }else {
        throw AlreadyHasUnitsException("The game already has Units, you cant set a new Map!");
    }
    
}

void Game::putHero(Hero hero, int x, int y) {
    if (map.isEmpty()) 
    {
        if (this->hero.h != nullptr) 
        {
            if (map.get(x, y) == Map::type::Free)
            {
                this->hero.h = new Hero(hero);
                this->hero.row = x;
                this->hero.col = y;
                hasUnits = true;
            }
            else
                throw OccupiedException("Coordinate occupied");
        }else{ throw AlreadyHasHeroException("Game already has Hero"); }
    }else{ throw Map::WrongIndexException("Need set map to put a Hero"); }
}

void Game::putMonster(Monster monster, int x, int y){
    if (map.isEmpty()) 
    {
        if (map.get(x, y) == Map::type::Free) {
            Mstr monsterpoint = { monster,x,y };
            monsters.push_back(monsterpoint);
            hasUnits = true;
        }
        else
            throw OccupiedException("Coordinate occupied");
    }
    else {
        throw Map::WrongIndexException("Need set map to put a Hero");
    }
    
    
}

void Game::moveHero(const std::string& direction){
    if (direction =="east") hero.row++;
    if (direction =="west") hero.row--;
    if (direction =="north") hero.col--;
    if (direction =="south") hero.col++;
}



void Game::run() {
    running = true;
    if (hasUnits && !monsters.empty() && hasMap) 
    {
        std::string moveHero = "";
        std::list<Mstr>::iterator monster = monsters.begin();
        while (hero.h->isAlive() && !monsters.empty())
        {

            if (hero.row == mm.row && hero.col == mm.col)
            {
                cout << hero.h->getName() << "(" << hero.h->getLevel() << endl;
                hero.h->fightTilDeath(monster->m);
            }
            if (!monster->m.isAlive()) monsters.erase(monster);
            //léptet
            else monster++;

        }
        //ha a hero nyert
        if (hero.h->isAlive()) {
            cout << hero.h->getName() << "cleared the map.";
        }
        else {//ha meghalt

        }
        //? minden lépés után kiírodik a pálya output ultra hosszu lesz azt is ellenőrízni kell vagy az out tesztre vami egyszerü mintát kéne csinálni pl másik scanario v nem tom 
        //késöb valszeg ezt orvsolja a marked map (belép a scanario fájlok helyet)

    }
    else {
        throw NotInitializedException("Game couldn't initialized! Try again");
    }

}

void Game::printMap(){
    for (int y = 0; y < map.getHeight(); y++)
    {
        for (int x = 0; x < map.getWidth(y); x++)
        {
            if (map.get(x,y) == map.type::Wall) {
                std::cout << "██";
            }else if(hero.row == x && hero.col == y){
                std::cout << "┣┫";
            }else{
                int count = 0;
                for (auto a : monsters)
                {
                    if ((a.row == x && a.col == y) && a.m.isAlive()) count++;
                }
                if (count == 1) std::cout << "M░";
                else if (count > 1) std::cout << "MM";
                else std::cout << "░░";
            }
        }
        std::cout << std::endl;
    }
}