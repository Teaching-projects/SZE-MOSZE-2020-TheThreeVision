#include "JSON.h"

int JSON::count(const std::string& toFind){
    int toReturn = Data.count(toFind);
    return toReturn;
}

JSON JSON::parseFromFile(const std::string& filePath){
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
    JSON file = JSON::parseScenario(DataToParse);
    return file;
}

JSON JSON::parseScenario(std::string& JSONstring){
    std::map<std::string, std::any> Map;
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

    JSON file(Map);
    return file;
}

// old

std::map<std::string, std::any> JSON::ParseJsonString(std::string StringToParse){
    std::map<std::string, std::any> Map;
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
    
    std::string array[5];
    if (StringToParse.find("base_health_points") != std::string::npos)
    {
        array[0] = StringToParse;
        array[1] = "name";
        array[2] = "base_health_points";
        array[3] = "base_damage";
        array[4] = "base_attack_cooldown";
    }else{
        array[0] = StringToParse;
        array[1] = "name";
        array[2] = "health_points";
        array[3] = "damage";
        array[4] = "attack_cooldown";
    }
    
    for (int i = 1; i < 5; i++)
    {
        Map[array[i]] = JSON::FindData(array[0],array[i]);
    }
    
    return Map;
}

std::map<std::string, std::any> JSON::ParseJson(std::istream& JSONToParse){
    std::string DataToParse, line;
    while (std::getline(JSONToParse, line))
    {
        DataToParse += line;
    }
    
    return JSON::ParseJsonString(DataToParse);
}

JSON JSON::ParseJsonFilename(std::string FilenameToParse){
    FilenameToParse = "Units/" + FilenameToParse;
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
    std::map<std::string, std::any> Map = JSON::ParseJsonString(DataToParse);
    JSON toReturn(Map);
    return toReturn;
}

std::any JSON::FindData(const std::string& StringToParse, const std::string& StringToFind){
    std::string data = "";
    
    if (StringToParse.find(StringToFind) != std::string::npos)
    {
        int findWord = StringToParse.find(StringToFind) + StringToFind.length() + 2;
         if (StringToParse[findWord] == '"' or StringToParse[findWord] == ' ')
        {
            findWord++;
        }
        do
        {
            data += StringToParse[findWord];
            findWord++;
        } while (isdigit(StringToParse[findWord]) or isalpha(StringToParse[findWord]) or StringToParse[findWord] == ' ' or StringToParse[findWord] == '.' or StringToParse[findWord] == '_');
        if (data[data.length()-1] == ' ')
        {
            data.erase(data.length()-1, 1);
        }
        
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
    return std::any_cast<std::any>(data);
}