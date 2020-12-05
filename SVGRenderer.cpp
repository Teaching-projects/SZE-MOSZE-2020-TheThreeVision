#include "SVGRenderer.h"

void ObserverSVGRenderer::render(const Game& game) const
{
    int x = 0, y = 0;
    int fullwidth = game.getMap().getMaxWidth() * 10;
    int fullHeight = game.getMap().getHeight() * 10;
    std::ofstream svg(Filename);
    std::map<std::string, std::string> textures = game.getTextures();
    std::string wall = game.getTextures()["wall_texture"];
    std::string free = game.getTextures()["free_texture"];
    //TODO in Monster and hero new argument +getter ++googletest
    //std::string hero = game.getHero().h->getTexture();

    if (!std::filesystem::exists(wall)) wall = game.getTextures()["empty_texture"];
    if (!std::filesystem::exists(free)) free = game.getTextures()["empty_texture"];
   // if (!std::filesystem::exists(hero)) hero = game.getTextures()["empty_texture"];


}

void CharacterSVGRenderer::render(const Game& game) const
{

}
