#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error_handler.h"
#include "point.h"
#include "link.h"
#include "drawing.h"
#include "graph.h"

figure& init()
{
    static figure fig;

    fig.points.n = 0;
    fig.points.arr = NULL;

    fig.links.n = 0;
    fig.links.arr = NULL;

    return fig;
}


void empty_figure(figure& fig)
{
    fig.points.n = 0;
    points_free(fig.points);

    fig.links.n = 0;
    links_free(fig.links);
}


int load_figure_from_file(const char *filename, figure& fig)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return FILE_NOT_FOUND;

    int err = process_points(f, fig.points);
    if (!err)
        err = process_links(f, fig.links, fig.points);

    fclose(f);
    return err;
}


int draw_figure(figure fig, draw arg)
{
    graphics a;

    int err = init_graph(a, arg.gV);
    if (err)
        return err;

    draw_links(fig.points, fig.links, arg, a);

    set(arg.gV, a);

    return err;
}
