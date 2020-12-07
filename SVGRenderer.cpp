#include "SVGRenderer.h"

std::string getEmpty(int x,int y,int es) {
    std::string s = "<g transform=\"translate(";
    s += x + "," + y;
    s += ") scale(0.0" + es;
    s+=",0.0" + es;
    s +=") \"fill=\"#000000\" stroke=\"none\"><path d=\"M0 640 l0 -640 640 0 640 0 0 640 0 640 -640 0 -640 0 0 -640z\"/></g>";
    return s;
}
void ObserverSVGRenderer::render(const Game& game) const
{
    int fullWidth = game.getMap().getMaxWidth() * 10;
    int fullHeight = game.getMap().getHeight() * 10;

    //find textures
    std::map<std::string, std::string> textures = game.getTextures();
    std::string wall = game.getTextures()["wall_texture"];
    std::string free = game.getTextures()["free_texture"];
    std::string hero = game.getHero().h->getTexture();
      

    //if not find some texures
    if (!std::filesystem::exists(wall)) wall = "";
    if (!std::filesystem::exists(free)) free = "";
    if (!std::filesystem::exists(hero)) hero = "";
    std::map<std::string,bool> monsterTexures;
    for (auto a : game.getMonsters())
    {
        if (std::filesystem::exists(a.m.getTexture())) {
            monsterTexures.insert(std::make_pair(a.m.getTexture(), true));
        }else{ monsterTexures.insert(std::make_pair(a.m.getTexture(), false)); }
    }
    //start of file
    std::ofstream svgOutput(Filename);
    svgOutput << "<svg version=\"1.0\" xmlns=\"http://www.w3.org/2000/svg\"";
    svgOutput << "width = \"" << fullWidth << "pt\" height=\"" << fullHeight << "pt\" viewBox=\"-10 -10 " << fullWidth << " " << fullHeight << "\">";

    for (int y = 0; y < fullHeight; y+=10){
        for (int x = 0; x < fullWidth; x+=10){
            if (game.getMap().get(x, y) == game.getMap().type::Wall)
            {
                if (wall != "") svgOutput << "<image x = \"" << x << "\" y=\"" << y << "\" width=\"" << elementSize << "\" height=\"" << elementSize << "\" href=\"" << wall << "\" />";
                else svgOutput << getEmpty(x,y,elementSize);
            }
            else if (game.getHero().row == x && game.getHero().col == y)
            {
                if (hero != "") svgOutput << "<image x = \"" << x << "\" y=\"" << y << "\" width=\"" << elementSize << "\" height=\"" << elementSize << "\" href=\"" << hero << "\" />";
                else svgOutput << getEmpty(x, y, elementSize);
            }
            else if (game.getMap().get(x, y) == game.getMap().type::Free)
            {
                if (free != "") svgOutput << "<image x = \"" << x << "\" y=\"" << y << "\" width=\"" << elementSize << "\" height=\"" << elementSize << "\" href=\"" << free << "\" />";
                else svgOutput << getEmpty(x, y, elementSize);
            }
            else
            {
                int count = 1;
                for (auto a : game.getMonsters())
                {
                    int eSize = elementSize / count;
                    int ex = x + (count-1)*eSize, ey = y + (count - 1) * eSize;
                    if ((a.row == x && a.col == y) && a.m.isAlive()) {
                        if (monsterTexures[a.m.getTexture()]) svgOutput << "<image x = \"" << ex << "\" y=\"" << ey << "\" width=\"" << eSize << "\" height=\"" << eSize << "\" href=\"" << a.m.getTexture() << "\" />";
                        else svgOutput << getEmpty(ex, ey, eSize);
                        
                        count++;
                    }
                }
                
            }
        }

    }
        

     
  
    //end of file
    svgOutput << "</svg>";
    svgOutput.close();
}

void CharacterSVGRenderer::render(const Game& game) const{
    
}
