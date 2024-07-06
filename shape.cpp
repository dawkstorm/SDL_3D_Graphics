#include "Shape.h"
#include <iostream>

Shape::Shape(Coords coords, Renderer3D renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
}

std::vector<SDL_Vertex> Shape::get2DVerticies(SDL_Color &color)
{
    std::vector<SDL_Vertex> verticies;
    verticies.reserve(verts.size());
    Uint8 colour = 255;
    for (int i = 0; i < verts.size(); i++)
    {
        verticies.push_back(
            {
                coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(verts[i])),
                SDL_Color{colour, colour, colour, 255},
                SDL_FPoint{0},
            });
        colour -= 5.f;
    }
    return verticies;
}

std::vector<SDL_Point> Shape::get2DVertsPoints()
{
    std::vector<SDL_Point> verticies;
    verticies.reserve(verts.size());
    for (int i = 0; i < verts.size(); i++)
    {
        float pX = (int)coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(verts[i])).x;
        float pY = (int)coords.TranslateFromAbsoluteToPixels(renderer3D.getProjectedPoint(verts[i])).y;
        SDL_Point point = {pX, pY};
        verticies.push_back(point);
    }
    return verticies;
}