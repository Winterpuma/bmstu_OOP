 #ifndef MODEL_H
#define MODEL_H

#include "object.h"
#include "node.h"
#include "edge.h"

#include <vector>

class Model : public VisibleObject
{
public:
    Model() = default;
    Model(const std::vector<Node> nodes, const std::vector<Edge> edges);
    Model(const Model& model);
    Model(Model&& model);
    ~Model() = default;

    Model& operator=(const Model& model);
    Model& operator=(Model&& model);

    const std::vector<Node> getNodes() const;
    const std::vector<Edge> getEdges() const;

    void addNode(const Node& node);
    void addEdge(const Edge& edge);

    void shift(const double x, const double y, const double z);
    void scale(const double x, const double y, const double z);
    void rotate(const double x, const double y, const double z);

private:
    std::vector<Node> nodes;    
    std::vector<Edge> edges;
};

#endif // MODEL_H

