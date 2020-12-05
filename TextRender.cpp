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
                OutStream << "██";
            }
            else if (g.getHero().row == x && g.getHero().col == y && x >= g.getHero().row - g.getHero().h->getLightRadius() &&
                x <= g.getHero().row + g.getHero().h->getLightRadius() &&
                y >= g.getHero().col - g.getHero().h->getLightRadius() &&
                y <= g.getHero().col + g.getHero().h->getLightRadius())
            {
                OutStream << "┣┫";
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
                    OutStream << "M░";
                else if (count > 1)
                    OutStream << "MM";
                else
                    OutStream << "░░";
            }
        }
        if (y >= g.getHero().col - g.getHero().h->getLightRadius() && y <= g.getHero().col + g.getHero().h->getLightRadius()) OutStream << "\n";
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
                OutStream << "██";
            }
            else if (g.getHero().row == x && g.getHero().col == y)
            {
                OutStream << "┣┫";
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
                    OutStream << "M░";
                else if (count > 1)
                    OutStream << "MM";
                else
                    OutStream << "░░";
            }
        }
        OutStream << "\n";
    }
}