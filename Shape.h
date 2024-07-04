#pragma once
#include "Renderer.h"
#include "Coords.h"
#include <SDL2/SDL.h>

class Shape
{
protected:
    Coords coords;
    Renderer3D renderer3D;

public:
    Shape(Coords coords, Renderer3D renderer3D);
    Shape() = default;
    Point3D position;
    Point3D size;
    std::vector<Point3D> verts;
    std::vector<SDL_Vertex> get2DVerticies();
    std::vector<SDL_Point> get2DEdges();
};
