// License: See distributed LICENSE file.

#ifndef FLUID_GRID_H
#define FLUID_GRID_H

#include "Array.h"
#include <Eigen>

class Grid
{
public:
    explicit Grid(int i, int j, int k, double h);
    explicit Grid(unsigned i, unsigned j, unsigned k, double h);
    explicit Grid(double x, double y, double z, double h);
    ~Grid() {}

    double pressure(int i, int j, int k) const;
    double pressure(double x, double y, double z) const;

    const Eigen::Vector3d& velocity(int i, int j, int k) const;
    const Eigen::Vector3d& velocity(double x, double y, double z) const;

private:
    Grid();
    Grid(const Grid& other);
    Grid& operator =(const Grid& other);

    Grid(unsigned i, unsigned j, unsigned k,
         double x, double y, double z, double h);

    Array<double> mPressures;
    Array<Eigen::Vector3d> mVelocities;
    double mWidth, mHeight, mDepth;
    double mH;
};

#endif // FLUID_GRID_H
