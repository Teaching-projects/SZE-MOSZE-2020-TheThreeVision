#include "Game.h"
#include <string.h>

using namespace std;

void Game::setMap(Map NewMap)
{
    if (!hasUnits)
    {
        if (!Running)
        {
            map = NewMap;
            if (!hasMap)
                hasMap = true;
        }
        else
            throw GameAlreadyStartedException("Game already started, you cant set a new Map!");
    }
    else
    {
        throw AlreadyHasUnitsException("The game already has Units, you cant set a new Map!");
    }
}

void Game::putHero(Hero hero, int x, int y)
{
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
            else
            {
                throw OccupiedException("Coordinate occupied.");
            }
        }
        else
        {
            throw AlreadyHasHeroException("Game already has Hero");
        }
    }
    else
    {
        throw Map::WrongIndexException("Need set map to put a Hero");
    }
}

void Game::putMonster(Monster monster, int x, int y)
{
    if (!map.isEmpty())
    {
        if (map.get(x, y) == Map::type::Free)
        {   
            Mstr monsterpoint = {monster, y, x};
            monsters.push_back(monsterpoint);
            hasUnits = true;
        }
        else
            throw OccupiedException("Coordinate occupied..");
    }
    else
    {
        throw Map::WrongIndexException("Need set map to put a Monster");
    }
}

void Game::moveHero(const std::string &direction)
{
    int x = hero.row;
    int y = hero.col;
    bool goodcommand = true;
    if (direction == "east")
        x++;
    else if (direction == "west")
        x--;
    else if (direction == "north")
        y--;
    else if (direction == "south")
        y++;
    else
    {
        goodcommand = false;
        throw InvalidMove("Invalid move, you can only use these movement commands: [east,west,north,south]");
    }
    if (goodcommand)
    {
        if (map.get(x, y) == Map::type::Free)
        {
            this->hero.row = x;
            this->hero.col = y;
        }
        else
        {
            throw InvalidMove("Invalid move, you can only enter a free space");
        }
    }
}

void Game::run()
{
    Running = true;

    if (hasUnits && !monsters.empty() && hasMap)
    {
        //hero try to clear the map
        while (hero.h->isAlive() && !monsters.empty())
        {
            std::string heroMoveDirection = "";
            std::list<Mstr>::iterator monster = monsters.begin();
            bool findMonsterOnHero = false;

            while (monster != monsters.end() && !findMonsterOnHero)
            {
                if (hero.row == monster->row && hero.col == monster->col)
                {
                    findMonsterOnHero = true;
                }
                monster++;
            }
            try
            {
             if (!findMonsterOnHero)
                {
                    for (auto&& r : Renderers) { r->render(*this); }
                    heroMoveDirection = "";
                    std::getline(cin, heroMoveDirection);
                    moveHero(heroMoveDirection);
                }
                else
                {
                 for (auto&& r : Renderers) { r->render(*this); }
                }

                monster = monsters.begin();
                //hero try to clear a point of the map
                while (hero.h->isAlive() && monster != monsters.end())
                {
                    if (hero.row == monster->row && hero.col == monster->col)
                    {
                        cout << hero.h->getName() << "(" << hero.h->getLevel() << ") vs " << monster->m.getName() << endl;
                        hero.h->fightTilDeath(monster->m);
                    }
                    if (!monster->m.isAlive())
                        monsters.erase(monster++);
                    else
                        monster++;
                }   
            }
            catch (std::runtime_error &e)
            {
                cout << e.what() << endl;
            }
        }
        for (auto&& r : Renderers) { r->render(*this); }
        if (hero.h->isAlive())
        {
            cout << endl
                 << hero.h->getName() << " cleared the map.\n";
            cout << "  LVL: " << hero.h->getLevel() << std::endl
                 << "   HP: " << hero.h->getHealthPoints() << "/" << hero.h->getMaxHealthPoints() << std::endl
                 << "  DMG: " << hero.h->getDamage() << std::endl
                 << "  ACD: " << hero.h->getAttackCoolDown() << std::endl;
        }
        else
        {
            cout << "The hero died.";
        }
    }
    else
    {
        throw NotInitializedException("Game couldn't initialized! Try again");
    }
}



PreparedGame::PreparedGame(std::string filename)
{
    hasUnits = false;
    hasMap = false;
    Running = false;
    JSON Units = JSON::parseFromFile(filename);

    Textures["free_texture"]= Units.get<std::string>("free_texture");
    Textures["wall_texture"] = Units.get<std::string>("wall_texture");
    

    std::string toOpen = "Units/" + Units.get<std::string>("map");
    MarkedMap map(toOpen);
    setMap(map);
    std::pair<int, int> heroPos = map.getHeroPosition();
    Hero h = Hero::parse(Units.get<std::string>("hero"));
    putHero(h, heroPos.first, heroPos.second);

    for (int i = 1; i <= 3; i++)
    {
        std::string parseHelp = "monster-";
        if (i == 1)
        {
            parseHelp += '1';
        }else if(i ==2){
            parseHelp += '2';
        }else if(i == 3){
            parseHelp += '3';
        }
        std::vector<std::pair<int, int>> monsterPos = map.getMonsterPosition(parseHelp[parseHelp.length()-1]);

        for (unsigned int j = 0; j < monsterPos.size(); j++)
        {
            Monster m = Monster::parse(Units.get<std::string>(parseHelp));
            putMonster(m, monsterPos[j].first, monsterPos[j].second);
        }
    }
}