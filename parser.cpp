#include "parser.h"

std::map<std::string, std::string> Parser::ParseJsonString(std::string StringToParse){
    std::map<std::string, std::string> Map;
    
    for (int i = 0; i < StringToParse.length(); i++)
    {
        if (StringToParse[i] == ' ')
        {
            StringToParse.erase(i,1);
        }
    }
    int findWord = StringToParse.find("name") + 8;
    int endOfWord = 0, i = findWord;
    while (endOfWord == 0)
    {
        if (StringToParse[i] == '"')
        {
            endOfWord = i;
        }
        i++;
    }
    Map["name"] = StringToParse.substr(findWord-1,endOfWord-findWord+1);

    findWord = StringToParse.find("hp") + 4;
    endOfWord = 0;
    i=findWord;
    while (endOfWord == 0)
    {
        if (!isdigit(StringToParse[i]))
        {
            endOfWord = i;
        }
        i++;
    }
    Map["hp"] = StringToParse.substr(findWord,endOfWord-findWord);

    findWord = StringToParse.find("dmg") + 5;
    endOfWord = 0;
    i=findWord;
    while (endOfWord == 0)
    {
        if (!isdigit(StringToParse[i]))
        {
            endOfWord = i;
        }
        i++;
    }
    Map["dmg"] = StringToParse.substr(findWord,endOfWord-findWord);
    //to attackspeed branch
    findWord = StringToParse.find("acd") + 5;
    endOfWord = 0;
    i = findWord;
    while (endOfWord == 0)
    {
        if (!isdigit(StringToParse[i]))
        {
            endOfWord = i;
        }
        i++;
    }
    Map["acd"] = StringToParse.substr(findWord,endOfWord-findWord);

    return Map;
}

std::map<std::string, std::string> Parser::ParseJson(std::istream& JSONToParse){
    std::string DataToParse, line;
    while (std::getline(JSONToParse, line))
    {
        DataToParse += line;
    }
    
    return Parser::ParseJsonString(DataToParse);
}

std::map<std::string, std::string> Parser::ParseJsonFilename(std::string FilenameToParse){
    std::ifstream ToParse(FilenameToParse);
    std::string DataToParse = "";
    if (ToParse.good())
    {
        std::string line;
        while (std::getline(ToParse, line))
        {
            DataToParse += line;
        }
    }else{
        throw std::runtime_error("Bad input data.");
    }
    return Parser::ParseJsonString(DataToParse);
}