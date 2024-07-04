#pragma once
#include "coords.h"

struct Point3D
{
    float x;
    float y;
    float z;
};

extern float canvasDistance;

class Renderer3D
{
public:
    void render();
    static float canvasDistance;

private:
    Point2D getProjectedPoint(Point3D point3D);
};