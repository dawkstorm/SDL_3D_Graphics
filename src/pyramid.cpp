#include "headers/Pyramid.h"

Pyramid::Pyramid(Coords *coords, Renderer3D *renderer3D)
{
    basicVerts = {
        vec3(0, 0, 1),
        vec3(1, 0, 1),
        vec3(1, 0, 0),
        vec3(1, 0, 0),
        vec3(0, 0, 0),
        vec3(0, 0, 1),
        // Bottom side

        vec3(0, 0, 1),
        vec3(0.5f, 1, 0.5f),
        vec3(1, 0, 1),

        vec3(1, 0, 0),
        vec3(0.5f, 1, 0.5f),
        vec3(0, 0, 0),

        vec3(0, 0, 0),
        vec3(0.5f, 1, 0.5f),
        vec3(0, 0, 1),

        vec3(1, 0, 1),
        vec3(0.5f, 1, 0.5f),
        vec3(1, 0, 0),
    };
    this->coords = coords;
    this->renderer3D = renderer3D;
    pivot = vec3(0.5f, 0.f, 0.5f);
    updateVertex();
}