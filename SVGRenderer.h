#pragma once
#include "Renderer.h"


class SVGRenderer : public Renderer {
protected:
    std::string Filename; /// the output stream's path 
    int elementSize = 40;
public:
    /// SVGRenderer constructor
    SVGRenderer(const std::string& filename/** [in] the output stream's path */) : Filename(filename) {}
    /// render method
    virtual void render(const Game& game/**[in] a printable Game*/) const = 0;
};


class CharacterSVGRenderer : public SVGRenderer {
public:
    /// CharacterSVGRenderer constructor
    CharacterSVGRenderer(const std::string& filename/** [in] the output stream's path*/) : SVGRenderer(filename) {}
    /// render method
    virtual void render(const Game& game/**[in]  a printable Game*/) const;
};

class ObserverSVGRenderer : public SVGRenderer {
public:
    /// ObserverSVGRenderer constructor
    ObserverSVGRenderer (const std::string& filename/** [in] the output stream's path*/) : SVGRenderer(filename) {}
    /// render method
    virtual void render(const Game& game/**[in]  a printable Game*/) const;
};