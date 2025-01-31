#include "headers/Shape.h"
#include "headers/Renderer.h"
#include <SDL2/SDL.h>
#include <cassert>
#include <limits>

vec3::vec3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Renderer3D::Renderer3D(float cd, Coords *coords)
{
    focalLength = cd;
    this->coords = coords;
    cameraPos = {0, 0, 0};
    // setOrthographicProjection(-1, 1, -1, 1, -1, 1);
    setPerspectiveProjection(glm::radians(45.f), coords->getAspectRatioHW(), 0.01f, 1000.f);
}

void Renderer3D::setOrthographicProjection(float left, float right, float top, float bottom, float near, float far)
{
    projectionMatrix = glm::mat4{1.0f};
    projectionMatrix[0][0] = 2.f / (right - left);
    projectionMatrix[1][1] = 2.f / (bottom - top);
    projectionMatrix[2][2] = 1.f / (far - near);
    projectionMatrix[3][0] = -(right + left) / (right - left);
    projectionMatrix[3][1] = -(bottom + top) / (bottom - top);
    projectionMatrix[3][2] = -near / (far - near);
}

void Renderer3D::setPerspectiveProjection(float fovy, float aspect, float near, float far)
{
    assert(glm::abs(aspect - std::numeric_limits<float>::epsilon()) > 0.0f);
    const float tanHalfFovy = tan(fovy * aspect / 2.f);
    projectionMatrix = glm::mat4{0.0f};
    projectionMatrix[0][0] = 1.f / (1 * tanHalfFovy);
    projectionMatrix[1][1] = 1.f / (tanHalfFovy);
    projectionMatrix[2][2] = far / (far - near);
    projectionMatrix[2][3] = 1.f;
    projectionMatrix[3][2] = -(far * near) / (far - near);
}

vec2 Renderer3D::getProjectedPoint(vec3 point3D)
{
    vec2 projected;
    glm::vec4 point = {point3D.x, point3D.y, point3D.z, 1};

    auto proj = getProjectionMatrix() * point;
    projected.x = proj[0] / proj[3];
    projected.y = proj[1] / proj[3];
    return projected;
}