#pragma once
#include "Renderer.h"
#include "Coords.h"
#include <SDL2/SDL.h>
#include "MatrixOperations.h"
#include <array>

class Shape
{
protected:
    Coords *coords;
    Renderer3D *renderer3D;
    /// @brief Check if face faces
    /// @param tri1 First vert
    /// @param tri2 Second vert
    /// @param tri3 Third vert
    /// @return True or false
    bool isFrontFacing(const vec3 &tri1, const vec3 &tri2, const vec3 &tri3);

public:
    /// @brief Constructor
    /// @param coords Coordinate system reference
    /// @param renderer3D Renderer3D reference
    Shape(Coords *coords, Renderer3D *renderer3D);
    Shape() = default;

    /// @brief update verticies after transformation
    void updateVertex();

    /// @brief Position of the object
    vec3 pos;

    /// @brief Size of the object
    vec3 size = {1, 1, 1};

    /// @brief Current angles rotation of the object
    vec3 rotation;

    /// @brief Pivot of the object
    vec3 pivot;

    /// @brief Verticies of the object
    std::vector<vec3> verts;

    /// @brief Initial verticies of the object
    std::vector<vec3> basicVerts;

    /// @brief Renders the object
    /// @param renderer
    /// @param color
    void render(SDL_Renderer *renderer, const SDL_Color &color);

    /// @brief Renders a separate triangle
    /// @param renderer SDL renderer reference
    /// @param tri1 First vert
    /// @param tri2 Second vert
    /// @param tri3 Third vert
    /// @param color Color of the triagle
    void renderTriangle(SDL_Renderer *renderer, const vec3 &tri1, const vec3 &tri2, const vec3 &tri3, const SDL_Color &color);

    /// @brief Set position of the object
    /// @param point3D Point in the space
    void setPos(vec3 point3D);

    /// @brief Set size of the object
    /// @param size Desired size
    void setSize(vec3 size);

    /// @brief Set pivot of the object
    /// @param point3D Point in the space
    void setPivot(vec3 point3D);

    /// @brief Move the object
    /// @param direction Direction of movement
    void move(vec3 direction);

    /// @brief Rotate the object
    /// @param rotation Angles to rotate by
    void rotate(vec3 rotation);
};
