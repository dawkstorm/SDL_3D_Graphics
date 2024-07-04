#include "renderer.h"

int canvasDistance = 1.f;

Point2D Renderer3D::getProjectedPoint(Point3D point3D)
{
    Point2D projected;
    projected.x = (point3D.x * canvasDistance) / (point3D.z + canvasDistance);
    projected.y = (point3D.y * canvasDistance) / (point3D.z + canvasDistance);
    return projected;
}