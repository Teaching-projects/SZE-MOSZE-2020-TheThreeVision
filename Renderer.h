#include "Game.h"
#include <ostream>

class Renderer
{
private:
public:
    Renderer() {};
    ~Renderer() {};
    virtual void render(const Game &) const = 0;
};

