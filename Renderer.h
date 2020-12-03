#include "Game.h"

class Renderer 
{
 private:

 public:
    Renderer();
    ~Renderer();
    virtual void render(const Game&) const =0;

};

class TextRenderer
{
private:
    
public:
    TextRenderer();
    ~TextRenderer();
};

