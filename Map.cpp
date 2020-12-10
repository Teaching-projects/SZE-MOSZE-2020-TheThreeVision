#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(const std::string &Filename)
{
    std::ifstream mapFile(Filename);
    if (mapFile.good())
    {
        std::string line;
        while (getline(mapFile, line))
            map.push_back(line);
    }
    else
        throw std::runtime_error("File does not exist: " + Filename);
    mapFile.close();
}

Map::type Map::get(unsigned int x, unsigned int y) const
{
    if (y >= map.size() || x > getMaxWidth())
    {
        throw WrongIndexException("Given coordinate is out of range!");
    }
    else if (x > map[y].length()-1)
    {
        return Map::type::Wall;
    }

    if (map[y][x] != '#')
        return Map::type::Free;
    else
        return Map::type::Wall;
}
int Map::getHeight() const
{
    return map.size();
}
int Map::getWidth(int line) const
{
    return map[line].length();
}

int Map::getMaxWidth() const
{
     int max = 0;
    for (auto a : map)
    {
        if (a.length() > max)
            max = a.length();
    }
    return max;
}

MarkedMap::MarkedMap(const std::string &FileName)
{
    std::ifstream MapFile(FileName);
    if (MapFile.good())
    {
        std::string Line;
        while (getline(MapFile, Line))
        {
            map.push_back(Line);
        }
    }
    else
        throw std::runtime_error("Game file does not exist:" + FileName);
    MapFile.close();
}
std::vector<std::pair<int, int>> MarkedMap::getMonsterPosition(char c) const
{
    std::vector<std::pair<int, int>> MonsterPosition;
    for (int i = 0; i < (int)map.size(); i++)
    {
        for (int j = 0; j < (int)map[i].length(); j++)
        {
            if (map[i][j] == c)
            {
                MonsterPosition.push_back(std::make_pair(j, i));
            }
        }
    }
    return MonsterPosition;
}
std::pair<int, int> MarkedMap::getHeroPosition() const
{
    std::pair<int, int> HeroPosition;
    for (int i = 0; i < (int)map.size(); i++)
    {
        for (int j = 0; j < (int)map[i].length(); j++)
        {
            if (map[i][j] == 'H')
            {
                HeroPosition = std::make_pair(j, i);
            }
        }
    }
    return HeroPosition;
}