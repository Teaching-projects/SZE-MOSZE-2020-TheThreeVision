#pragma once
#include "Renderer.h"

class TextRenderer : public Renderer
{
protected:
    std::ostream& OutStream; ///< output stream type.
public:
    /// TextRenderer constructor
    TextRenderer(std::ostream& stream = std::cout/** [in] an output stream type*/) : OutStream(stream) {}
    ~TextRenderer() {}
    /// Render method
    virtual void render(const Game&/** [in]  a printable Game*/ ) const = 0;
    /// Simple setter to output stream type.
    void setOutputStream(std::ostream& stream/** [in] an output stream type*/){
        OutStream.copyfmt(stream);
    }
};



class HeroTextRenderer : public TextRenderer
{
public:
    /// HeroTextRenderer constructor
    HeroTextRenderer(std::ostream& stream = std::cout/** [in] an output stream type*/) : TextRenderer(stream) {}
    /// Render method
    void render(const Game& game/**[in]  a printable Game*/) const;
};

class ObserverTextRenderer : public TextRenderer
{
public:
    /// TextRenderer constructor
    ObserverTextRenderer(std::ostream& stream = std::cout/** [in] an output stream type*/) : TextRenderer(stream) {}
    /// Render method
    void render(const Game& game/**[in]  a printable Game*/) const;
};
    