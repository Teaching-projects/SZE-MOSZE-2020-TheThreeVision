#include <string>
#include <list>
#include "Map.h"
#include "Hero.h"
#include "Monster.h"

///TO DO beolvasáskor ellenőrizni hogy minden sor egyforma e

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
    bool hasUnits; 
    bool hasMap;

public:
    Game() : map(Map()), hasUnits(false), hasMap(false), hero(){};
    Game(std::string mapfilename) : map(Map(mapfilename)), hasUnits(false), hasMap(true){};
    ~Game();

    void run(); ///Game run (start)
    void setMap(Map NewMap); /// Set the map
    void printMap(); ///Print the map
    void putHero(Hero hero, int x, int y); /// Put hero
    void moveHero(const std::string &direction); ///Moving the hero
    void putMonster(Monster monster, int x, int y); ///Put hero

    class NotInitializedException : public std::runtime_error
    {
    public:
        NotInitializedException(const std::string& msg) : std::runtime_error(msg) {}
    };
    class AlreadyHasHeroException : public std::runtime_error
    {
    public:
        AlreadyHasHeroException(const std::string& msg) : std::runtime_error(msg) {}
    };
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