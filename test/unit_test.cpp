#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include "../parser.h"

TEST(ParserTest, TestingWithFileInput)
{
	std::string inputFilename = "unit_test.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));

    std::ifstream inputFile(inputFilename);

	std::map<std::string, std::string> testingFunction = Parser::parseJson(inputFile);

    inputFile.close();

	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest, TestingWithFilenameInput)
{
	std::string inputFilename = "unit_test.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	std::map<std::string, std::string> testingFunction = Parser::parseJsonFilename(inputFilename);

	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest, TestingWithStringInput)
{
	std::string inputString = "{\n\t\"name\"\t   :  \"vizibicikli\",\n\t\"hp\":15330,\n\t\"dmg\"   :    1450\n}";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	std::map<std::string, std::string> testingFunction = Parser::parseJsonString(inputString);

	ASSERT_EQ(expected, testingFunction);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}