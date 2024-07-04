#pragma once
#include "Shape.h"
class Cube : public Shape
{
private:
    void updateVertex();

public:
    Cube(Coords coords, Renderer3D renderer3D);
    Cube() = default;
    void setPos(Point3D point3D);
};