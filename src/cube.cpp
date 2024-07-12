#include "headers/Cube.h"

Cube::Cube(Coords *coords, Renderer3D *renderer3D)
{
    basicVerts = {
        vec3(0, 1, 0), // Top front vertex
        vec3(0, 0, 0), // Bottom front vertex
        vec3(1, 0, 0), // Right front vertex
        vec3(1, 0, 0), // Top front vertex (repeated for the second triangle)
        vec3(1, 1, 0), // Top right vertex
        vec3(0, 1, 0), // Right front vertex (repeated for the second triangle)
                       // Front side
        vec3(1, 1, 0),
        vec3(1, 0, 0),
        vec3(1, 0, 1),
        vec3(1, 0, 1),
        vec3(1, 1, 1),
        vec3(1, 1, 0),
        // Right side

        vec3(0, 1, 1), // Top front vertex
        vec3(1, 1, 1), // Bottom front vertex
        vec3(1, 0, 1), // Right front vertex
        vec3(1, 0, 1), // Top front vertex (repeated for the second triangle)
        vec3(0, 0, 1), // Top right vertex
        vec3(0, 1, 1), // Right front vertex (repeated for the second triangle)
        // Back side

        vec3(0, 1, 0),
        vec3(0, 1, 1),
        vec3(0, 0, 1),
        vec3(0, 0, 1),
        vec3(0, 0, 0),
        vec3(0, 1, 0),
        // Right side

        vec3(0, 1, 1),
        vec3(0, 1, 0),
        vec3(1, 1, 0),
        vec3(1, 1, 0),
        vec3(1, 1, 1),
        vec3(0, 1, 1),
        // Top side

        vec3(0, 0, 1),
        vec3(1, 0, 1),
        vec3(1, 0, 0),
        vec3(1, 0, 0),
        vec3(0, 0, 0),
        vec3(0, 0, 1),
        // Bottom side
    };

    this->coords = coords;
    this->renderer3D = renderer3D;
    pivot = vec3(0.5f, 0.5f, 0.5f);
    updateVertex();
}