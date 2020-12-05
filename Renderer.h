#pragma once
#include "Game.h"
#include <ostream>

class Game;

class Renderer
{
private:
public:
    Renderer() {};
    ~Renderer() {};
    virtual void render(const Game &) const = 0;
};

