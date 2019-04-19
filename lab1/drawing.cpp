#include "drawing.h"
#include "graph.h"

coord_point get_dot(point* dots, int n)
{
    coord_point dot = {dots[n].x, dots[n].y};
    return dot;
}


coord_point point_transform(coord_point dot, draw arg)
{
    coord_point tmp;

    tmp.x = dot.x + arg.w/2;
    tmp.y = dot.y + arg.h/2;

    return tmp;
}


void draw_links(points_data pts, links_data links, draw arg, graphics a)
{
    coord_point p1, p2;

    for (int i = 0; i < links.n; i++)
    {
        p1 = get_dot(pts.arr, links.arr[i].p1);
        p2 = get_dot(pts.arr, links.arr[i].p2);
        draw_line(p1, p2, a, arg);
    }
}


void draw_line(coord_point p1, coord_point p2, graphics a, draw arg)
{
    p1 = point_transform(p1, arg);
    p2 = point_transform(p2, arg);

    my_addLine(a, p1.x, p2.x, p1.y, p2.y);
}

void my_addLine(graphics a, int x1, int x2, int y1, int y2)
{
    a.scene->addLine(x1, y1, x2, y2, a.pen);
}

