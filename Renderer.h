#pragma once
#include "Coords.h"
#include <SDL2/SDL.h>

struct vec3
{
    float x;
    float y;
    float z;
    vec3(float x = 0.f, float y = 0.f, float z = 0.f);
};

class Renderer3D
{
private:
    float near;
    float far;

public:
    Coords coords;
    float focalLength;
    Renderer3D(float cd, Coords &coords);
    Renderer3D() = default;
    vec2 getProjectedPoint(vec3 point3D);
};