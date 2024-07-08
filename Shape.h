#pragma once
#include "Renderer.h"
#include "Coords.h"
#include <SDL2/SDL.h>
#include "MatrixOperations.h"
#include <array>

class Shape
{
protected:
    Coords *coords;
    Renderer3D *renderer3D;
    bool isFrontFacing(const vec3 &tri1, const vec3 &tri2, const vec3 &tri3);

public:
    Shape(Coords *coords, Renderer3D *renderer3D);
    Shape() = default;
    vec3 pos;
    vec3 size;
    vec3 rotation;
    vec3 pivot;
    std::vector<vec3> verts;
    std::vector<vec3> edges;
    std::vector<SDL_Vertex> get2DVerticies(SDL_Color &color);
    std::vector<SDL_Point> get2DVertsPoints();
    void renderVertecies(SDL_Renderer *renderer, const SDL_Color &color);
    void renderTriangle(SDL_Renderer *renderer, const vec3 &tri1, const vec3 &tri2, const vec3 &tri3, const SDL_Color &color);
};
