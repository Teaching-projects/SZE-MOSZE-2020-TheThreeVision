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
	expected.insert(std::pair<std::string, std::string>("atkcd", "2"));

    std::ifstream inputFile(inputFilename);

	std::map<std::string, std::string> testingFunction = Parser::ParseJson(inputFile);

    inputFile.close();

	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest, TestingWithFilenameInput)
{
	std::string inputFilename = "test/unit_fail.json";

	ASSERT_THROW(Parser::ParseJsonFilename(inputFilename), std::runtime_error);
}

TEST(ParserTest, TestingWithStringInput)
{
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"hp\":1w3,\n\t\"dmg\"   :    1450,\n \"attackcooldown\": 2}";

	ASSERT_THROW(Parser::ParseJsonString(inputString), std::runtime_error);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}