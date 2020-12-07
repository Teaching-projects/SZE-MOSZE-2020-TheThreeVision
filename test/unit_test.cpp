#include "../JSON.h"
#include "../Hero.h"
#include "../Monster.h"
#include <gtest/gtest.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <variant>

//ToDo new test
/*
    HeroTest            ready
    MonsterTest         ready
    FindData test       ready
    runtime error with finddata     ready
    hp test     ready
    scenario test   ready
    type test ready
    fight test      ready
    fight test with hp      ready
    withspaces      ready
    exception test
    check magical
    Map test
    puthero wongindexexception
    heropos check
*/


TEST(Tests, HeroTest)
{
	Hero hero{Hero::parse("Dark_Wanderer.json")};
    ASSERT_TRUE(hero.getName() == "Prince Aidan of Khanduras");
    ASSERT_TRUE(hero.getHealthPoints() == 30);
    ASSERT_TRUE(hero.getDamage().physical== 3);
    ASSERT_TRUE(hero.getDamage().magical==0);
    ASSERT_TRUE(hero.getAttackCoolDown() == 1.1);
    ASSERT_TRUE(hero.getDefense()==0);
    ASSERT_TRUE(hero.getExperience_per_level() == 20);
    ASSERT_TRUE(hero.getHealth_point_bonus_per_level() == 5);
    ASSERT_TRUE(hero.getDamage_bonus_per_level().physical == 1);
    ASSERT_TRUE(hero.getDamage_bonus_per_level().magical == 2);
    ASSERT_TRUE(hero.getDefense_bonus_per_level() == 0);
    ASSERT_TRUE(hero.getCooldown_multiplier_per_level() == 0.9);

}

TEST(Tests, MonsterTest)
{
	Monster monster{Monster::parse("Fallen.json")};
    ASSERT_TRUE(monster.getName() == "Fallen");
    ASSERT_TRUE(monster.getHealthPoints() == 4);
    ASSERT_TRUE(monster.getDamage().physical == 2);
    ASSERT_TRUE(monster.getDamage().magical == 0);
    ASSERT_TRUE(monster.getAttackCoolDown() == 1.6);
    ASSERT_TRUE(monster.getDefense()==0);
}

TEST(Tests, FindDataTest)
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

TEST(Tests, TestingWithFalseData)
{
	std::string inputString = "{\n\t\"name\":\"vizibicikli\",\n\t\"dmg\":1450,\n\t\"hp\":15330,\n\"atkcd\":2}";
	std::string toFind = "atcd";


	ASSERT_THROW(JSON::FindData(inputString, toFind), std::runtime_error);
}

TEST(Tests, PreparedGame)
{
	JSON scenario = JSON::parseFromFile("Units/preparedgame.txt");
    ASSERT_TRUE(scenario.count("hero") == true);
    ASSERT_TRUE(scenario.count("monster-1") == true);
    ASSERT_TRUE(scenario.count("monster-2") == true);
    ASSERT_TRUE(scenario.count("monster-3") == true);
    ASSERT_TRUE(scenario.count("map") == true);
    std::string hero_name = scenario.get<std::string>("hero");
    ASSERT_TRUE(hero_name == "Dark_Wanderer.json");
}

TEST(Tests,typetest)
{
    Hero hero{Hero::parse("Dark_Wanderer.json")};
    EXPECT_EQ(typeid(std::string),typeid(hero.getName()));
    EXPECT_EQ(typeid(int),typeid(hero.getHealthPoints()));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage().physical));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage().magical));
    EXPECT_EQ(typeid(double),typeid(hero.getAttackCoolDown()));
    EXPECT_EQ(typeid(int),typeid(hero.getDefense()));
    EXPECT_EQ(typeid(double),typeid(hero.getExperience_per_level()));
    EXPECT_EQ(typeid(double),typeid(hero.getHealth_point_bonus_per_level()));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage_bonus_per_level().physical));
    EXPECT_EQ(typeid(int),typeid(hero.getDamage_bonus_per_level().magical));
    EXPECT_EQ(typeid(double),typeid(hero.getDefense_bonus_per_level()));
    EXPECT_EQ(typeid(double),typeid(hero.getCooldown_multiplier_per_level()));
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
    Monster h2 = Monster::parse("Blood_Raven.json");
    h1.fightTilDeath(h2);
    ASSERT_EQ(h1.getLevel(),1);
}

TEST(Tests, exist)
{
    ASSERT_THROW(JSON::ParseJsonString("{\"name\":\"Valaki\",\"hp\": 2}"), std::runtime_error);   
}

TEST(Tests, Level_XP_2)
{
    Hero expected = Hero("Bela", 200, damage(90,10),5.0, 1.0, 1.0, 1.0,damage(1,1), 1.0, 1.0,1.0,1.0);
    EXPECT_EQ(expected.getLevel(), 1);
    EXPECT_EQ(expected.getXP(), 0);
}

TEST(Tests, ParseWithWhitespaces)
{
    Hero hero = Hero::parse("unit.json");
    ASSERT_TRUE(hero.getName() == "vizibicikli");
    ASSERT_TRUE(hero.getHealthPoints() == 15330);
    ASSERT_TRUE(hero.getDamage().physical== 3);
    ASSERT_TRUE(hero.getDamage().magical==0);
    ASSERT_TRUE(hero.getAttackCoolDown() == 2);
    ASSERT_TRUE(hero.getDefense()==0);
    ASSERT_TRUE(hero.getExperience_per_level() == 20);
    ASSERT_TRUE(hero.getHealth_point_bonus_per_level() == 5);
    ASSERT_TRUE(hero.getDamage_bonus_per_level().physical == 1);
    ASSERT_TRUE(hero.getDamage_bonus_per_level().magical == 2);
    ASSERT_TRUE(hero.getDefense_bonus_per_level() == 0);
    ASSERT_TRUE(hero.getCooldown_multiplier_per_level() == 0.9);
}

TEST(Tests, ParseException){

}



int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}