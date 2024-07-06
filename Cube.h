#pragma once
#include "Shape.h"
class Cube : public Shape
{
private:
    void updateVertex();

public:
    Cube(Coords coords, Renderer3D renderer3D);
    Cube() = default;
    void setPos(Vector3 point3D);
    void move(Vector3 point3D);
    void rotate(Vector3 rotation);
    const std::vector<Vector3> basicVerts = {
        Vector3(0, 1, 0), // Top front vertex
        Vector3(0, 0, 0), // Bottom front vertex
        Vector3(1, 0, 0), // Right front vertex
        Vector3(0, 1, 0), // Top front vertex (repeated for the second triangle)
        Vector3(1, 1, 0), // Top right vertex
        Vector3(1, 0, 0), // Right front vertex (repeated for the second triangle)
        // First side (front face) completed

        Vector3(1, 1, 0), // Top right vertex
        Vector3(1, 0, 0), // Right front vertex
        Vector3(1, 0, 1), // Right back vertex
        Vector3(1, 1, 0), // Top right vertex (repeated for the second triangle)
        Vector3(1, 1, 1), // Top back vertex
        Vector3(1, 0, 1), // Right back vertex (repeated for the second triangle)
        // Second side (right face) completed

        Vector3(0, 1, 1), // Top back vertex
        Vector3(0, 1, 0), // Top right vertex
        Vector3(1, 1, 0), // Top right vertex (repeated for the second triangle)
        Vector3(0, 1, 1), // Top back vertex (repeated for the second triangle)
        Vector3(1, 1, 1), // Top front vertex
        Vector3(1, 1, 0), // Top back vertex (repeated for the second triangle)
        // Third side (top face) completed

        Vector3(0, 1, 0), // Top right vertex
        Vector3(0, 0, 0), // Right front vertex
        Vector3(0, 0, 1), // Right back vertex
        Vector3(0, 1, 0), // Top right vertex (repeated for the second triangle)
        Vector3(0, 1, 1), // Top back vertex
        Vector3(0, 0, 1), // Right back vertex (repeated for the second triangle)
        // Fifth side (left face) completed

        Vector3(0, 1, 1), // Top front vertex
        Vector3(0, 0, 1), // Bottom front vertex
        Vector3(1, 0, 1), // Right front vertex
        Vector3(0, 1, 1), // Top front vertex (repeated for the second triangle)
        Vector3(1, 1, 1), // Top right vertex
        Vector3(1, 0, 1), // Right front vertex (repeated for the second triangle)
        // Fourth side (back face) completed

        Vector3(0, 0, 1), // Top back vertex
        Vector3(0, 0, 0), // Top right vertex
        Vector3(1, 0, 0), // Top right vertex (repeated for the second triangle)
        Vector3(0, 0, 1), // Top back vertex (repeated for the second triangle)
        Vector3(1, 0, 1), // Top front vertex
        Vector3(1, 0, 0), // Top back vertex (repeated for the second triangle)
        // Sixth side (bottom face) completed

    };
};