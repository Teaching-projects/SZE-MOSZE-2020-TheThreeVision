
#include "../parser.h"
#include <gtest/gtest.h>

TEST(ParserTest, InputString) {
	Parser p;
	std::map<std::string, std::string> TestMap;

	TestMap = p.ParseJsonString("{\n\t\"name\"\t   :  \"vizibicikli\",\n\t\"hp\":15330,\n\t\"dmg\"   :    1450\n}");

	ASSERT_TRUE(TestMap["name"] == "vizibicikli");
	ASSERT_TRUE(stoi(TestMap["hp"]) == 15530);
	ASSERT_TRUE(stoi(TestMap["dmg"]) == 1450);
}

TEST(ParserTest, InputFileName) {
	Parser p;
	std::map<std::string, std::string> TestMap;

	TestMap = p.ParseJsonFilename("unit.json");

	ASSERT_TRUE(TestMap["name"] == "vizibicikli");
	ASSERT_TRUE(stoi(TestMap["hp"]) == 15530);
	ASSERT_TRUE(stoi(TestMap["dmg"]) == 1450);
}

TEST(ParserTest, InputIstream) {
	Parser p;
	std::map<std::string, std::string> TestMap;
	std::fstream filename;

	filename.open("unit.json");
	TestMap = p.ParseJson(filename);
	filename.close();

	ASSERT_TRUE(TestMap["name"] == "vizibicikli");
	ASSERT_TRUE(stoi(TestMap["hp"]) == 15530);
	ASSERT_TRUE(stoi(TestMap["dmg"]) == 1450);
}



int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}