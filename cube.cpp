#include "Cube.h"

void Cube::updateVertex()
{
    verts.resize(basicVerts.size());
    for (int i = 0; i < basicVerts.size(); i++)
    {
        Vector3 rotatedVert = Matrix::getRotatedPos(basicVerts[i], Matrix::xRotation(rotation.x));
        std::cout << rotatedVert.x << " " << rotatedVert.y << " " << rotatedVert.z << std::endl;
        verts[i] = Matrix::addPoints(rotatedVert, pos);
    }
}

void Cube::setPos(Vector3 point3D)
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

void Cube::rotate(Vector3 rotation)
{
    this->rotation = Matrix::addPoints(this->rotation, rotation);
    updateVertex();
}
