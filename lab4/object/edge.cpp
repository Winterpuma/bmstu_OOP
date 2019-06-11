#ifndef EDGE_HPP
#define EDGE_HPP

#include "edge.h"

Edge::Edge() : src(0), purp(0) {}

Edge::Edge(const size_t src, const size_t purp) : src(src), purp(purp) {}

Edge::Edge(const Edge& edge)
{
    this->src = edge.src;
    this->purp = edge.purp;
}

Edge::Edge(Edge &&edge)
{
    this->src = edge.src;
    this->purp = edge.purp;
    edge.~Edge();
}

Edge::~Edge()
{
    this->src = 0;
    this->purp = 0;
}

Edge& Edge::operator=(const Edge& edge)
{
    this->src = edge.src;
    this->purp = edge.purp;

    return *this;
}

Edge& Edge::operator=(Edge&& edge)
{
    this->src = edge.src;
    this->purp = edge.purp;
    edge.~Edge();

    return *this;
}

size_t Edge::getSrc() const
{
    return src;
}

size_t Edge::getPurp() const
{
    return purp;
}

void Edge::setSrc(const size_t src)
{
    this->src = src;
}

void Edge::setPurp(const size_t purp)
{
    this->purp = purp;
}

#endif // EDGE_HPP

