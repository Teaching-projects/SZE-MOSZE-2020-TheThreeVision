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
    if (!map.isEmpty()) 
    {
        if (this->hero.h == nullptr) 
        {
            if (map.get(x, y) == Map::type::Free)
            {
                this->hero.h = new Hero(hero);
                this->hero.row = x;
                this->hero.col = y;
                hasUnits = true;
            }
            else{
                throw OccupiedException("Coordinate occupied.");
            }
        }else{ throw AlreadyHasHeroException("Game already has Hero"); }
    }else{ throw Map::WrongIndexException("Need set map to put a Hero"); }
}

void Game::putMonster(Monster monster, int x, int y){
    if (!map.isEmpty()) 
    {
        if (map.get(x, y) == Map::type::Free) {
            Mstr monsterpoint = { monster,x,y };
            monsters.push_back(monsterpoint);
            hasUnits = true;
        }
        else
            throw OccupiedException("Coordinate occupied..");
    }
    else {
        throw Map::WrongIndexException("Need set map to put a Monster");
    }
    
    
}

void Game::moveHero(const std::string& direction){
    int x = hero.row;
    int y = hero.col;
    bool goodcommand = true;
    if (direction =="east") x++;
    else if (direction =="west") x--;
    else if (direction =="north") y--;
    else if (direction =="south") y++;
    else { goodcommand = false; throw InvalidMove("Invalid move, you can only use these movement commands: [east,west,north,south]"); }
    if (goodcommand) {
        if (map.get(x, y) == Map::type::Free)
        {
            this->hero.row = x;
            this->hero.col = y;
        }
        else { throw InvalidMove("Invalid move, you can only enter a free space"); }
    }
   
}



void Game::run() {
    running = true;
    
    if (hasUnits && !monsters.empty() && hasMap) 
    {
        //hero try to clear the map
        while (hero.h->isAlive() && !monsters.empty()) {
            //move
            this->printMap();
            std::string heroMoveDirection = "";
            cin >> heroMoveDirection;
            try {
                moveHero(heroMoveDirection);

                std::list<Mstr>::iterator monster = monsters.begin();
                //hero try to clear a point of the map
                while (hero.h->isAlive() && monster != monsters.end())
                {
                    if (hero.row == monster->row && hero.col == monster->col)
                    {
                        cout << hero.h->getName() << "(" << hero.h->getLevel() << ") vs " << monster->m.getName() << endl;
                        hero.h->fightTilDeath(monster->m);
                    }
                    if (!monster->m.isAlive()) monsters.erase(monster++);
                    else monster++;

                }
            }
            catch (std::runtime_error& e) {
                cout << e.what()<<endl;
            }
        }
        if (hero.h->isAlive()) {
             cout <<endl<< hero.h->getName() << " cleared the map.\n";
             cout << "  LVL: " << hero.h->getLevel() << std::endl
                  << "   HP: "<<hero.h->getHealthPoints()<<"/"<<hero.h->getMaxHealthPoints()<<std::endl
                  << "  DMG: "<<hero.h->getDamage()<<std::endl
                  << "  ACD: "<<hero.h->getAttackCoolDown()<<std::endl
                  ;
        }
        else {
            cout << "The hero died.";
        }
       
    }
    else {
        throw NotInitializedException("Game couldn't initialized! Try again");
    }

}

void Game::printMap(){
    for (int y = 0; y < map.getHeight(); y++)
    {
        for (int x = 0; x < map.getMaxWidth(); x++)
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