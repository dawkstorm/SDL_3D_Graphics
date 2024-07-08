#pragma once
#include "Renderer.h"
#include <glm/glm.hpp>
class Matrix
{
private:
public:
    static std::array<std::array<float, 3>, 3> xRotation(float angle);
    static std::array<std::array<float, 3>, 3> yRotation(float angle);
    static std::array<std::array<float, 3>, 3> zRotation(float angle);

    static vec3 getRotatedPos(vec3 vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix);
    static vec3 addVectors(vec3 p1, vec3 p2);
    static vec3 subtractVectors(vec3 p1, vec3 p2);
};
