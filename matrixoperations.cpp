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

Vector3 Matrix::getRotatedPos(Vector3 vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix)
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
    Vector3 newPos(rslt[0], rslt[1], rslt[2]);
    return newPos;
}

Vector3 Matrix::addVectors(Vector3 p1, Vector3 p2)
{
    Vector3 sum(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
    return sum;
}