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
};

struct Hr
{
    Hero *h;
    int col;
    int row;
    ~Hr() { delete h; }
};

class Game
{
protected:
    Map map;
    std::list<Mstr> monsters;
    Hr hero;
    bool hasUnits; 
    bool hasMap;
    bool running;
public:
    void setMap(Map NewMap); /// Set the map
    void printMap(); ///Print the map
    void putHero(Hero hero, int x, int y); /// Put hero
    void moveHero(const std::string &direction); ///Moving the hero
    void putMonster(Monster monster, int x, int y); ///Put hero
    Game() : map(MarkedMap()), hasUnits(false), hasMap(false), running(false), hero() {};
    Game(std::string mapfilename) : map(MarkedMap(mapfilename)), hasUnits(false), hasMap(true), running(false), hero() {};
    void run(); ///Game run (start)
    class InvalidMove : public std::runtime_error
    {
    public:
        InvalidMove(const std::string& msg) : std::runtime_error(msg) {}
    };
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
        OccupiedException(const std::string& errMsg) : std::runtime_error(errMsg) {}
    };
    class GameAlreadyStartedException : public std::runtime_error
    {
    public:
        GameAlreadyStartedException(const std::string& errMsg) : std::runtime_error(errMsg) {}
    };
};

class PreparedGame : public Game{
private:
    MarkedMap map;
public:
    PreparedGame(std::string filename);
    using Game::run;
};