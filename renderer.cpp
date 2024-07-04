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
    canvasDistance = cd;
    this->coords = coords;
}

Point2D Renderer3D::getProjectedPoint(Point3D point3D)
{
    Point2D projected;
    projected.x = (point3D.x * canvasDistance) / (point3D.z + canvasDistance);
    projected.y = (point3D.y * canvasDistance) / (point3D.z + canvasDistance);
    return projected;
}