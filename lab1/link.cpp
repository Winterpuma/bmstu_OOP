#include "cstdio"
#include <cstdlib>
#include "link.h"
#include "figure.h"
#include "error_handler.h"
#include "io.h"

int links_alloc(links_data &connections, int len)
{
    connections.n = len;

    connections.arr = (link*) calloc(len, sizeof(link));
    if (!connections.arr)
        return PTR_ALL_ERR;

    return NONE;
}


void links_free(links_data &connections)
{
    if (connections.arr)
        free(connections.arr);
}


int read_link(FILE* f, link* joints)
{
    if (fscanf(f, "%d%d", &joints->p1, &joints->p2) != 2)
        return FILE_FORMAT_ERR;

    return NONE;
}


int read_n_links(FILE *f, link* joints, int n)
{
    int err = 0;
    for (int i = 0; i < n && !err; i++)
    {
        if (read_link(f, &joints[i]))
            err = FILE_FORMAT_ERR;
    }

    return err;
}


int process_links(FILE* f, links_data& connections, points_data& pts)
{
    int n;
    int err = 0;

    err = read_amount(f, &n);
    if (!err)
    {
        err = links_alloc(connections, n);
        if (!err)
            err = read_n_links(f, connections.arr, n);
    }
    if (err)
    {
        points_free(pts);
        links_free(connections);
    }
    return err;
}
