#include "Shape.h"
#include "Renderer.h"
#include <SDL2/SDL.h>

Point3D::Point3D(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Renderer3D::Renderer3D(float cd, Coords coords)
{
    focalLength = cd;
    this->coords = coords;
}

Point2D Renderer3D::getProjectedPoint(Point3D point3D)
{
    Point2D projected;
    projected.x = (point3D.x * focalLength) / (point3D.z + focalLength);
    projected.y = (point3D.y * focalLength) / (point3D.z + focalLength);
    return projected;
}