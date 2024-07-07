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
    Vector3 pos;
    Vector3 size;
    Vector3 rotation;
    Vector3 pivot;
    std::vector<Vector3> verts;
    std::vector<Vector3> edges;
    std::vector<SDL_Vertex> get2DVerticies(SDL_Color &color);
    std::vector<SDL_Point> get2DVertsPoints();
};
