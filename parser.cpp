#include "parser.h"

std::map<std::string, std::string> Parser::ParseJson(std::string DataToParse){
    std::map<std::string, std::string> Map;
    if (DataToParse.find('{') == std::string::npos)
    {
        std::ifstream ToParse(DataToParse);
        if (ToParse.good())
        {
            DataToParse = "";
            std::string line;
            while (std::getline(ToParse, line))
            {
                DataToParse += line;
            }
        }else{
            throw std::runtime_error("Bad input data.");
        }
    }

    for (int i = 0; i < DataToParse.length(); i++)
    {
        if (DataToParse[i] == ' ')
        {
            DataToParse.erase(i,1);
        }
    }
    int findWord = DataToParse.find("name") + 8;
    int endOfWord = 0, i = findWord;
    while (endOfWord == 0)
    {
        if (DataToParse[i] == '"')
        {
            endOfWord = i;
        }
        i++;
    }
    Map["name"] = DataToParse.substr(findWord-1,endOfWord-findWord+1);
    findWord = DataToParse.find("hp") + 4;
    endOfWord = 0;
    i=findWord;
    while (endOfWord == 0)
    {
        if (!isdigit(DataToParse[i]))
        {
            endOfWord = i;
        }
        i++;
    }
    Map["hp"] = DataToParse.substr(findWord,endOfWord-findWord);
    
    findWord = DataToParse.find("dmg") + 5;
    endOfWord = 0;
    i=findWord;
    while (endOfWord == 0)
    {
        if (!isdigit(DataToParse[i]))
        {
            endOfWord = i;
        }
        i++;
    }
    Map["dmg"] = DataToParse.substr(findWord,endOfWord-findWord);
    
    return Map;
}

std::map<std::string, std::string> Parser::ParseJson(std::istream& JSONToParse){
    std::string DataToParse, line;
    while (std::getline(JSONToParse, line))
    {
        DataToParse += line;
    }
    
    return Parser::ParseJson(DataToParse);
}