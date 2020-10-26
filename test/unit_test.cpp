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
TEST(Finddatatest, Hptest) 
{
	
	std::string toFind="hp";
	std::string expected;

	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	expected = "15330";
	std::string data = Parser::FindData(inputString,toFind);

	ASSERT_EQ(expected, data);

}
TEST(Finddatatest, Nametest)
{

	std::string toFind = "name";
	std::string expected;

	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	expected = "vizibicikli";
	std::string data = Parser::FindData(inputString, toFind);

	ASSERT_EQ(expected, data);

}
TEST(Finddatatest, dmgtest)
{

	std::string toFind = "dmg";
	std::string expected;

	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	expected = "1450";
	std::string data = Parser::FindData(inputString, toFind);

	ASSERT_EQ(expected, data);

}
TEST(Finddatatest, atkcd)
{

	std::string toFind = "atkcd";
	std::string expected;

	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	expected = "2";
	std::string data = Parser::FindData(inputString, toFind);

	ASSERT_EQ(expected, data);

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

TEST(ParserTest, TestingWithFilenameInput)
{
	std::string Filename = "test/unit_fail.json";
	std::ifstream inputFile(Filename);

	ASSERT_THROW(Parser::ParseJson(inputFile), std::runtime_error);
}
	

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}