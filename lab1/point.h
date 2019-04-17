#ifndef POINT_H
#define POINT_H

struct point
{
    double x;
    double y;
    double z;
};

struct points_data
{
    int n;
    point *arr;
};

int points_alloc(points_data& pts, int len);
void points_free(points_data& pts);
int read_point(FILE* f, point* dot);
int read_n_points(FILE *f, point* dots, int n);
int process_points(FILE *f, points_data& pts);

#endif // POINT_H
