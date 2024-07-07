#include "Cube.h"

Vector3 multiplyByRotationVectors(Vector3 vert, Vector3 &rot)
{
    auto result = Matrix::getRotatedPos(vert, Matrix::xRotation(rot.x));
    result = Matrix::getRotatedPos(result, Matrix::yRotation(rot.y));
    result = Matrix::getRotatedPos(result, Matrix::zRotation(rot.z));
    return result;
}

void Cube::updateVertex()
{
    verts.resize(basicVerts.size());
    for (int i = 0; i < basicVerts.size(); i++)
    {
        Vector3 pivotedVert = Matrix::subtractVectors(basicVerts[i], pivot);
        Vector3 rotatedVert = multiplyByRotationVectors(pivotedVert, rotation);
        verts[i] = Matrix::addVectors(rotatedVert, pos);
    }
}

void Cube::setPos(Vector3 point3D)
{
    pos = point3D;
    updateVertex();
}
void Cube::move(Vector3 point3D)
{
    Matrix::addVectors(pos, point3D);
    updateVertex();
}

Cube::Cube(Coords coords, Renderer3D renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
    pivot = Vector3(0.5f, 0.5f, 0.5f);
    updateVertex();
}

void Cube::rotate(Vector3 rot)
{
    this->rotation = Matrix::addVectors(this->rotation, rot);
    updateVertex();
}
