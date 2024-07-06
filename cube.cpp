#include "Cube.h"

void Cube::updateVertex()
{
    verts.resize(basicVerts.size());
    for (int i = 0; i < basicVerts.size(); i++)
    {
        Point3D rotatedVert = Matrix::getRotatedPos(basicVerts[i], Matrix::xRotation(15));
        std::cout << rotatedVert.x << " " << rotatedVert.y << " " << rotatedVert.z << std::endl;
        verts[i] = Matrix::addPoints(basicVerts[i], pos);
    }
}

void Cube::setPos(Point3D point3D)
{
    pos = point3D;
    updateVertex();
}

Cube::Cube(Coords coords, Renderer3D renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
    updateVertex();
}

void Cube::rotateX(float angle)
{
    angleX = angle;
    updateVertex();
}
