#pragma once
#include "Renderer.h"
class Matrix
{
private:
public:
    static std::array<std::array<float, 3>, 3> xRotation(float angle);
    static std::array<std::array<float, 3>, 3> yRotation(float angle);
    static std::array<std::array<float, 3>, 3> zRotation(float angle);
    static Vector3 getRotatedPos(Vector3 vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix);
    static Vector3 addVectors(Vector3 p1, Vector3 p2);
    static Vector3 subtractVectors(Vector3 p1, Vector3 p2);
};
