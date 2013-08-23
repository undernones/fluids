// License: See distributed LICENSE file.

#include "Grid.h"

Grid::Grid(int i, int j, int k, double h)
    : Grid(i, j, k, i * h, j * h, k * h, h)
{
}

Grid::Grid(unsigned i, unsigned j, unsigned k, double h)
    : Grid(i, j, k, i * h, j * h, k * h, h)
{
}

Grid::Grid(double x, double y, double z, double h)
    : Grid(static_cast<unsigned>(x / h),
           static_cast<unsigned>(y / h),
           static_cast<unsigned>(z / h),
           x, y, z, h)
{
}

Grid::Grid(unsigned i, unsigned j, unsigned k,
           double x, double y, double z, double h)
    : mPressures(i, j, k)
    , mVelocities(i, j, k)
    , mWidth(x)
    , mHeight(y)
    , mDepth(z)
    , mH(h)
{
}

double
Grid::pressure(int i, int j, int k) const
{
    // TODO: boundary check
    return mPressures(i, j, k);
}

double
Grid::pressure(double x, double y, double z) const
{
    // TODO: boundary check
    return 0;
}

const Eigen::Vector3d&
Grid::velocity(int i, int j, int k) const
{
    // TODO: boundary check
    return mVelocities(i, j, k);
}

const Eigen::Vector3d&
Grid::velocity(double x, double y, double z) const
{
    // TODO: boundary check
    return mVelocities(0, 0, 0);
}
