#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

class Edge
{
public:
    Edge();
    Edge(const size_t src, const size_t purp);
    Edge(const Edge& edge);
    Edge(Edge&& edge);
    ~Edge();

    Edge& operator=(const Edge& edge);
    Edge& operator=(Edge&& edge);

    size_t getSrc() const;
    size_t getPurp() const;

    void setSrc(const size_t src);
    void setPurp(const size_t purp);

private:
    size_t src;
    size_t purp;
};

#endif // EDGE_H

