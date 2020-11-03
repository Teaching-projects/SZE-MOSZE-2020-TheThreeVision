#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <any>
#include <vector>

/**
 * \class JSON
 * 
 * \brief JSON class
 * 
 * \author poloczmate
 *
 * \date 2020.10.28. 21:00
 *
 * \note The JSON can read data from JSON files
 * 
 */

class JSON{
private:
	std::map<std::string, std::string> Data;
public:
	JSON(std::map<std::string, std::string> newData) : Data(newData) {}

	JSON parseFromFile(std::string& filePath);
	std::map<std::string, std::string> parseScenario(std::string& JSONstring);

	int count(const std::string& toFind);

	template <class Temp>
  	Temp get(const std::string& input){
    	Temp toReturn = Data(input);
    	return toReturn;
  	}

	class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& msg) : std::runtime_error(msg){}
 	};
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