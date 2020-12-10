#pragma once
#include "Renderer.h"
/// Renders the game to text
class TextRenderer : public Renderer
{
protected:
    std::ostream& OutStream; ///< output stream type.
public:
    /// This is a constructor 
    TextRenderer(std::ostream& stream = std::cout/** [in] is an output stream type*/) : OutStream(stream) {}
    ~TextRenderer() {}
    /// Render method
    virtual void render(const Game&/** [in] is a printable Game*/ ) const = 0;
    /// Simple setter to output stream type.
    void setOutputStream(std::ostream& stream/** [in] is an output stream type*/){
        OutStream.copyfmt(stream);
    }
};


/// Renders the game to text
class HeroTextRenderer : public TextRenderer
{
public:
    /// This is a constructor 
    HeroTextRenderer(std::ostream& stream = std::cout/** [in] is an output stream type*/) : TextRenderer(stream) {}
    /// Render method
    void render(const Game& game/**[in] is a printable Game*/) const;
};
/// Renders the game to text
class ObserverTextRenderer : public TextRenderer
{
public:
    /// This is a constructor 
    ObserverTextRenderer(std::ostream& stream = std::cout/** [in] is an output stream type*/) : TextRenderer(stream) {}
    /// Render method
    void render(const Game& game/**[in] is a printable Game*/) const;
};
    