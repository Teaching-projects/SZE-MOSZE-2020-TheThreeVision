#include "SVGRenderer.h"
#include <sstream> 

std::string getElement(std::string e,int x, int y, int eW, int eH) {
    std::stringstream ss;
    if (e != "") ss << "<image x = \"" << x << "\" y=\"" << y << "\" width=\"" << eW << "\" height=\"" << eH << "\" href=\"" << e << "\" />";
    else ss << "<g transform=\"translate(" << x << "," << y << ") scale(0.0" << eW << ",0.0" << eH << ")\""
            << " fill=\"#000000\" stroke=\"none\">"
            << "\n<path d=\"M0 640 l0 -640 640 0 640 0 0 640 0 640 -640 0 -640 0 0 -640z\"/>\n</g>\n";
    return ss.str();
}
void ObserverSVGRenderer::render(const Game& game) const
{
    int fullWidth = game.getMap().getMaxWidth() * elementSize;
    int fullHeight = game.getMap().getHeight() * elementSize;

    //find textures
    std::map<std::string, std::string> textures = game.getTextures();
    std::string wall = game.getTextures()["wall_texture"];
    std::string free = game.getTextures()["free_texture"];
    std::string hero = game.getHero().h->getTexture();
      

    //if not find some texures
    if (!std::filesystem::exists(wall)) wall = "";
    if (!std::filesystem::exists(free)) free = "";
    if (!std::filesystem::exists(hero)) hero = "";
    std::map<std::string, std::string> monsterTexures;
    for (auto a : game.getMonsters())
    {
        if (std::filesystem::exists(a.m.getTexture())) {
            monsterTexures.insert(std::make_pair(a.m.getTexture(), a.m.getTexture()));
        }else{ monsterTexures.insert(std::make_pair(a.m.getTexture(), "")); }
    }
    //start of file
    std::ofstream svgOutput(Filename);
    svgOutput << "<svg version=\"1.0\" xmlns=\"http://www.w3.org/2000/svg\" \n";
    svgOutput << "width = \"" << fullWidth+20 << "pt\" height=\"" << fullHeight + 20 << "pt\" viewBox=\"-10 -10 " << fullWidth + 20 << " " << fullHeight + 20 << "\">\n\n";

    for (int y = 0; y < fullHeight; y+=elementSize){
        for (int x = 0; x < fullWidth; x+=elementSize){
            if (game.getMap().get(x/ elementSize, y/ elementSize) == game.getMap().type::Wall)
            {
                svgOutput << getElement(wall, x, y, elementSize, elementSize);
            }
            else if (game.getHero().row == x/ elementSize && game.getHero().col == y/ elementSize)
            {
                svgOutput << getElement(hero, x, y, elementSize, elementSize);
            }
           
            else
            {
                int count = 1;
                for (auto a : game.getMonsters())
                {
                    int eSize = elementSize / count;
                    int ex = x + (count - 1) * eSize;
                    if ((a.row == x/ elementSize && a.col == y/ elementSize) && a.m.isAlive()) {
                        svgOutput << getElement(monsterTexures[a.m.getTexture()], ex, y, eSize, elementSize);
                        count++;
                    }
                }
                if (count==1)
                {
                    svgOutput << getElement(free, x, y, elementSize, elementSize);
                }
                
            }
        }

    }
        

     
  
    //end of file
    svgOutput << "</svg>\n";
    svgOutput.close();
}

void CharacterSVGRenderer::render(const Game& game) const{
    
    int fullWidth = game.getMap().getMaxWidth() * elementSize;
    int fullHeight = game.getMap().getHeight() * elementSize;
    int radius = game.getHero().h->getLightRadius() * elementSize;
    int row = game.getHero().row * elementSize;
    int col = game.getHero().col * elementSize;
    //find textures
    std::map<std::string, std::string> textures = game.getTextures();
    std::string wall = game.getTextures()["wall_texture"];
    std::string free = game.getTextures()["free_texture"];
    std::string hero = game.getHero().h->getTexture();
      

    //if not find some texures
    if (!std::filesystem::exists(wall)) wall = "";
    if (!std::filesystem::exists(free)) free = "";
    if (!std::filesystem::exists(hero)) hero = "";
    std::map<std::string, std::string> monsterTexures;
    for (auto a : game.getMonsters())
    {
        if (std::filesystem::exists(a.m.getTexture())) {
            monsterTexures.insert(std::make_pair(a.m.getTexture(), a.m.getTexture()));
        }else{ monsterTexures.insert(std::make_pair(a.m.getTexture(), "")); }
    }
    //start of file
    std::ofstream svgOutput(Filename);
    svgOutput << "<svg version=\"1.0\" xmlns=\"http://www.w3.org/2000/svg\" \n";
    int viewBoxRow = row - radius; if (viewBoxRow < 0)viewBoxRow = 0; viewBoxRow -= 10;
    int viewBoxCol = col - radius; if (viewBoxCol < 0)viewBoxCol = 0; viewBoxCol -= 10;
    svgOutput << "width = \"" << fullWidth+20 << "pt\" height=\"" << fullHeight + 20 << "pt\" viewBox=\"" << viewBoxRow << " " << viewBoxCol << " " << fullWidth + 20 << " " << fullHeight + 20 << "\">\n\n";

    for (int y = 0; y < fullHeight; y+=elementSize){
        for (int x = 0; x < fullWidth; x+=elementSize){
            if ((game.getMap().get(x/ elementSize, y/ elementSize) == game.getMap().type::Wall) && 
                x >= row - radius &&
                x <= row + radius &&
                y >= col - radius &&
                y <= col + radius)
            {
                svgOutput << getElement(wall, x, y, elementSize, elementSize);
            }
            else if (game.getHero().row == x/ elementSize && game.getHero().col == y/ elementSize )
            {
                svgOutput << getElement(hero, x, y, elementSize, elementSize);
            }
           
            else if (x >= row - radius &&
                x <= row + radius &&
                y >= col - radius &&
                y <= col + radius)
            {
                int count = 1;
                for (auto a : game.getMonsters())
                {
                    int eSize = elementSize / count;
                    int ex = x + (count - 1) * eSize;
                    if ((a.row == x/ elementSize && a.col == y/ elementSize) && a.m.isAlive()) {
                        svgOutput << getElement(monsterTexures[a.m.getTexture()], ex, y, eSize, elementSize);
                        count++;
                    }
                }
                if (count==1)
                {
                    svgOutput << getElement(free, x, y, elementSize, elementSize);
                }
                
            }
        }

    }
        

     
  
    //end of file
    svgOutput << "</svg>\n";
    svgOutput.close();
}
