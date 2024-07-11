#pragma once
#include "Shape.h"
class Cube : public Shape
{
private:
public:
    /// @brief Cube constructor
    Cube(Coords *coords, Renderer3D *renderer3D);
    Cube() = default;
};