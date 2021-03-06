#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <variant>
#include <vector>
#include <list>
#include <type_traits>

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
	std::map<std::string, std::variant<std::string, double, int>> Data;///<all parsed data
	
	/**
	* \brief This method reads a .json file and returns the keys and the attached data in a std::map.
	* \return return with a std::map
	* \throw throw a "runtime_error" if something wrong
	*/
	static std::map<std::string, std::variant<std::string, double, int>> ParseJson(std::istream& JSONToParse);



public:
	/*
	*\brief This method can parse a Scenario JSON.
	*\note this method use the findData method
	*\return return with a JSON
	*\throw throw a "runtime_error" if something wrong
	*/
	static JSON parseScenario(std::string& JSONstring);
	
	///this list stores the name of the monsters.
	typedef std::list<std::variant<std::string, int,double>>list;	
	/// JSON construct, what put the input parameters to the data member
	JSON(std::map<std::string, std::variant<std::string, double, int>> newData) : Data(newData) {}
	/*
	*\brief This method can read a file and parse it.
	*\note this method use the parseScenario method
	*\return return with a JSON
	*\throw throw a "runtime_error" if something wrong
	*/
	static JSON parseFromFile(const std::string& filePath);

	/**
	* \brief This method reads a .json file as std::string and returns the keys and the attached informations in a std::map.
	* \return return with a std::map
	* \throw throw a "runtime_error" if something wrong
	*/
	static std::map<std::string, std::variant<std::string, double, int>> ParseJsonString(std::string StringToParse);
	
	/**
	 * \brief This method can search a key(std::string) in a std::string and returns the data attached to the key.
	 * \return return with a std::string
	 * \throw throw a "runtime_error" if something wrong
	 */
	static std::string FindData(const std::string& StringToParse, const std::string& StringToFind);

	/**
	 * \brief This method can search a key(std::string) in a JSON object and returns how many times data with this key find.
	 * \return return with a integer
	 */
	int count(const std::string& toFind);
	/**
	 * \brief get information from json
	 * \return return an information from json file
	 */
  	template <typename T>
	inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type get(const std::string& input){
    	return  std::get<T>(Data[input]);
		
  	}
	/**
	 * \brief get information from json
	 * \return return an information from json file
	 */
	template <typename T>
    inline typename std::enable_if<std::is_same<T, JSON::list>::value, JSON::list>::type get(std::string input){
            JSON::list toReturn;
			std::string allFilenames = std::get<std::string>(Data[input]);
				unsigned int counter = 0;
				while (counter < allFilenames.length())
				{
					int find = allFilenames.find(',',counter);
					if (find < 0 )
					{
						find = allFilenames.length();
					}else{
						find = allFilenames.find(',',counter);
					}
					
					std::string toAdd = allFilenames.substr(counter,find-counter);

					toReturn.push_back(toAdd);
					counter = find + 1;
				}
			return toReturn;
        }
	/**
	 * \brief This is a kind of runtime_error
	 */
	class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& msg) : std::runtime_error(msg){}
 	};
	/**
	 * \brief This method opens a .json file and returns the keys and the attached data in a JSON Object.
	 * \return return with a JSON Object
	 * \throw throw a "runtime_error" if something wrong
	 */
    static JSON ParseJsonFilename(std::string FilenameToParse);
   };