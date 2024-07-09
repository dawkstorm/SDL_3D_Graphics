#pragma once
#include "Coords.h"
#include <SDL2/SDL.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

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
    void setOrthographicProjection(float left, float right, float top, float bottom, float near, float far);
    void setPerspectiveProjection(float fovy, float near, float far);
    Coords *coords;

public:
    const glm::mat4 &getProjectionMatrix() const
    {
        return projectionMatrix;
    }
    float focalLength;
    Renderer3D(float cd, Coords *coords);
    Renderer3D() = default;
    vec2 getProjectedPoint(vec3 point3D);
    vec3 cameraPos;
};