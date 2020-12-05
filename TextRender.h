#pragma once
#include "Renderer.h"

class TextRenderer : public Renderer
{
protected:
    std::ostream& OutStream; ///< output stream type.
public:
    /// TextRenderer constructor
    TextRenderer(std::ostream& stream = std::cout) : OutStream(stream) {}
    /// Render method
    virtual void render(const Game&) const = 0;
    /// Simple setter to output stream type.
    void setOutputStream(std::ostream& stream){
        OutStream.copyfmt(stream);
    }
};



class HeroTextRenderer : public TextRenderer
{
public:
    /// HeroTextRenderer constructor
    HeroTextRenderer(std::ostream& stream = std::cout) : TextRenderer(stream) {}
    /// Render method
    void render(const Game&) const override;
};

class ObserverTextRenderer : public TextRenderer
{
public:
    /// TextRenderer constructor
    ObserverTextRenderer(std::ostream& stream = std::cout) : TextRenderer(stream) {}
    /// Render method
    void render(const Game&) const override;
};
    