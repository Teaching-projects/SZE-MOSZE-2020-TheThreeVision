#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <any>
#include <vector>

/**
 * \class Parser
 * 
 * \brief Parser class
 * 
 * \author poloczmate
 *
 * \date 2020.10.28. 21:00
 *
 * \note The Parser can read data from JSON files
 * 
 */

class Parser{
public:
/**
	 * \brief This method can search a key(std::string) in a std::string and returns the data attached to the key.
	 * \return return with a std::string
	 * \throw throw a "runtime_error" if something wrong
	 */
    static std::string FindData(const std::string& StringToParse, const std::string& StringToFind);
    /**
	 * \brief This method opens a .json file and returns the keys and the attached data in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
    static std::map<std::string, std::string> ParseJsonFilename(std::string FilenameToParse);
    /**
	 * \brief This method reads a .json file and returns the keys and the attached data in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
    static std::map<std::string, std::string> ParseJson(std::istream& JSONToParse);
    /**
	 * \brief This method reads a .json file as std::string and returns the keys and the attached informations in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
    static std::map<std::string, std::string> ParseJsonString(std::string StringToParse);
};