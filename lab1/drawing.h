#ifndef DRAWING_H
#define DRAWING_H
#include "QGraphicsView"
#include "graph.h"
#include "point.h"
#include "link.h"

struct draw
{
    QGraphicsView *gV;
    int width;
    int heigh;
};

struct coord_point
{
    int x;
    int y;
};
/*
void draw_line(graphics a, draw arg, coord_point beg, coord_point end);
void draw_lines(points_data dots, links_data smezh, draw arg, graphics a);
*/
#endif // DRAWING_H
