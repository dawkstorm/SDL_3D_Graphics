#include "Cube.h"

void Cube::updateVertex()
{
    verts = {
        Point3D(0 + position.x, 1 + position.y, 0 + position.z), // Top front vertex
        Point3D(0 + position.x, 0 + position.y, 0 + position.z), // Bottom front vertex
        Point3D(1 + position.x, 0 + position.y, 0 + position.z), // Right front vertex
        Point3D(0 + position.x, 1 + position.y, 0 + position.z), // Top front vertex (repeated for the second triangle)
        Point3D(1 + position.x, 1 + position.y, 0 + position.z), // Top right vertex
        Point3D(1 + position.x, 0 + position.y, 0 + position.z), // Right front vertex (repeated for the second triangle)
        // First side (front face) completed

        Point3D(1 + position.x, 1 + position.y, 0 + position.z), // Top right vertex
        Point3D(1 + position.x, 0 + position.y, 0 + position.z), // Right front vertex
        Point3D(1 + position.x, 0 + position.y, 1 + position.z), // Right back vertex
        Point3D(1 + position.x, 1 + position.y, 0 + position.z), // Top right vertex (repeated for the second triangle)
        Point3D(1 + position.x, 1 + position.y, 1 + position.z), // Top back vertex
        Point3D(1 + position.x, 0 + position.y, 1 + position.z), // Right back vertex (repeated for the second triangle)
        // Second side (right face) completed

        Point3D(0 + position.x, 1 + position.y, 1 + position.z), // Top back vertex
        Point3D(0 + position.x, 1 + position.y, 0 + position.z), // Top right vertex
        Point3D(1 + position.x, 1 + position.y, 0 + position.z), // Top right vertex (repeated for the second triangle)
        Point3D(0 + position.x, 1 + position.y, 1 + position.z), // Top back vertex (repeated for the second triangle)
        Point3D(1 + position.x, 1 + position.y, 1 + position.z), // Top front vertex
        Point3D(1 + position.x, 1 + position.y, 0 + position.z), // Top back vertex (repeated for the second triangle)
        // Third side (top face) completed

        Point3D(0 + position.x, 1 + position.y, 1 + position.z), // Top front vertex
        Point3D(0 + position.x, 0 + position.y, 1 + position.z), // Bottom front vertex
        Point3D(1 + position.x, 0 + position.y, 1 + position.z), // Right front vertex
        Point3D(0 + position.x, 1 + position.y, 1 + position.z), // Top front vertex (repeated for the second triangle)
        Point3D(1 + position.x, 1 + position.y, 1 + position.z), // Top right vertex
        Point3D(1 + position.x, 0 + position.y, 1 + position.z), // Right front vertex (repeated for the second triangle)
        // Fourth side (back face) completed

        Point3D(0 + position.x, 1 + position.y, 0 + position.z), // Top right vertex
        Point3D(0 + position.x, 0 + position.y, 0 + position.z), // Right front vertex
        Point3D(0 + position.x, 0 + position.y, 1 + position.z), // Right back vertex
        Point3D(0 + position.x, 1 + position.y, 0 + position.z), // Top right vertex (repeated for the second triangle)
        Point3D(0 + position.x, 1 + position.y, 1 + position.z), // Top back vertex
        Point3D(0 + position.x, 0 + position.y, 1 + position.z), // Right back vertex (repeated for the second triangle)
        // Fifth side (left face) completed

        Point3D(0 + position.x, 0 + position.y, 1 + position.z), // Top back vertex
        Point3D(0 + position.x, 0 + position.y, 0 + position.z), // Top right vertex
        Point3D(1 + position.x, 0 + position.y, 0 + position.z), // Top right vertex (repeated for the second triangle)
        Point3D(0 + position.x, 0 + position.y, 1 + position.z), // Top back vertex (repeated for the second triangle)
        Point3D(1 + position.x, 0 + position.y, 1 + position.z), // Top front vertex
        Point3D(1 + position.x, 0 + position.y, 0 + position.z), // Top back vertex (repeated for the second triangle)
    };
}

void Cube::setPos(Point3D point3D)
{
    position = point3D;
    updateVertex();
}

Cube::Cube(Coords coords, Renderer3D renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
    updateVertex();
}
