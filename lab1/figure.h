#ifndef FIGURE_H
#define FIGURE_H
#include "point.h"
#include "link.h"

struct figure
{
    points_data points;
    links_data links;
};

figure& init();
void empty_figure(figure& fig);
int load_figure_from_file(const char *filename, figure &ob);

#endif // FIGURE_H
