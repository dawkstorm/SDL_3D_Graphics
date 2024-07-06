#pragma once
#include "Coords.h"
#include <SDL2/SDL.h>

struct Vector3
{
    float x;
    float y;
    float z;
    Vector3(float x = 0.f, float y = 0.f, float z = 0.f);
};

class Renderer3D
{
private:
public:
    Coords coords;
    float focalLength;
    Renderer3D(float cd, Coords coords);
    Renderer3D() = default;
    Vector2 getProjectedPoint(Vector3 point3D);
};