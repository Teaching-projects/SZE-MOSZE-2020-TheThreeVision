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
    if (argc == 2)
    {
        if (!std::filesystem::exists(argv[1]))
            bad_exit(2);
        PreparedGame game = PreparedGame(argv[1]);
        try
        {
            std::ofstream stream = std::ofstream("log.txt");
            game.registerRenderer(new HeroTextRenderer());
            game.registerRenderer(new ObserverTextRenderer(stream));
            game.registerRenderer(new CharacterSVGRenderer("pretty.svg"));
            game.registerRenderer(new ObserverSVGRenderer("prettyObserver.svg"));
            game.run();
        }
        catch (Game::NotInitializedException &e)
        {
            std::cout << e.what();
        }
    }else{
        bad_exit(1);
    }

    return 0;
}
