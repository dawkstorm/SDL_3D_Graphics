#include "MatrixOperations.h"
#include <array>

std::array<std::array<float, 3>, 3> Matrix::xRotation(float angle)
{
    std::array<std::array<float, 3>, 3> matrix = {{{1, 0, 0},
                                                   {0, cos(angle), -sin(angle)},
                                                   {0, sin(angle), cos(angle)}}};
    return matrix;
}

Point3D Matrix::getRotatedPos(Point3D vertPos, const std::array<std::array<float, 3>, 3> &rotMatrix)
{
    int posArr[3] = {{vertPos.x}, {vertPos.y}, {vertPos.z}};
    int rslt[3];
    for (int i = 0; i < 3; i++)
    {
        rslt[i] = 0;
        for (int k = 0; k < 3; k++)
        {
            rslt[i] += rotMatrix[i][k] * posArr[k];
        }
    }
    Point3D newPos(rslt[0], rslt[1], rslt[2]);
    return newPos;
}

Point3D Matrix::addPoints(Point3D p1, Point3D p2)
{
    Point3D sum(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
    return sum;
}