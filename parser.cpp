#include "parser.h"

std::map<std::string, std::string> Parser::ParseJsonString(std::string StringToParse){
    std::map<std::string, std::string> Map;
    bool toDelete = true;
    int j = 0;
    while (j < StringToParse.length())
    {
        if (StringToParse[j] == '"'){
            if (toDelete)
            {
                toDelete = false;
            }else{
                toDelete = true;
            }
        }
        if (StringToParse[j] == ' ' && toDelete)
        {
            StringToParse.erase(j,1);
        }else{
            j++;
        }
    }
    std::string array[] = {StringToParse, "name", "hp", "dmg"};
    
    Map["name"] = Parser::FindData(array[0],array[1]);

    Map["hp"] = Parser::FindData(array[0],array[2]);

    Map["dmg"] = Parser::FindData(array[0],array[3]);

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
        
    }
    return Parser::ParseJsonString(DataToParse);
}

std::string Parser::FindData(const std::string& StringToParse, const std::string& StringToFind){
    std::string data = "";

    if (StringToParse.find(StringToFind) != std::string::npos)
    {
        int findWord = StringToParse.find(StringToFind) + StringToFind.length() + 2;
         if (StringToParse[findWord] == '"')
        {
            findWord++;
        }
        do
        {
            data += StringToParse[findWord];
            findWord++;
        } while (isdigit(StringToParse[findWord]) or isalpha(StringToParse[findWord]) or StringToParse[findWord] == ' ');
    }else{
        throw std::runtime_error("Bad input data.");
    }
    if (data == "")
    {
        throw std::runtime_error("Bad input data.");
    }
    
    return data;
}