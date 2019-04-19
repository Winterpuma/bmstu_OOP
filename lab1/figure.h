#ifndef FIGURE_H
#define FIGURE_H
#include "point.h"
#include "link.h"
#include "drawing.h"
#include "operations.h"

struct figure
{
    points_data points;
    links_data links;
};

figure& init();
void empty_figure(figure& fig);
void copy_figure(figure& fig, figure& tmp);
int load_figure_from_file(figure &ob, const char *filename);

int draw_figure(figure fig, draw arg);

int move_figure(figure& fig, move coeff);
int scale_figure(figure& fig, scale coeff);
int turn_figure(figure& fig, turn coeff);

#endif // FIGURE_H
