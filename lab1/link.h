#ifndef CONNECTION_H
#define CONNECTION_H
#include "point.h"

struct link
{
    int p1;
    int p2;
};

struct links_data
{
    int n;
    link *arr;
};

int links_alloc(links_data &connections, int len);
void links_free(links_data &connections);
int read_link(FILE* f, link* joints);
int read_n_links(FILE *f, link* joints, int n);
int process_links(FILE* f, links_data& connections, points_data& pts);

#endif // CONNECTION_H
