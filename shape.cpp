#include "Shape.h"
#include <iostream>

Shape::Shape(Coords *coords, Renderer3D *renderer3D)
{
    this->coords = coords;
    this->renderer3D = renderer3D;
}

std::vector<SDL_Vertex> Shape::get2DVerticies(SDL_Color &color)
{
    std::vector<SDL_Vertex> verticies;
    verticies.reserve(verts.size());
    Uint8 colour = 255;
    for (int i = 0; i < verts.size(); i++)
    {
        verticies.push_back(
            {
                coords->translateFromAbsoluteToPixels(renderer3D->getProjectedPoint(verts[i])),
                SDL_Color{colour, colour, colour, 255},
                SDL_FPoint{0},
            });
        colour -= 5.f;
    }
    return verticies;
}

std::vector<SDL_Point> Shape::get2DVertsPoints()
{
    std::vector<SDL_Point> verticies;
    verticies.reserve(verts.size());
    for (int i = 0; i < verts.size(); i++)
    {
        int pX = (int)coords->translateFromAbsoluteToPixels(renderer3D->getProjectedPoint(verts[i])).x;
        int pY = (int)coords->translateFromAbsoluteToPixels(renderer3D->getProjectedPoint(verts[i])).y;
        SDL_Point point = {pX, pY};
        verticies.push_back(point);
    }
    return verticies;
}

void Shape::renderVertecies(SDL_Renderer *renderer, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    // SDL_RenderDrawLines(renderer, get2DVertsPoints().data(), get2DVertsPoints().size());
    for (int i = 0; i < verts.size(); i += 3)
    {
        renderTriangle(renderer, verts[i], verts[i + 1], verts[i + 2], color);
    }
}

bool Shape::isFrontFacing(const vec3 &tri1, const vec3 &tri2, const vec3 &tri3)
{
    vec3 edge1 = Matrix::subtractVectors(tri2, tri1);
    vec3 edge2 = Matrix::subtractVectors(tri3, tri2);

    vec3 crossProduct = Matrix::crossProduct(edge1, edge2);

    return crossProduct.z > 0;
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
        Uint8 colorCooficient = 10;
        SDL_Color colorTest = {color.r - colorCooficient * i, color.g - colorCooficient * i, color.b - colorCooficient * i, color.a};
        vertsArr[i] = {
            triangleVerts[i], colorTest, SDL_FPoint{0}};
    }
    if (isFrontFacing(tri1, tri2, tri3))
    {
        SDL_RenderGeometry(renderer, nullptr, vertsArr.data(), vertsArr.size(), nullptr, 0);
        SDL_RenderDrawLinesF(renderer, triangleVerts.data(), triangleVerts.size());
    }
}