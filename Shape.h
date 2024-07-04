#pragma once
#include "Renderer.h"
#include <SDL2/SDL.h>
class Shape
{
private:
    Renderer3D renderer3D;

public:
    Shape();
    Point3D position;
    Point3D size;
    std::vector<Point3D> verts;
    virtual void setPos();
    virtual void setSize();
};
