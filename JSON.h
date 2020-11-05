#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <variant>
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
	std::map<std::string, std::variant<std::string, double, int>> Data;
public:
	JSON(std::map<std::string, std::variant<std::string, double, int>> newData) : Data(newData) {}

	static JSON parseFromFile(const std::string& filePath);
	static JSON parseScenario(std::string& JSONstring);

	int count(const std::string& toFind);

	template <typename T>
  	T get(const std::string& input){
    	return  std::get<T>(Data[input]);
		
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
    static JSON FindData(const std::string& StringToParse, const std::string& StringToFind);
    /**
	 * \brief This method opens a .json file and returns the keys and the attached data in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
    static JSON ParseJsonFilename(std::string FilenameToParse);
    /**
	 * \brief This method reads a .json file and returns the keys and the attached data in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
	static std::map<std::string, std::variant<std::string, double, int>> ParseJson(std::istream& JSONToParse);

    /**
	 * \brief This method reads a .json file as std::string and returns the keys and the attached informations in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
    static std::map<std::string, std::variant<std::string, double, int>> ParseJsonString(std::string StringToParse);
};