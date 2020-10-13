#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <any>
#include <vector>

class Parser{
public:
    static std::map<std::string, std::string> ParseJsonFilename(std::string FilenameToParse);
    static std::map<std::string, std::string> ParseJson(std::istream& JSONToParse);
    static std::map<std::string, std::string> ParseJsonString(std::string StringToParse);
};