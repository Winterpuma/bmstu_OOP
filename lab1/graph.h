#ifndef GRAPH_H
#define GRAPH_H

#include "QGraphicsView"

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

int init_graph(graphics &a, QGraphicsView *gV);
void del(graphics &a);
void set(QGraphicsView *gV, graphics &a);

#endif // GRAPH_H
