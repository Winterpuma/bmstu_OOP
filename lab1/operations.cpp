#include "math.h"
#include "operations.h"
#include "error_handler.h"
#include "figure.h"

void move_point(point& dot, move coeff)
{
    dot.x += coeff.dx;
    dot.y += coeff.dy;
    dot.z += coeff.dz;
}

int move_points_array(point* pts, int n, move coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        move_point(pts[i], coeff);

    return err;
}


void scale_point(point& dot, scale coeff)
{
    dot.x *= coeff.kx;
    dot.y *= coeff.ky;
    dot.z *= coeff.kz;
}

int scale_points_array(point* pts, int n, scale coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        scale_point(pts[i], coeff);

    return err;
}


double d_cos(double angle)
{
    return cos(angle * 3.1415 / 180);
}

double d_sin(double angle)
{
    return sin(angle * 3.1415 / 180);
}

void x_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    dot.y = dot.y + cos_ang + dot.z * sin_ang;
    dot.z = -dot.y * sin_ang + dot.z * cos_ang;
}

void y_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    dot.x = dot.x * cos_ang + dot.z * sin_ang;
    dot.z = -dot.x * sin_ang + dot.z * cos_ang;
}

void z_turn_point(point& dot, double angle)
{
    double cos_ang = d_cos(angle);
    double sin_ang = d_sin(angle);

    dot.x = dot.x * cos_ang + dot.y * sin_ang;
    dot.y = -dot.x * sin_ang + dot.y * cos_ang;
}


int turn_points_array(point* pts, int n, turn coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
    {
        x_turn_point(pts[i], coeff.ox);
        y_turn_point(pts[i], coeff.oy);
        z_turn_point(pts[i], coeff.oz);
    }

    return err;
}
