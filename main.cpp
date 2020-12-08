#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Monster.h"
#include "Game.h"

#include "TextRenderer.h"
#include "SVGRenderer.h"

const std::map<int, std::string> error_messages = {
    {1, "Bad number of arguments. Only a single scenario file should be provided."},
    {2, "The provided file is not accessible."},
    {3, "The provided scenario file is invalid."},
    {4, "JSON parsing error."},
    {5, "The game is not initialized."},
    {6, "The game already has a hero."},
    {7, "The game already has units."},
    {8, "The game already started."},
    {9, "This coordinate is occupied."},
    {10, "Wrong index."}};

void bad_exit(int exitcode)
{
    std::cerr
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char **argv)
{
    std::string prep_game = "Units/preparedgame.txt";
    if (!std::filesystem::exists(prep_game))
        bad_exit(2);
    PreparedGame game = PreparedGame(prep_game);
        try
        {
            game.registerRenderer(new HeroTextRenderer());
            game.run();
        }
        catch (Game::NotInitializedException &e)
        {
            std::cout << e.what();
        }
    return 0;
}
