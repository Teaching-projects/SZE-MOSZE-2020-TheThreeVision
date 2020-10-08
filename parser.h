#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <any>
#include <vector>

class Parser{
public:
    static std::map<std::string, std::string> ParseJson(std::string DataToParse);
    static std::map<std::string, std::string> ParseJson(std::istream& JSONToParse);
};