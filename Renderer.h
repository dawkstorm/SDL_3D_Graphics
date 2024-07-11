#pragma once
#include "Coords.h"
#include <SDL2/SDL.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

/// @brief 3 dimensional vector
struct vec3
{
    float x;
    float y;
    float z;
    vec3(float x = 0.f, float y = 0.f, float z = 0.f);
};

class Renderer3D
{
private:
    float near;
    float far;
    glm::mat4 projectionMatrix{1.f};

    /// @brief Set orthographic projection matrix
    void setOrthographicProjection(float left, float right, float top, float bottom, float near, float far);

    /// @brief Set perspective projection matrix
    void setPerspectiveProjection(float fovy, float near, float far);
    Coords *coords;

public:
    /// @brief Get projection matrix
    const glm::mat4 &getProjectionMatrix() const
    {
        return projectionMatrix;
    }

    float focalLength;

    /// @brief Constructor
    /// @param cd Focal length
    /// @param coords Coordinate system reference
    Renderer3D(float cd, Coords *coords);
    Renderer3D() = default;

    /// @brief Project a 3d point on 2d plane
    /// @param point3D Point in 3D space
    vec2 getProjectedPoint(vec3 point3D);

    /// @brief Position of camera
    vec3 cameraPos;
};