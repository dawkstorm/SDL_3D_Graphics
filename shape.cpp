#include "Shape.h"
#include <iostream>

Shape::Shape(Coords *coords, Renderer3D *renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
}

vec3 multiplyByRotationVectors(vec3 vert, vec3 &rot)
{
    auto result = Matrix::getRotatedPos(vert, Matrix::xRotation(rot.x));
    result = Matrix::getRotatedPos(result, Matrix::yRotation(rot.y));
    result = Matrix::getRotatedPos(result, Matrix::zRotation(rot.z));
    return result;
}

void Shape::updateVertex()
{
    verts.resize(basicVerts.size());
    for (int i = 0; i < basicVerts.size(); i++)
    {
        vec3 vert = Matrix::subtractVectors(basicVerts[i], pivot);
        vert = Matrix::multiplyElements(vert, size);
        vert = multiplyByRotationVectors(vert, rotation);
        vert = Matrix::addVectors(vert, pos);
        vert = Matrix::subtractVectors(vert, renderer3D->cameraPos);
        verts[i] = vert;
    }
}

void Shape::render(SDL_Renderer *renderer, const SDL_Color &color)
{
    for (int i = 0; i < verts.size(); i += 3)
    {
        renderTriangle(renderer, verts[i], verts[i + 1], verts[i + 2], color);
    }
}

bool Shape::isFrontFacing(const vec3 &tri1, const vec3 &tri2, const vec3 &tri3)
{
    vec3 edge1 = Matrix::subtractVectors(tri2, tri1);
    vec3 edge2 = Matrix::subtractVectors(tri3, tri1);

    vec3 normal = Matrix::crossProduct(edge2, edge1);
    Matrix::normalize(&normal);

    vec3 cameraRay = Matrix::subtractVectors(renderer3D->cameraPos, tri1);
    float dotProduct = Matrix::dotProduct(normal, cameraRay);

    return dotProduct > 0.f;
}

void Shape::renderTriangle(SDL_Renderer *renderer, const vec3 &tri1, const vec3 &tri2, const vec3 &tri3, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    std::array<SDL_FPoint, 3> triangleVerts;
    triangleVerts[0] = coords->translateFromAbsoluteToPixels(renderer3D->getProjectedPoint(tri1));
    triangleVerts[1] = coords->translateFromAbsoluteToPixels(renderer3D->getProjectedPoint(tri2));
    triangleVerts[2] = coords->translateFromAbsoluteToPixels(renderer3D->getProjectedPoint(tri3));

    std::array<SDL_Vertex, 3> vertsArr;
    for (int i = 0; i < 3; i++)
    {
        Uint8 colorCooficient = 1;
        SDL_Color colorTest = {color.r - colorCooficient * i, color.g - colorCooficient * i, color.b - colorCooficient * i, color.a};
        vertsArr[i] = {
            triangleVerts[i], colorTest, SDL_FPoint{0}};
    }
    if (isFrontFacing(tri1, tri2, tri3))
    {
        SDL_RenderGeometry(renderer, nullptr, vertsArr.data(), vertsArr.size(), nullptr, 0);
    }
}

void Shape::setPos(vec3 point3D)
{
    pos = point3D;
    updateVertex();
}

void Shape::move(vec3 direction)
{
    Matrix::addVectors(pos, direction);
    updateVertex();
}

void Shape::setPivot(vec3 point3D)
{
    pivot = point3D;
    updateVertex();
}

void Shape::rotate(vec3 rot)
{
    this->rotation = Matrix::addVectors(this->rotation, rot);
    updateVertex();
}

void Shape::setSize(vec3 size)
{
    this->size = size;
    updateVertex();
}