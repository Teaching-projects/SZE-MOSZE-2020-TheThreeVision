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
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"hp\":1w3,\n\t\"dmg\"   :    1450,\n \"atkcd\": 2}";

	ASSERT_THROW(Parser::ParseJsonString(inputString), std::runtime_error);
}
//new branch tesztek innentol

TEST(ParserTest2, TestingWithFileInput_randomkeys)
{
	std::string inputFilename = "test/unit2.json";
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
TEST(ParserTest2, TestingWithFilenameInput_randomkeys)
{
	std::string inputFilename = "test/unit2.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	expected.insert(std::pair<std::string, std::string>("atkcd", "2"));



	std::map<std::string, std::string> testingFunction = Parser::ParseJsonFilename(inputFilename);

	ASSERT_EQ(expected, testingFunction);


}
TEST(ParserTest2, TestingWithStringInput_randomkeys)
{
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\"   :    15330,\n \"atkcd\": 2}";

	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	expected.insert(std::pair<std::string, std::string>("atkcd", "2"));



	std::map<std::string, std::string> testingFunction = Parser::ParseJsonString(inputString);

	ASSERT_EQ(expected, testingFunction);
}
TEST(Finddatatests, ALL_DATA_TESTS)
{

	std::string toFind = "hp";
	std::string expected;

	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	expected = "15330";
	std::string data = Parser::FindData(inputString, toFind);

	ASSERT_EQ(expected, data);


	std::string toFind1 = "name";
	std::string expected1;


	expected1 = "vizibicikli";
	std::string data1 = Parser::FindData(inputString, toFind1);

	ASSERT_EQ(expected1, data1);

	std::string toFind2 = "dmg";
	std::string expected2;

	
	expected2 = "1450";
	std::string data2 = Parser::FindData(inputString, toFind2);

	ASSERT_EQ(expected2, data2);

	std::string toFind3 = "atkcd";
	std::string expected3;

	
	expected3 = "2";
	std::string data3 = Parser::FindData(inputString, toFind3);

	ASSERT_EQ(expected3, data3);
}



TEST(Finddatatest, TestingWithfalsedata)
{
	std::string toFind = "atcd";

	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";

	ASSERT_THROW(Parser::FindData(inputString, toFind), std::runtime_error);
}

TEST(ParserTest2, TestingWithFilenameInput_good)
{
	std::string inputFilename = "test/unit2.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	expected.insert(std::pair<std::string, std::string>("atkcd", "2"));

	std::map<std::string, std::string> testingFunction = Parser::ParseJsonFilename(inputFilename);


	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest2, TestingWithStringInput_good)
{
	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	expected.insert(std::pair<std::string, std::string>("atkcd", "2"));

	std::map<std::string, std::string> testingFunction = Parser::ParseJsonString(inputString);


	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest2, TestingWithFilenameInput)
{
	std::string Filename = "test/unit_fail.json";
	std::ifstream inputFile(Filename);

	ASSERT_THROW(Parser::ParseJson(inputFile), std::runtime_error);
}

TEST(Finddatatest, Nametest_withspace)
{

	std::string toFind = "name";
	std::string expected;

	std::string inputString = "{\n\t\"name\":\"vizi bicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	expected = "vizi bicikli";
	std::string data = Parser::FindData(inputString, toFind);

	ASSERT_EQ(expected, data);

}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}