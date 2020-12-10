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
    unsigned int j = 0;
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
    
    std::string array[] = {JSONstring, "map", "hero", "monster-1", "monster-2", "monster-3", "free_texture", "wall_texture"};

    for (int i = 1; i < 8; i++)
    {
        Map[array[i]] = JSON::FindData(array[0],array[i]);
    }

    JSON file(Map);
    return file;
}

std::map<std::string, std::variant<std::string, double, int>> JSON::ParseJsonString(std::string StringToParse){
    std::map<std::string, std::variant<std::string, double, int>> Map;
    bool toDelete = true;
    unsigned int j = 0;
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


    std::string array[6] = {StringToParse, "name", "base_health_points", "base_damage", "base_attack_cooldown","texture"};

    if (StringToParse.find("base_health_points") == std::string::npos)
    {
        array[2] = "health_points";
        array[3] = "damage";
        array[4] = "attack_cooldown";

        for(int i = 1; i < 6; i++)
        {
            if (array[i] == "name")
            {
                Map.insert(std::make_pair("name", FindData(array[0], array[i])));
            }else if(array[i] == "health_points"){
                Map.insert(std::make_pair("points", std::stoi(FindData(array[0], array[i]))));
            }else if(array[i] == "damage"){
                Map.insert(std::make_pair("damage", std::stoi(FindData(array[0], array[i]))));
            }else if(array[i] == "attack_cooldown"){
                Map.insert(std::make_pair("cooldown", std::stod(FindData(array[0], array[i]))));
            }else if(array[i] == "texture"){
                Map.insert(std::make_pair("texture", FindData(array[0], "texture")));
            }
        }
    }else{
        for(int i = 1; i < 6; i++)
        {
            if (array[i] == "name")
            {
                Map.insert(std::make_pair("name", FindData(array[0], array[i])));
            }else if(array[i] == "base_health_points"){
                Map.insert(std::make_pair("points", std::stoi(FindData(array[0], array[i]))));
            }else if(array[i] == "base_damage"){
                Map.insert(std::make_pair("damage", std::stoi(FindData(array[0], array[i]))));
            }else if(array[i] == "base_attack_cooldown"){
                Map.insert(std::make_pair("cooldown", std::stod(FindData(array[0], array[i]))));
            }else if(array[i] == "texture"){
                    Map.insert(std::make_pair("texture", FindData(array[0], "texture")));
                }
        }
        Map.insert(std::make_pair("light_radius", std::stod(FindData(array[0],"light_radius"))));
        if (array[0].find("light_radius_bonus_per_level") == std::string::npos)
        {
            Map.insert(std::make_pair("light_radius_bonus_per_level", (double)1));
        }else Map.insert(std::make_pair("light_radius_bonus_per_level", std::stod(FindData(array[0],"light_radius_bonus_per_level"))));
        
    }
    
    std::string additionals[12] = {StringToParse, "lore", "\"race\"", "experience_per_level","health_point_bonus_per_level",
        "damage_bonus_per_level","cooldown_multiplier_per_level","additional_info", "defense_bonus_per_level", "defense",
         "\"magical-damage\"", "magical-damage_bonus_per_level"};
    for (int i = 1; i < 12; i++)
    {
        if (additionals[0].find(additionals[i]) != std::string::npos)
        {
            std::string data = FindData(additionals[0], additionals[i]);
            if((data != "" && isdigit(data[0])) && (additionals[i] == "magical-damage_bonus_per_level" or additionals[i] == "damage_bonus_per_level")){
                Map.insert(std::make_pair(additionals[i],std::stoi(data)));
            }else if (data != "" && isdigit(data[0]))
            {
                Map.insert(std::make_pair(additionals[i],std::stod(data)));
            }else if(data != "" && isalpha(data[0])){
                Map.insert(std::make_pair(additionals[i],data));
            }
        }else if(i == 10 && additionals[0].find(additionals[i]) == std::string::npos)
        {
            Map.insert(std::make_pair(additionals[i],0));
        }
        
    }
    
    return Map;
}

std::map<std::string, std::variant<std::string, double, int>> JSON::ParseJson(std::istream& JSONToParse){
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
    DataToParse += FilenameToParse;
    std::map<std::string, std::variant<std::string, double, int>> Map = JSON::ParseJsonString(DataToParse);
    JSON toReturn(Map);
    return toReturn;
}

std::string JSON::FindData(const std::string& StringToParse, const std::string& StringToFind){
    //std::cout << StringToFind << std::endl;
    std::string data = "";
    std::string toFind = "";
    if (StringToFind[0] != '"')
    {
        toFind = '"' + StringToFind + '"';
    }else{
        toFind = StringToFind;
    }
    if (StringToParse.find(toFind) != std::string::npos)
    {
        int findWord = StringToParse.find(toFind) + toFind.length() + 1 ;
        if (StringToParse[findWord] == '[') // ebben az esetben listarol van szo!!!
        {
            findWord++;
            do
            {
                data += StringToParse[findWord];
                findWord++;
            } while (StringToParse[findWord] != ']');
            
        }else{
            if (StringToParse[findWord] == '"') // ebben az esetben stringkent
            {
                findWord++;
                do
                {
                    data += StringToParse[findWord];
                    findWord++;
                } while (StringToParse[findWord] != '"');
            }else if(isdigit(StringToParse[findWord])){ // ebben az esetben " nelkul
                do
                {
                    data += StringToParse[findWord];
                    findWord++;
                } while (isdigit(StringToParse[findWord]) or StringToParse[findWord] == '.');
            }
        }
        //std::cout << "-" << data << "-\n\n";
        return data;
    }else{
        throw std::runtime_error("Bad input data..." + StringToParse); //Stringtoparse to delete
    }
}