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


int read_link(link* joints, FILE* f)
{
    if (fscanf(f, "%d%d", &joints->p1, &joints->p2) != 2)
        return FILE_FORMAT_ERR;

    return NONE;
}


int read_n_links(link* joints, int n, FILE *f)
{
    int err = 0;
    for (int i = 0; i < n && !err; i++)
    {
        if (read_link(&joints[i], f))
            err = FILE_FORMAT_ERR;
    }

    return err;
}


int process_links(links_data& connections, FILE* f)
{
    int n;
    int err = 0;

    err = read_amount(&n, f);
    if (!err)
    {
        if (n)
            err = links_alloc(connections, n);
        else
            err = NO_LINKS;

        if (!err)
        {
            if ((err = read_n_links(connections.arr, n, f)) == FILE_FORMAT_ERR)
                links_free(connections);
        }
    }
    return err;
}
