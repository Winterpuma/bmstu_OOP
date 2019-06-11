#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <fstream>
#include "object/model.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual std::shared_ptr<Model> getModel() const = 0;
    virtual void build(std::ifstream f) = 0;
};

class ModelBuilder : public BaseBuilder
{
public:
    ModelBuilder();
    ~ModelBuilder() = default;

    std::shared_ptr<Model> getModel() const;
    void build(std::ifstream f);
    void buildNode(const double x, const double y, const double z);
    void buildEdge(const size_t src, const size_t purp);
    void buildNodes(std::ifstream& f);
    void buildEdges(std::ifstream& f);

protected:
    bool isModelBuilt() const;

    std::shared_ptr<Model> model;
};

struct buildParams
{
    std::ifstream& f;
};

#endif // MODELBUILDER_H
