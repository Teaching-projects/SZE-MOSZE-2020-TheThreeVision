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

	try
	{
		Parser::ParseJsonFilename(inputFilename);
	}
	catch(const std::runtime_error& e)
	{
		EXPECT_STREQ("Bad input data.", e.what());
	}
}

TEST(ParserTest, TestingWithStringInput)
{
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"hp\":1w3,\n\t\"dmg\"   :    1450\n}";

	try
	{
		Parser::ParseJsonString(inputString);
	}
	catch(const std::runtime_error& e)
	{
		EXPECT_STREQ("Bad input data.", e.what());
	}
}

TEST(ParserTest, TestingFindData)
{
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"hp\":1553,\n\t\"dmg\"   :    1450\n}";

	std::string data = Parser::FindData(inputString, "name");
	std::string expected;
	expected.insert("vizibicikli");

	ASSERT_EQ(expected, data);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}