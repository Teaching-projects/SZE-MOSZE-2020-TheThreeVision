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
    int endOfWord;
    for (int i = findWord; i < DataToParse.length(); i++)
    {
        if (DataToParse[i] == '"')
        {
            endOfWord = i;
        } 
    }
    Map["name"] = DataToParse.substr(findWord,endOfWord-findWord);
    Map["hp"] = 10;
    Map["dmg"] = 11;
    
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







/*std::map<std::string, std::string> Parser::parseString(std::string InputString){
    std::map<std::string, std::string> Map;
    if (InputString.find('{') != std::string::npos){
        Map = ParseJson(InputString);
    }
    std::ifstream JFile(InputString);
    if (JFile.good())
    {
        Map = ParseJson(JFile);
    }else{
        throw std::runtime_error("Bad input data.");
    }
    return Map;
}*/

/*std::map<std::string, std::string> Parser::ParseJson(std::string JString){

}*/

/*std::map<std::string, std::string> Parser::ParseJson(std::ifstream& File){
    std::vector<std::string> data;
    std::map<std::string, std::string> Map;
    std::string newLine, name, hp, dmg;
    if (File.good()) {
        while (getline(File, newLine)) {
            data.push_back(newLine);
        }
        data[0].erase();
        data[data.size() - 1].erase();
        for (int i = 0; i < data.size(); i++) {
            int c;
            c = data[i].find('"');
            if (data[i][c + 1] == 'n') {
                c = data[i].find(':');
                std::string temp;
                temp = data[i].substr(c + 3, data[i].length());
                Map["name"] = temp.substr(0, temp.length() - 2);
            }
            else if (data[i][c + 1] == 'h') {
                c = data[i].find(':');
                std::string temp;
                temp = data[i].substr(c + 2, data[i].length());
                temp = temp.substr(0, temp.length() - 1);
                Map["hp"]  = temp;
            }
            else if (data[i][c + 1] == 'd') {
                c = data[i].find(':');
                std::string temp;
                temp = data[i].substr(c + 2, data[i].length());
                temp = temp.substr(0, temp.length());
                Map["dmg"]  = temp;
            }
        }
        return Map;
    }
    else {
        throw std::runtime_error("There is a problem with the file.");
    }
    
}*/