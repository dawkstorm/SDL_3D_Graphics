#include "Cube.h"
Cube::Cube()
{
    verts = {
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

        Point3D(1, 1, 1), // Top back vertex
        Point3D(1, 0, 1), // Right back vertex
        Point3D(0, 0, 1), // Bottom back vertex
        Point3D(1, 1, 1), // Top back vertex (repeated for the second triangle)
        Point3D(0, 1, 1), // Top left vertex
        Point3D(0, 0, 1), // Bottom back vertex (repeated for the second triangle)
        // Third side (back face) completed

        Point3D(0, 1, 1),  // Top left vertex
        Point3D(0, 0, 1),  // Bottom back vertex
        Point3D(-1, 0, 1), // Left back vertex
        Point3D(0, 1, 1),  // Top left vertex (repeated for the second triangle)
        Point3D(-1, 1, 1), // Top left vertex
        Point3D(-1, 0, 1), // Left back vertex (repeated for the second triangle)
        // Fourth side (left face) completed

        Point3D(-1, 1, 1), // Top left vertex
        Point3D(-1, 0, 1), // Left back vertex
        Point3D(-1, 0, 0), // Left front vertex
        Point3D(-1, 1, 1), // Top left vertex (repeated for the second triangle)
        Point3D(-1, 1, 0), // Top front vertex
        Point3D(-1, 0, 0), // Left front vertex (repeated for the second triangle)
        // Fifth side (left face) completed

        Point3D(-1, 1, 0), // Top front vertex
        Point3D(-1, 0, 0), // Left front vertex
        Point3D(0, 0, 0),  // Bottom front vertex
        Point3D(-1, 1, 0), // Top front vertex (repeated for the second triangle)
        Point3D(0, 1, 0),  // Top front vertex
        Point3D(0, 0, 0),  // Bottom front vertex (repeated for the second triangle)
        // Sixth side (bottom face) completed
    };
}
