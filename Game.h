#include <string>
#include "Map.h"
#include "Hero.h"
#include "Monster.h"


class Game
{
private:

public:
    Game();
    Game::Game(std::string mapfilename);
    ~Game();

void setMap(Map map); // Set the map

void putHero(Hero hero, int x, int y);

void putMonster(Monster monster, int x, int y);
};
