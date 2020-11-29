#include <string>
#include <list>
#include "Map.h"
#include "Hero.h"
#include "Monster.h"

struct Mstr
{
    Monster m;
    int col;
    int row;
} mm;

struct Hr
{
    Hero *h;
    int col;
    int row;
};

class Game
{
private:
    Map map;
    std::list<Mstr> monsters;
    Hr hero;
    bool hasUnits; // @Tomi ez legyen majd true-ra állítva a putokban!!!
    bool hasMap;

public:
    Game() : map(Map()), hasUnits(false), hasMap(false), hero(){};
    Game(std::string mapfilename) : map(Map(mapfilename)), hasUnits(false), hasMap(true){};
    ~Game();

    void run();
    void setMap(Map NewMap); // Set the map

    void putHero(Hero hero, int x, int y);
    void moveHero(const std::string &direction);
    void putMonster(Monster monster, int x, int y);

    class AlreadyHasUnitsException : public std::runtime_error
    {
    public:
        AlreadyHasUnitsException(const std::string &msg) : std::runtime_error(msg) {}
    };

    class OccupiedException : public std::runtime_error
    {
    public:
        OccupiedException(const std::string &errMsg) : std::runtime_error(errMsg) {}
    };
};