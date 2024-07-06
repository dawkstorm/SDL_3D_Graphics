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
    void rotateX(float angle);
    float angleX;
    const std::vector<Point3D> basicVerts = {
        Point3D(0, 1, 0), // Top front vertex
        Point3D(0, 0, 0), // Bottom front vertex
        Point3D(1, 0, 0), // Right front vertex
        Point3D(0, 1, 0), // Top front vertex (repeated for the second triangle)
        Point3D(1, 1, 0), // Top right vertex
        Point3D(1, 0, 0), // Right front vertex (repeated for the second triangle)
        // First side (front face) completed

        Point3D(1, 1, 0), // Top right vertex
        Point3D(1, 0, 0), // Right front vertex
        Point3D(1, 0, 1), // Right back vertex
        Point3D(1, 1, 0), // Top right vertex (repeated for the second triangle)
        Point3D(1, 1, 1), // Top back vertex
        Point3D(1, 0, 1), // Right back vertex (repeated for the second triangle)
        // Second side (right face) completed

        Point3D(0, 1, 1), // Top back vertex
        Point3D(0, 1, 0), // Top right vertex
        Point3D(1, 1, 0), // Top right vertex (repeated for the second triangle)
        Point3D(0, 1, 1), // Top back vertex (repeated for the second triangle)
        Point3D(1, 1, 1), // Top front vertex
        Point3D(1, 1, 0), // Top back vertex (repeated for the second triangle)
        // Third side (top face) completed

        Point3D(0, 1, 0), // Top right vertex
        Point3D(0, 0, 0), // Right front vertex
        Point3D(0, 0, 1), // Right back vertex
        Point3D(0, 1, 0), // Top right vertex (repeated for the second triangle)
        Point3D(0, 1, 1), // Top back vertex
        Point3D(0, 0, 1), // Right back vertex (repeated for the second triangle)
        // Fifth side (left face) completed

        Point3D(0, 1, 1), // Top front vertex
        Point3D(0, 0, 1), // Bottom front vertex
        Point3D(1, 0, 1), // Right front vertex
        Point3D(0, 1, 1), // Top front vertex (repeated for the second triangle)
        Point3D(1, 1, 1), // Top right vertex
        Point3D(1, 0, 1), // Right front vertex (repeated for the second triangle)
        // Fourth side (back face) completed

        Point3D(0, 0, 1), // Top back vertex
        Point3D(0, 0, 0), // Top right vertex
        Point3D(1, 0, 0), // Top right vertex (repeated for the second triangle)
        Point3D(0, 0, 1), // Top back vertex (repeated for the second triangle)
        Point3D(1, 0, 1), // Top front vertex
        Point3D(1, 0, 0), // Top back vertex (repeated for the second triangle)
        // Sixth side (bottom face) completed

    };
};