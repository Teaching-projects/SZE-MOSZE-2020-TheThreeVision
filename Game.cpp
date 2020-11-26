#include "Game.h"


Game::Game(); // Empty Game

Game::Game(string mapfilename); // Game with the Map initialized

void setMap(Map map); // Set the map

void putHero(Hero hero, int x, int y);

void putMonster(Monster monster, int x, int y);
