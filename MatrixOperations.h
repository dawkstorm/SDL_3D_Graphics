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
    /// @brief Element-wise multiplication
    /// @param p1 First vector
    /// @param p2 Second vector
    static vec3 multiplyElements(vec3 p1, vec3 p2);
    static vec3 scalarMultiply(vec3 p, float s);
    static vec3 crossProduct(vec3 p1, vec3 p2);
    static vec3 getNormal(vec3 p1, vec3 p2);
    static float dotProduct(vec3 p1, vec3 p2);
    static float getLength(vec3 p);
    static void normalize(vec3 *p);
};
