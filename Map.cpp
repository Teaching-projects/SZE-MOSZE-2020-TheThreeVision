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

Map::type Map::get( int x,  int y) const{
    if (y >= map.size() || x >= map[y].length()) throw WrongIndexException("Given coordinate is out of range!");
    if(map[y][x] == ' ') return Map::type::Free;
    else return Map::type::Wall;
    
}