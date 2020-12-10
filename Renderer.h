#pragma once
#include "Game.h"
#include <ostream>

class Game;
/**
 * \brief Renders the Game
 *
 * \date 2020.12.10. 13:23
 *
 */
class Renderer
{
private:
public:
    Renderer() {};
    ~Renderer() {};
    /// render method
    virtual void render(const Game &game /**[in] is  a printable Game*/) const = 0;
};

