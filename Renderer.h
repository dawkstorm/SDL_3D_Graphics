#pragma once
#include "Coords.h"

struct Point3D
{
    float x;
    float y;
    float z;
    Point3D(float x = 0.f, float y = 0.f, float z = 0.f);
};

class Renderer3D
{
public:
    float canvasDistance;
    void render();
    Renderer3D(float cd);
    Point2D getProjectedPoint(Point3D point3D);

private:
};