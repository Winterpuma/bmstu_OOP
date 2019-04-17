#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error_handler.h"

int points_alloc(points_data& pts, int len)
{
    pts.n = len;
    pts.arr = (point*) calloc(len, sizeof(point));

    if (!pts.arr)
    {
        return PTR_ALL_ERR;
    }
    return NONE;
}


void points_free(points_data &pts)
{
    if (pts.arr)
    {
        free(pts.arr);
    }
}


int read_point(FILE* f, point* dot)
{
    if (fscanf(f, "%lf%lf%lf", &dot->x, &dot->y, &dot->z) != 3)
    {
        return FILE_FORMAT_ERR;
    }
    return NONE;
}


int read_n_points(FILE *f, point *dots, int n)
{
    int err = 0;
    for (int i = 0; i < n && !err; i++)
    {
        if (read_point(f, &dots[i]))
        {
            err = FILE_FORMAT_ERR;
        }
    }
    return err;
}


int process_points(FILE *f, points_data &pts)
{
    int n;
    int err = 0;

    err = read_amount(f, &n);
    if (!err)
    {
        err = points_alloc(pts, n);
        if (!err)
        {
            err = read_n_points(f, pts.arr, n);
        }
    }

    return err;
}
