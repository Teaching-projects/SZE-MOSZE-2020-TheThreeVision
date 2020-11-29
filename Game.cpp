#include "Game.h"
#include <string.h>

using namespace std;


void Game::setMap(Map NewMap){
    if (hasUnits)
    {
        map = NewMap;
        if (!hasMap) hasMap = true;
    }else{
        throw AlreadyHasUnitsException("The game already has Units, you cant add a new Map!");
    }
    
}

void Game::putHero(Hero hero, int x, int y){
    
if (this->hero.h != nullptr) throw AlreadyHasUnitsException("Game already has Hero");
{
   if (map.get(x,y)== Map::type::Free)
   {
       this->hero.h=new Hero(hero);
       this->hero.row=x;
       this->hero.col=y;       
       hasUnits=true;
   }
   
}
}

void Game::putMonster(Monster monster, int x, int y){
    
    if (map.get(x,y)== Map::type::Free){
        Mstr monsterpoint  = {monster,x,y};
        monsters.push_back(monsterpoint);
        hasUnits=true;
    }
    else 
        throw OccupiedException("Coordinate occupied");
    
    
    
}
//future possible feature updates 
/*void Game::moveHero(const std::string& direction){
    if (direction =="east") hero.row++;
    if (direction =="west") hero.row--;
    if (direction =="north") hero.col--;
    if (direction =="south") hero.col++;
}
*/


void Game::run(){
    
    if (hasUnits && !monsters.empty() && hasMap)
    {
        std::string moveHero="";
        std::list<Mstr>::iterator monster = monsters.begin();
        while (hero.h->isAlive() && !monsters.empty())
        {
            if (hero.h->isAlive())
            {
                if (hero.row==mm.row && hero.col==mm.col)
                {
                    cout<<hero.h->getName() <<"("<<hero.h->getLevel()<<endl;
                    hero.h->fightTilDeath(monster->m);
                }
                if(!monster->m.isAlive()) monsters.erase(monster);
                else monster++;
            }
            
        }
        
    }
    else throw OccupiedException("Game couldn't initialized! Try again");
    
}
