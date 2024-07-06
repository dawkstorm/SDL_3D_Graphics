#pragma once
#include "Renderer.h"
class Matrix
{
private:
public:
    static std::array<std::array<float, 3>, 3> xRotation(float angle);
    static Point3D getRotatedPos(Point3D vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix);
    static Point3D addPoints(Point3D p1, Point3D p2);
};
