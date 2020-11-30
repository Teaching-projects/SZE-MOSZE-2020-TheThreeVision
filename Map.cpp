#include "Map.h"
#include <fstream>

Map::Map(const std::string& Filename){
    std::ifstream mapFile(Filename);
    if(mapFile.good()) 
    {
        std::string line;
        while (getline(mapFile, line))
            map.push_back(line);
    }
    else throw std::runtime_error("File does not exist: " + Filename);
    mapFile.close();
}

Map::type Map::get( unsigned int x,  unsigned int y) const{
    if (y >= map.size() || (x >= map[y].length() && map[y].length() > getMaxWidth())){
    throw WrongIndexException("Given coordinate is out of range!");
    }
    if(map[y][x] == ' ') return Map::type::Free;
    else return Map::type::Wall;
    
}
int Map::getHeight() const{
    return map.size();
    
}
int Map::getWidth(int line) const {
    return map[line].length();
}

int Map::getMaxWidth() const{
    int max = 0;
    for (auto a : map)
    {
        if (a.length() > max) max = a.length();
    }
    return max;
}