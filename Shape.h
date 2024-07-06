#pragma once
#include "Renderer.h"
#include "Coords.h"
#include <SDL2/SDL.h>
#include "MatrixOperations.h"
#include <array>

class Shape
{
protected:
    Coords coords;
    Renderer3D renderer3D;

public:
    Shape(Coords coords, Renderer3D renderer3D);
    Shape() = default;
    Point3D pos;
    Point3D size;
    std::vector<Point3D> verts;
    std::vector<Point3D> edges;
    std::vector<SDL_Vertex> get2DVerticies(SDL_Color &color);
    std::vector<SDL_Point> get2DVertsPoints();
};
