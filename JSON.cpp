#include "JSON.h"

int JSON::count(const std::string& toFind){
    Data.count(toFind);
}

JSON JSON::parseFromFile(std::string& filePath){
    std::ifstream JSONfile(filePath);

    if (JSONfile.fail())
    {
        throw ParseException("Bad input data.");
    }

    std::string DataToParse, line;
    while (std::getline(JSONfile, line))
    {
        DataToParse += line;
    }
    
    return parseScenario(DataToParse);
}

std::map<std::string, std::string> JSON::parseScenario(std::string& JSONstring){
    std::map<std::string, std::string> Map;
    bool toDelete = true;
    int j = 0;
    while (j < JSONstring.length())
    {
        if (JSONstring[j] == '"'){
            if (toDelete)
            {
                toDelete = false;
            }else{
                toDelete = true;
            }
        }
        if (JSONstring[j] == ' ' && toDelete)
        {
            JSONstring.erase(j,1);
        }else{
            j++;
        }
    }
    std::string array[] = {JSONstring, "hero", "monsters"};

    for (int i = 1; i < 3; i++)
    {
        Map[array[i]] = JSON::FindData(array[0],array[i]);
    }

    return Map;
}

// old

std::map<std::string, std::string> JSON::ParseJsonString(std::string StringToParse){
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
    std::string array[] = {StringToParse, "name", "hp", "dmg", "atkcd"};

    for (int i = 1; i < 5; i++)
    {
        Map[array[i]] = JSON::FindData(array[0],array[i]);
    }

    return Map;
}

std::map<std::string, std::string> JSON::ParseJson(std::istream& JSONToParse){
    std::string DataToParse, line;
    while (std::getline(JSONToParse, line))
    {
        DataToParse += line;
    }
    
    return JSON::ParseJsonString(DataToParse);
}

std::map<std::string, std::string> JSON::ParseJsonFilename(std::string FilenameToParse){
    std::ifstream ToParse(FilenameToParse);
    std::string DataToParse = "";
    if (ToParse.good())
    {
        std::string line;
        while (std::getline(ToParse, line))
        {
            DataToParse += line;
        }
    }
    return JSON::ParseJsonString(DataToParse);
}

std::string JSON::FindData(const std::string& StringToParse, const std::string& StringToFind){
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
        } while (isdigit(StringToParse[findWord]) or isalpha(StringToParse[findWord]) or StringToParse[findWord] == ' ' or StringToParse[findWord] == '.');
    }else{
        throw std::runtime_error("Bad input data.");
    }
    if (data == "")
    {
        throw std::runtime_error("Bad input data.");
    }
    if (StringToFind == "hp" or StringToFind == "dmg")
    {
        for (int i = 0; i < data.length(); i++)
        {
            if (!isdigit(data[i]))
            {
                throw std::runtime_error("Bad input data.");
            }       
         }
    }
    return data;
}