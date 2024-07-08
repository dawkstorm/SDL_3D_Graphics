#pragma once
#include "Shape.h"
class Cube : public Shape
{
private:
    void updateVertex();

public:
    Cube(Coords *coords, Renderer3D *renderer3D);
    Cube() = default;
    void setPos(vec3 point3D);
    void move(vec3 point3D);
    void rotate(vec3 rotation);
    const std::vector<vec3> basicVerts = {
        vec3(0, 1, 0), // Top front vertex
        vec3(0, 0, 0), // Bottom front vertex
        vec3(1, 0, 0), // Right front vertex
        vec3(0, 1, 0), // Top front vertex (repeated for the second triangle)
        vec3(1, 1, 0), // Top right vertex
        vec3(1, 0, 0), // Right front vertex (repeated for the second triangle)
        // First side (front face) completed

        vec3(1, 1, 0), // Top right vertex
        vec3(1, 0, 0), // Right front vertex
        vec3(1, 0, 1), // Right back vertex
        vec3(1, 1, 0), // Top right vertex (repeated for the second triangle)
        vec3(1, 1, 1), // Top back vertex
        vec3(1, 0, 1), // Right back vertex (repeated for the second triangle)
        // Second side (right face) completed

        vec3(0, 1, 1), // Top back vertex
        vec3(0, 1, 0), // Top right vertex
        vec3(1, 1, 0), // Top right vertex (repeated for the second triangle)
        vec3(0, 1, 1), // Top back vertex (repeated for the second triangle)
        vec3(1, 1, 1), // Top front vertex
        vec3(1, 1, 0), // Top back vertex (repeated for the second triangle)
        // Third side (top face) completed

        vec3(0, 1, 0), // Top right vertex
        vec3(0, 0, 0), // Right front vertex
        vec3(0, 0, 1), // Right back vertex
        vec3(0, 1, 0), // Top right vertex (repeated for the second triangle)
        vec3(0, 1, 1), // Top back vertex
        vec3(0, 0, 1), // Right back vertex (repeated for the second triangle)
        // Fifth side (left face) completed

        vec3(0, 1, 1), // Top front vertex
        vec3(0, 0, 1), // Bottom front vertex
        vec3(1, 0, 1), // Right front vertex
        vec3(0, 1, 1), // Top front vertex (repeated for the second triangle)
        vec3(1, 1, 1), // Top right vertex
        vec3(1, 0, 1), // Right front vertex (repeated for the second triangle)
        // Fourth side (back face) completed

        vec3(0, 0, 1), // Top back vertex
        vec3(0, 0, 0), // Top right vertex
        vec3(1, 0, 0), // Top right vertex (repeated for the second triangle)
        vec3(0, 0, 1), // Top back vertex (repeated for the second triangle)
        vec3(1, 0, 1), // Top front vertex
        vec3(1, 0, 0), // Top back vertex (repeated for the second triangle)
        // Sixth side (bottom face) completed

    };
};