#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"
#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <variant>


TEST(Tests, HeroTest)
{
	Hero hero{Hero::parse("Dark_Wanderer.json")};
    ASSERT_TRUE(hero.getHealthPoints() == 30);
    ASSERT_TRUE(hero.getName() == "Prince Aidan of Khanduras");
    ASSERT_TRUE(hero.getDamage().physical== 3);
    ASSERT_TRUE(hero.getDamage().magical==0);
    ASSERT_TRUE(hero.getAttackCoolDown() == 1.1);
    ASSERT_TRUE(hero.getDefense()==0);
}

TEST(Tests, MonsterTest)
{
	Monster monster{Monster::parse("Fallen.json")};
    ASSERT_TRUE(monster.getHealthPoints() == 4);
    ASSERT_TRUE(monster.getName() == "Fallen");
    ASSERT_TRUE(monster.getDamage().physical == 2);
    ASSERT_TRUE(monster.getDamage().magical == 0);
    ASSERT_TRUE(monster.getAttackCoolDown() == 1.6);
    ASSERT_TRUE(monster.getDefense()==0);
}

TEST(Tests, ALL_DATA_TESTS)
{
	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\t\"atkcd\":2\n\t\"defense\":0}";
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

    std::string toFind4="defense";
    std::string expected4="0";
    std::string data4= JSON::FindData(inputString, toFind4);
    ASSERT_EQ(expected4,data4);
}

TEST(Tests, TestingWithfalsedata)
{
	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	std::string toFind = "atcd";


	ASSERT_THROW(JSON::FindData(inputString, toFind), std::runtime_error);
}

TEST(Tests, scenario1)
{
	JSON scenario = JSON::parseFromFile("Units/preparedgame.txt");
    ASSERT_TRUE(scenario.count("hero") == true);
    ASSERT_TRUE(scenario.count("monsters-1") == true);
    ASSERT_TRUE(scenario.count("monsters-2") == true);
    ASSERT_TRUE(scenario.count("monsters-3") == true);
    ASSERT_TRUE(scenario.count("map") == true);
    std::string hero_name = scenario.get<std::string>("hero");
    ASSERT_TRUE(hero_name == "Dark_Wanderer.json");
}

TEST(Tests,typetest)
{
    Hero hero{Hero::parse("Dark_Wanderer.json")};
    EXPECT_EQ(typeid(int),typeid(hero.getHealthPoints()));
    EXPECT_EQ(typeid(std::string),typeid(hero.getName()));
    EXPECT_EQ(typeid(double),typeid(hero.getAttackCoolDown()));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage().physical));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage().magical));
    EXPECT_EQ(typeid(int),typeid(hero.getDefense()));
}

TEST(Tests, HPTest)
{
    Hero h1 = Hero::parse("Dark_Wanderer.json");
    Monster h2 = Monster::parse("Blood_Raven.json");
    h1.fightTilDeath(h2);
    ASSERT_DOUBLE_EQ(h1.getHealthPoints(),0);
    ASSERT_DOUBLE_EQ(h2.getHealthPoints(),101);
}

TEST(Tests, SuccessfulFight)
{
    Hero h1 = Hero::parse("Dark_Wanderer.json");
    Monster h2 = Monster::parse("Blood_Raven.json");
    EXPECT_NO_THROW(h1.fightTilDeath(h2));
}

TEST(Tests, LevelTest)
{
    Hero h1 = Hero::parse("Dark_Wanderer.json");
    Monster h2 = Monster::parse("Zombie.json");
    h1.fightTilDeath(h2);
    ASSERT_EQ(h1.getLevel(),1);
}

TEST(Tests, AdditionalTest)
{
    Hero h1 = Hero::parse("Dark_Wanderer.json");
    Monster h2 = Monster::parse("Zombie.json");
    h1.fightTilDeath(h2);
    ASSERT_EQ(h1.getLevel(),1);
}

TEST(Tests, exist)
{
    ASSERT_THROW(JSON::ParseJsonString("{\"name\":\"Valaki\",\"hp\": 2}"), std::runtime_error);   
}

TEST(Tests, Level_XP_2)
{
    Hero expected = Hero("Bela", 200, damage(90,10),5.0, 1.0, 1.0, 1.0,damage(1,1), 1.0, 1.0);
    EXPECT_EQ(expected.getLevel(), 1);
    EXPECT_EQ(expected.getXP(), 0);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}