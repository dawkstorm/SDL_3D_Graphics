#pragma once
#include "Shape.h"
class Pyramid : public Shape
{
private:
public:
    /// @brief Pyramid constructor
    Pyramid(Coords *coords, Renderer3D *renderer3D);
    Pyramid() = default;
};