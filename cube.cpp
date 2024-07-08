#include "Cube.h"

vec3 multiplyByRotationVectors(vec3 vert, vec3 &rot)
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
        vec3 pivotedVert = Matrix::subtractVectors(basicVerts[i], pivot);
        vec3 rotatedVert = multiplyByRotationVectors(pivotedVert, rotation);
        verts[i] = Matrix::addVectors(rotatedVert, pos);
    }
}

void Cube::setPos(vec3 point3D)
{
    pos = point3D;
    updateVertex();
}
void Cube::move(vec3 point3D)
{
    Matrix::addVectors(pos, point3D);
    updateVertex();
}

Cube::Cube(Coords *coords, Renderer3D *renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
    pivot = vec3(0.5f, 0.5f, 0.5f);
    updateVertex();
}

void Cube::rotate(vec3 rot)
{
    this->rotation = Matrix::addVectors(this->rotation, rot);
    updateVertex();
}
