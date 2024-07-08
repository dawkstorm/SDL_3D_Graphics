#include "Shape.h"
#include "Renderer.h"
#include <SDL2/SDL.h>

vec3::vec3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Renderer3D::Renderer3D(float cd, Coords &coords)
{
    focalLength = cd;
    this->coords = coords;
}

vec2 Renderer3D::getProjectedPoint(vec3 point3D)
{
    vec2 projected;
    projected.x = (point3D.x * focalLength) / (point3D.z + focalLength);
    projected.y = (point3D.y * focalLength) / (point3D.z + focalLength);
    return projected;
}