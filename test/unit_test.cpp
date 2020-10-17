#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include "../parser.h"

TEST(ParserTest, TestingWithFileInput)
{
	std::string inputFilename = "test/unit.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));

    std::ifstream inputFile(inputFilename);

	std::map<std::string, std::string> testingFunction = Parser::ParseJson(inputFile);

    inputFile.close();

	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest, TestingWithFilenameInput)
{
	std::string inputFilename = "test/unit_fail.json";

	std::map<std::string, std::string> testingFunction = Parser::ParseJsonFilename(inputFilename);

	try
	{
		Parser::ParseJsonFilename(inputFilename);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

TEST(ParserTest, TestingWithStringInput)
{
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"hp\":1w3,\n\t\"dmg\"   :    1450\n}";
	
	std::map<std::string, std::string> testingFunction = Parser::ParseJsonString(inputString);

	try
	{
		Parser::ParseJsonString(inputString);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}