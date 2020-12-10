#pragma once
#include "Renderer.h"

/// Renders the game to SVG 
class SVGRenderer : public Renderer {
protected:
    std::string Filename; ///< the output file's path 
    int elementSize = 10;///<the smallest prtintable unit's size
public:
    /// this is a constructor 
    SVGRenderer(const std::string& filename/** [in] is the output file's path */) : Filename(filename) {}
    /// render method
    virtual void render(const Game& game/**[in] is a printable Game*/) const = 0;
};

/// Renders the game to SVG 
class CharacterSVGRenderer : public SVGRenderer {
public:
    /// this is a constructor 
    CharacterSVGRenderer(const std::string& filename/** [in] is the output file's path*/) : SVGRenderer(filename) {}
    /// render method
    virtual void render(const Game& game/**[in]  is a printable Game*/) const;
};
/// Renders the game to SVG 
class ObserverSVGRenderer : public SVGRenderer {
public:
    ///this is a constructor
    ObserverSVGRenderer (const std::string& filename/** [in] is the output file's path*/) : SVGRenderer(filename) {}
    /// render method
    virtual void render(const Game& game/**[in] is  a printable Game*/) const;
};