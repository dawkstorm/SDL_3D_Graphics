#pragma once
#include "Renderer.h"
#include <glm/glm.hpp>
class Matrix
{
private:
public:
    /// @brief Get X Rotation Matrix
    /// @param angle Angle
    static std::array<std::array<float, 3>, 3> xRotation(float angle);

    /// @brief Get Y Rotation Matrix
    /// @param angle Angle
    static std::array<std::array<float, 3>, 3> yRotation(float angle);

    /// @brief Get Z Rotation Matrix
    /// @param angle Angle
    static std::array<std::array<float, 3>, 3> zRotation(float angle);

    /// @brief Get Rotated position
    /// @param rotMatrix Rotation Matrix
    static vec3 getRotatedPos(vec3 vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix);

    /// @brief Add vectors
    /// @param p1 First vector
    /// @param p2 Second vector
    /// @return Sum
    static vec3 addVectors(vec3 p1, vec3 p2);

    /// @brief Subtract vectors
    /// @param p1 First vector
    /// @param p2 Second vector
    /// @return Difference
    static vec3 subtractVectors(vec3 p1, vec3 p2);

    /// @brief Element-wise multiplication
    /// @param p1 First vector
    /// @param p2 Second vector
    /// @return Product
    static vec3 multiplyElements(vec3 p1, vec3 p2);

    /// @brief Multiply vector by scalar
    /// @param p Vector
    /// @param s Scalar value
    /// @return Product
    static vec3 scalarMultiply(vec3 p, float s);

    /// @brief Get cross product
    /// @param p1 First vector
    /// @param p2 Second vector
    /// @return Cross product
    static vec3 crossProduct(vec3 p1, vec3 p2);

    /// @brief Get dot product
    /// @param p1 First vector
    /// @param p2 Second vector
    /// @return Dot product
    static float dotProduct(vec3 p1, vec3 p2);

    /// @brief Get length of a vector
    /// @param p Vector
    /// @return Length
    static float getLength(vec3 p);

    /// @brief Normalize vector
    /// @param p Vector
    static void normalize(vec3 *p);
};
