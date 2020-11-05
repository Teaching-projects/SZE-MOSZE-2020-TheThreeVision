#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"


TEST(ParserTest, TestingWithFileInput)
{
	/*std::string inputFilename = "Units/Dark_Wanderer.json";
	std::map<std::string, std::variant<std::string, double, int>> expected;
	expected.insert(std::make_pair("name", "Prince Aidan of Khanduras"));
	expected.insert(std::make_pair("points", std::stoi("30")));
	expected.insert(std::make_pair("damage", std::stoi("3")));
	expected.insert(std::make_pair("cooldown", std::stod("1.1")));

	std::ifstream inputFile(inputFilename);

	JSON testingFunction = JSON::ParseJson(inputFile);
	JSON e(expected);

	inputFile.close();

	ASSERT_EQ(e, testingFunction);*/
	Hero hero{Hero::parse("Units/Dark_Wanderer.json")};
    ASSERT_TRUE(hero.getHealthPoints() == 30);
    ASSERT_TRUE(hero.getName() == "Prince Aidan of Khanduras");
    ASSERT_TRUE(hero.getDamage() == 3);
    ASSERT_TRUE(hero.getAttackCoolDown() == 1.1);
}
/*
TEST(ParserTest, TestingWithFilenameInput)
{
	std::string inputFilename = "test/unit_fail.json";

	ASSERT_THROW(JSON::ParseJsonFilename(inputFilename), std::runtime_error);
}

TEST(ParserTest, TestingWithStringInput)
{
	std::string inputString = "{\n\t\"name\"  :  \"vizibicikli\",\n\t\"hp\":1w3,\n\t\"dmg\"   :    1450,\n \"atkcd\": 2}";

	ASSERT_THROW(JSON::ParseJsonString(inputString), std::runtime_error);
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

	std::map<std::string, std::string> testingFunction = JSON::ParseJson(inputFile);

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



	std::map<std::string, std::string> testingFunction = JSON::ParseJsonFilename(inputFilename);

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



	std::map<std::string, std::string> testingFunction = JSON::ParseJsonString(inputString);

	ASSERT_EQ(expected, testingFunction);
}
TEST(Finddatatests, ALL_DATA_TESTS)
{
	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	std::string toFind = "hp";
	std::string expected = "15330";;


	std::string data = JSON::FindData(inputString, toFind);
	ASSERT_EQ(expected, data);


	std::string toFind1 = "name";
	std::string expected1 = "vizibicikli";;


	std::string data1 = JSON::FindData(inputString, toFind1);
	ASSERT_EQ(expected1, data1);


	std::string toFind2 = "dmg";
	std::string expected2 = "1450";


	std::string data2 = JSON::FindData(inputString, toFind2);

	ASSERT_EQ(expected2, data2);

	std::string toFind3 = "atkcd";
	std::string expected3 = "2";;


	std::string data3 = JSON::FindData(inputString, toFind3);

	ASSERT_EQ(expected3, data3);
}



TEST(Finddatatest, TestingWithfalsedata)
{
	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	std::string toFind = "atcd";


	ASSERT_THROW(JSON::FindData(inputString, toFind), std::runtime_error);
}

TEST(ParserTest2, TestingWithFilenameInput_good)
{
	std::string inputFilename = "test/unit.json";
	std::map<std::string, std::string> expected;
	expected.insert(std::pair<std::string, std::string>("name", "vizibicikli"));
	expected.insert(std::pair<std::string, std::string>("hp", "15330"));
	expected.insert(std::pair<std::string, std::string>("dmg", "1450"));
	expected.insert(std::pair<std::string, std::string>("atkcd", "2"));

	std::map<std::string, std::string> testingFunction = JSON::ParseJsonFilename(inputFilename);


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

	std::map<std::string, std::string> testingFunction = JSON::ParseJsonString(inputString);


	ASSERT_EQ(expected, testingFunction);
}

TEST(ParserTest2, TestingWithFilenameInput)
{
	std::string Filename = "test/unit_fail.json";
	std::ifstream inputFile(Filename);

	ASSERT_THROW(JSON::ParseJson(inputFile), std::runtime_error);
}

TEST(Finddatatest, Nametest_withspace)
{
	std::string inputString = "{\n\t\"name\":\"vizi bicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	std::string toFind = "name";
	std::string expected = "vizi bicikli";;


	std::string data = JSON::FindData(inputString, toFind);

	ASSERT_EQ(expected, data);

}
TEST(DATATEST, _NOT_EXISTINGFILE)
{
	std::string inputFilename = "test/doesitexist.json";

	ASSERT_THROW(JSON::ParseJsonFilename(inputFilename), std::runtime_error);

}

TEST(Fight, isdead)
{
	Monster* p1 = Monster::parseUnit("Units/Maple.json");
	Monster* p2 = Monster::parseUnit("Units/Sally.json");
	p1->Fight(p2);
	ASSERT_TRUE(p1->getHP() <= 0 || p2->getHP() <= 0);
}
TEST(Fight, runtest)
{
	Monster* p1 = Monster::parseUnit("Units/Maple.json");
	Monster* p2 = Monster::parseUnit("Units/Sally.json");

	EXPECT_NO_THROW(p1->Fight(p2));
	
}
*/
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}