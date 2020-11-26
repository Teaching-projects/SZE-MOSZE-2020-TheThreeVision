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

void Game::putHero(Hero hero, int x, int y){}

void Game::putMonster(Monster monster, int x, int y){}
