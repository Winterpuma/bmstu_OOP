#ifndef POINT_H
#define POINT_H

#include <cstdio>

struct point
{
    double x;
    double y;
    double z;
};

struct points_data
{
    int n;
    point* arr;
};

int points_alloc(points_data& pts, int len);
void points_free(points_data& pts);

int read_point(point* dot, FILE* f);
int read_n_points(point *dots, int n, FILE *f);
int process_points(points_data &pts, FILE *f);

#endif // POINT_H
