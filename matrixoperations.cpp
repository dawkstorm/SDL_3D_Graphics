#include "MatrixOperations.h"
#include <array>

std::array<std::array<float, 3>, 3> Matrix::xRotation(float angle)
{
    std::array<std::array<float, 3>, 3> matrix = {{{1, 0, 0},
                                                   {0, cos(angle), -sin(angle)},
                                                   {0, sin(angle), cos(angle)}}};
    return matrix;
}

std::array<std::array<float, 3>, 3> Matrix::yRotation(float angle)
{
    std::array<std::array<float, 3>, 3> matrix = {{{cos(angle), 0, sin(angle)},
                                                   {0, 1, 0},
                                                   {-sin(angle), 0, cos(angle)}}};
    return matrix;
}

std::array<std::array<float, 3>, 3> Matrix::zRotation(float angle)
{
    std::array<std::array<float, 3>, 3> matrix = {{{cos(angle), -sin(angle), 0},
                                                   {sin(angle), cos(angle), 0},
                                                   {0, 0, 1}}};
    return matrix;
}

vec3 Matrix::getRotatedPos(vec3 vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix)
{
    float posArr[3] = {{vertPos.x}, {vertPos.y}, {vertPos.z}};
    float rslt[3];
    for (int i = 0; i < 3; i++)
    {
        rslt[i] = 0;
        for (int k = 0; k < 3; k++)
        {
            rslt[i] += rotMatrix[i][k] * posArr[k];
        }
    }
    vec3 newPos(rslt[0], rslt[1], rslt[2]);
    return newPos;
}

vec3 Matrix::addVectors(vec3 p1, vec3 p2)
{
    vec3 sum(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
    return sum;
}

vec3 Matrix::subtractVectors(vec3 p1, vec3 p2)
{
    vec3 sum(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
    return sum;
}

vec3 Matrix::multiplyElements(vec3 p1, vec3 p2)
{
    vec3 product(p1.x * p2.x, p1.y * p2.y, p1.z * p2.z);
    return product;
}

vec3 Matrix::scalarMultiply(vec3 p, float s)
{
    vec3 product(p.x * s, p.y * s, p.z * s);
    return product;
}

vec3 Matrix::crossProduct(vec3 p1, vec3 p2)
{
    glm::vec3 a = {p1.x, p1.y, p1.z};
    glm::vec3 b = {p2.x, p2.y, p2.z};
    auto product = glm::cross(a, b);
    vec3 result(product.x, product.y, product.z);
    return result;
}

vec3 Matrix::getNormal(vec3 p1, vec3 p2)
{
    vec3 result;
    result.x = p1.y * p2.z - p1.y * p2.z;
    result.y = p1.x * p2.z - p1.x * p2.z;
    result.z = p1.x * p2.y - p1.x * p2.y;
    return result;
}

float Matrix::dotProduct(vec3 p1, vec3 p2)
{
    float result = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
    return result;
}

float Matrix::getLength(vec3 p)
{
    float result = std::sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
    return result;
}

void Matrix::normalize(vec3 *p)
{
    float l = getLength(*p);
    p->x /= l;
    p->y /= l;
    p->z /= l;
}