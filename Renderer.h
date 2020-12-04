#include "Game.h"
#include <ostream>

class Renderer
{
private:
public:
    Renderer();
    ~Renderer();
    virtual void render(const Game &) const = 0;
};

class TextRenderer : public Renderer
{
protected:
    std::ostream &out_stream; ///< A kimenet típusa.
public:
    /// TextRenderer konstruktor
    TextRenderer(std::ostream &stream = std::cout) : out_stream(stream) {}
    /// Render függvény
    virtual void render(const Game &) const = 0;
    /// Ez a függvény beállítja kimenetet.
    void setOutputStream(std::ostream &stream)
    {
        out_stream.copyfmt(stream);
    }
};

class HeroTextRenderer : public TextRenderer
{
public:
    /// HeroTextRenderer konstruktor
    HeroTextRenderer(std::ostream &stream = std::cout) : TextRenderer(stream) {}
    void render(const Game &) const override;
};

class ObserverTextRenderer : public TextRenderer
{
public:
    /// TextRenderer konstruktor
    ObserverTextRenderer(std::ostream &stream = std::cout) : TextRenderer(stream) {}
    /// Render függvény
    void render(const Game &) const override;
};
