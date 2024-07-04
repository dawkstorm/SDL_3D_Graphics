#pragma once
#include "Coords.h"
#include <SDL2/SDL.h>

struct Point3D
{
    float x;
    float y;
    float z;
    Point3D(float x = 0.f, float y = 0.f, float z = 0.f);
};

class Renderer3D
{
private:
public:
    Coords coords;
    float canvasDistance;
    Renderer3D(float cd, Coords coords);
    Renderer3D() = default;
    Point2D getProjectedPoint(Point3D point3D);
};