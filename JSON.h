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
	/*
	*\brief This method can parse a Scenario JSON.
	*\note this method use the findData method
	*\return return with a JSON
	*\throw throw a "runtime_error" if something wrong
	*/
	static JSON parseScenario(std::string& JSONstring);
	/**
	 * \brief This method can search a key(std::string) in a std::string and returns the data attached to the key.
	 * \return return with a std::string
	 * \throw throw a "runtime_error" if something wrong
	 */
	static std::string FindData(const std::string& StringToParse, const std::string& StringToFind);
	/**
	* \brief This method reads a .json file as std::string and returns the keys and the attached informations in a std::map.
	* \return return with a std::map
	* \throw throw a "runtime_error" if something wrong
	*/
	static std::map<std::string, std::variant<std::string, double, int>> ParseJsonString(std::string StringToParse);
	/**
	* \brief This method reads a .json file and returns the keys and the attached data in a std::map.
	* \return return with a std::map
	* \throw throw a "runtime_error" if something wrong
	*/
	static std::map<std::string, std::variant<std::string, double, int>> ParseJson(std::istream& JSONToParse);



public:
	/// JSON construct, what put the input parameters to the data member
	JSON(std::map<std::string, std::variant<std::string, double, int>> newData) : Data(newData) {}
	/*
	*\brief This method can read a file and parse it.
	*\note this method use the parseScenario method
	*\return return with a JSON
	*\throw throw a "runtime_error" if something wrong
	*/
	static JSON parseFromFile(const std::string& filePath);


	int count(const std::string& toFind);

	template <typename T>
  	T get(const std::string& input){
    	return  std::get<T>(Data[input]);
		
  	}

	class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& msg) : std::runtime_error(msg){};
 	};
	/**
	 * \brief This method opens a .json file and returns the keys and the attached data in a std::map.
	 * \return return with a std::map
	 * \throw throw a "runtime_error" if something wrong
	 */
    static JSON ParseJsonFilename(std::string FilenameToParse);
   
   };