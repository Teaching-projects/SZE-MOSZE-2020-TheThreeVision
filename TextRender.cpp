#include "TextRender.h"

void HeroTextRenderer::render(const Game& g) const
{
   
    for (int y = 0; y < g.getMap().getHeight(); y++)
    {
        for (int x = 0; x < g.getMap().getMaxWidth(); x++)
        {
            if ((g.getMap().get(x, y) == g.getMap().type::Wall) && x >= g.getHero().row - g.getHero().h->getLightRadius() &&
                x <= g.getHero().row + g.getHero().h->getLightRadius() &&
                y >= g.getHero().col - g.getHero().h->getLightRadius() &&
                y <= g.getHero().col + g.getHero().h->getLightRadius())
            {
                std::cout << "██";
            }
            else if (g.getHero().row == x && g.getHero().col == y && x >= g.getHero().row - g.getHero().h->getLightRadius() &&
                x <= g.getHero().row + g.getHero().h->getLightRadius() &&
                y >= g.getHero().col - g.getHero().h->getLightRadius() &&
                y <= g.getHero().col + g.getHero().h->getLightRadius())
            {
                std::cout << "┣┫";
            }
            else if (x >= g.getHero().row - g.getHero().h->getLightRadius() &&
                x <= g.getHero().row + g.getHero().h->getLightRadius() &&
                y >= g.getHero().col - g.getHero().h->getLightRadius() &&
                y <= g.getHero().col + g.getHero().h->getLightRadius())
            {
                int count = 0;
                for (auto a : g.getMonsters())
                {
                    if ((a.row == x && a.col == y) && a.m.isAlive())
                        count++;
                }
                if (count == 1)
                    std::cout << "M░";
                else if (count > 1)
                    std::cout << "MM";
                else
                    std::cout << "░░";
            }
        }
        if (y >= g.getHero().col - g.getHero().h->getLightRadius() && y <= g.getHero().col + g.getHero().h->getLightRadius()) std::cout << std::endl;
    }
}

void ObserverTextRenderer::render(const Game& g) const
{

    for (int y = 0; y < g.getMap().getHeight(); y++)
    {
        for (int x = 0; x < g.getMap().getMaxWidth(); x++)
        {
            if (g.getMap().get(x, y) == g.getMap().type::Wall)
            {
                std::cout << "██";
            }
            else if (g.getHero().row == x && g.getHero().col == y)
            {
                std::cout << "┣┫";
            }
            else
            {
                int count = 0;
                for (auto a : g.getMonsters())
                {
                    if ((a.row == x && a.col == y) && a.m.isAlive())
                        count++;
                }
                if (count == 1)
                    std::cout << "M░";
                else if (count > 1)
                    std::cout << "MM";
                else
                    std::cout << "░░";
            }
        }
        std::cout << std::endl;
}