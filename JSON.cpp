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
    std::map<std::string, std::variant<std::string, double, int>> Map;
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

JSON JSON::ParseJsonString(std::string StringToParse){
    std::map<std::string, std::variant<std::string, double, int>> Map;
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
    
    std::string array[5] = {StringToParse, "name", "points", "damage", "cooldown"};
    
    
    for(int i = 1; i < 5; i++)
    {
        if (array[i] == "name")
        {
            Map.insert(std::make_pair("name", FindData(array[0], array[i])));
        }else if(array[i] == "points"){
            Map.insert(std::make_pair("points", std::stoi(FindData(array[0], array[i]))));
        }else if(array[i] == "damage"){
            Map.insert(std::make_pair("damage", std::stoi(FindData(array[0], array[i]))));
        }else if(array[i] == "cooldown"){
            Map.insert(std::make_pair("cooldown", std::stod(FindData(array[0], array[i]))));
        }
    }

    std::string additionals[8] = {StringToParse, "lore", "\"race", "experience_per_level","health_point_bonus_per_level","damage_bonus_per_level","cooldown_multiplier_per_level","additional_info"};
    for (int i = 1; i < 8; i++)
    {
        if (additionals[0].find(additionals[i]) != std::string::npos)
        {
            std::string data = FindData(additionals[0], additionals[i]);
            if (data != "" && isdigit(data[0]))
            {
                Map.insert(std::make_pair(additionals[i],std::stod(data)));
            }else if(data != "" && isalpha(data[0])){
                Map.insert(std::make_pair(additionals[i],data));
            }
        }
    }
    
    JSON toReturn(Map);
    return toReturn;
}

JSON JSON::ParseJson(std::istream& JSONToParse){
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
    
    return JSON::ParseJsonString(DataToParse);
}

std::string JSON::FindData(const std::string& StringToParse, const std::string& StringToFind){
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
        } while (isdigit(StringToParse[findWord]) or isalpha(StringToParse[findWord]) or StringToParse[findWord] == ' ' or StringToParse[findWord] == '.' or StringToParse[findWord] == '_' or StringToParse[findWord] == '(' or StringToParse[findWord] == ')' or StringToParse[findWord] == ',' or StringToParse[findWord] == '-');
        if (data[data.length()-1] == ' ' or data[data.length()-1] == ',')
        {
            data.erase(data.length()-1, 1);
        }
        
    }else{
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