#ifndef DRAWING_H
#define DRAWING_H
#include "QGraphicsView"
#include "graph.h"
#include "point.h"
#include "link.h"

struct draw
{
    QGraphicsView *gV;
    int w;
    int h;
};

struct coord_point
{
    int x;
    int y;
};

coord_point get_dot(point* dots, int n);
coord_point point_transform(coord_point dot, draw arg);
void draw_links(points_data pts, links_data links, draw arg, graphics a);
void draw_line(coord_point p1, coord_point p2, graphics a, draw arg);
void my_addLine(graphics a, int x1, int x2, int y1, int y2);

#endif // DRAWING_H
