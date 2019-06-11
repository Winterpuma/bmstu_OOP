#include "builder.h"
#include "exceptions/uploaderException.h"
#include "exceptions/builderException.h"
#include "object/model.h"


ModelBuilder::ModelBuilder()
{
}

std::shared_ptr<Model> ModelBuilder::getModel() const
{
    return model;
}

void ModelBuilder::build(std::ifstream f)
{
    model = std::make_shared<Model>();
    buildEdges(f);
    buildNodes(f);
}

void ModelBuilder::buildNode(const double x, const double y, const double z)
{
    if (!isModelBuilt())
        throw NoBuildingObjectException();

    Node node(x, y, z);
    this->model->addNode(node);
}

void ModelBuilder::buildNodes(std::ifstream& f)
{
    size_t countNodes;
    double x, y, z;

    f >> countNodes;

    for (size_t i = 0; i < countNodes; ++i)
    {
        f >> x >> y >> z;
        buildNode(x, y, z);
    }
}

void ModelBuilder::buildEdges(std::ifstream& f)
{
    size_t countEdges;
    size_t src, purp;

    f >> countEdges;

    for (size_t i = 0; i < countEdges; ++i)
    {
        f >> src >> purp;
        buildEdge(src, purp);
    }
}

void ModelBuilder::buildEdge(const size_t src, const size_t purp)
{
    if (!isModelBuilt())
        throw NoBuildingObjectException();

    Edge edge(src, purp);
    this->model->addEdge(edge);
}

bool ModelBuilder::isModelBuilt() const
{
    return (this->model == nullptr) ? false : true;
}
