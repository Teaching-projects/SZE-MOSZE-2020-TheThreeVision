#pragma once
#include <string>
#include <list>
#include "Map.h"
#include "Hero.h"
#include "Monster.h"
#include "Renderer.h"
#include <filesystem>
class Renderer;
/**
 * \brief Mstr struct contain a Monster and its coordinates (col and row) 
 * 
 * \date 2020.12.10. 9:23
 *
 */
struct Mstr
{
    Monster m;///the Monster
    int col;///x coordinate
    int row;///y coordinate
};
/**
 * \brief Hr struct contain a Hero pointer and his/her coordinates (col and row)
 *
 *
 * \date 2020.12.10. 9:24
 *
 */
struct Hr
{
    Hero *h;///the Hero
    int col;///x coordinate
    int row;///y coordinate
};
/**
 * \class Game
 * 
 * \brief manage the game
 *
 * \date 2020.12.10. 13:23
 *
 */
class Game
{
private:
    Map map;
protected:
    std::list<Mstr> monsters;
    Hr hero;
    bool hasUnits; 
    bool hasMap;
    bool Running;
    std::map<std::string, std::string> Textures///<contain the wall and free and the placeholder textures
    {std::make_pair("free_texture", "svg/free.svg"),std::make_pair("wall_texture", "svg/wall.svg")};
    std::list<Renderer*> Renderers; ///<contain the added renderers

public:
    Game() : map(MarkedMap()), hero(),hasUnits(false),hasMap(false),Running(false) {};///< Game's costructor without mapfile
    Game(std::string mapfilename) : map(MarkedMap(mapfilename)), hero(), hasUnits(false), hasMap(true), Running(false) {};///< Game's costructor with mapfile

    void setMap(Map NewMap); ///<Set the map
    Map getMap()const { return map; }///<Get the map
    std::map<std::string, std::string> getTextures() const{ return Textures; }///<Get the textures
    void putHero(Hero hero, int x, int y); ///<Put hero
    Hr getHero() const { return hero; }///<Get the hero
    void moveHero(const std::string &direction); ///<Moving the hero
    void putMonster(Monster monster, int x, int y); ///<Put hero
    std::list<Mstr> getMonsters() const { return monsters; }///<Get the monsters
    void registerRenderer(Renderer* renderer) { Renderers.push_back(renderer); }///<add a new renderer
    void run(); ///<Game run (start)
    /// This is a kind of runtime_error
    class InvalidMove : public std::runtime_error
    {
    public:
        InvalidMove(const std::string& msg) : std::runtime_error(msg) {}
    };
    /// This is a kind of runtime_error
    class NotInitializedException : public std::runtime_error
    {
    public:
        NotInitializedException(const std::string& msg) : std::runtime_error(msg) {}
    };
    /// This is a kind of runtime_error
    class AlreadyHasHeroException : public std::runtime_error
    {
    public:
        AlreadyHasHeroException(const std::string& msg) : std::runtime_error(msg) {}
    };
    /// This is a kind of runtime_error
    class AlreadyHasUnitsException : public std::runtime_error
    {
    public:
        AlreadyHasUnitsException(const std::string &msg) : std::runtime_error(msg) {}
    };
    /// This is a kind of runtime_error
    class OccupiedException : public std::runtime_error
    {
    public:
        OccupiedException(const std::string& errMsg) : std::runtime_error(errMsg) {}
    };
    /// This is a kind of runtime_error
    class GameAlreadyStartedException : public std::runtime_error
    {
    public:
        GameAlreadyStartedException(const std::string& errMsg) : std::runtime_error(errMsg) {}
    };
};
/**
 * \brief manages the game, but it's already prepared
 * 
 * \note this class prepares from a file
 */
class PreparedGame : public Game{
private:
    MarkedMap map;
public:
    /// Game's costructor prepares the Game from a file
    PreparedGame(std::string filename/*[in] a file's name witch contains the game's data to prepare*/);
    ///running a game
    using Game::run;
};