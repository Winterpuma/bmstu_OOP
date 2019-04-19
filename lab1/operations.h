#ifndef OPERATIONS_H
#define OPERATIONS_H

struct move
{
    int dx;
    int dy;
    int dz;
};

struct scale
{
    double kx;
    double ky;
    double kz;
};

struct turn
{
    int ox;
    int oy;
    int oz;
};

#endif // OPERATIONS_H
