#include "transformmanager.h"
#include "exceptions/transformerException.h"

#include <sstream>

TransformManager::TransformManager(Scene *_scene) : BaseSceneManager(_scene)
{
}

MoveManager::MoveManager(Scene *_scene) : TransformManager(_scene)
{

}

void MoveManager::move(double dx, double dy, double dz)
{
    ObjIter b = scene->objectBegin();
    ObjIter e = scene->objectEnd();
    for (ObjIter iter = b; iter != e; ++iter)
    {
        if (!(*iter))
            throw NoDrawingObjectException();

        if ((*iter)->isVisible())
        {
            std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);
            std::vector<Node> nodes = model->getNodes();
            if (nodes.empty())
                throw NoTransformingNodesException();

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                nodes[i].shift(dx, dy, dz);
            }
        }
    }
}

ScaleManager::ScaleManager(Scene *_scene) : TransformManager(_scene)
{

}

void ScaleManager::scale(double kx, double ky, double kz)
{

    ObjIter b = scene->objectBegin();
    ObjIter e = scene->objectEnd();
    for (ObjIter iter = b; iter != e; ++iter)
    {
        if (!(*iter))
            throw NoDrawingObjectException();

        if ((*iter)->isVisible())
        {
            std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);
            std::vector<Node> nodes = model->getNodes();
            if (nodes.empty())
                throw NoTransformingNodesException();

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                nodes[i].scale(kx, ky, kz);
            }
        }
    }
}


RotateManager::RotateManager(Scene *_scene) : TransformManager(_scene)
{

}

void RotateManager::rotate(double ax, double ay, double az)
{
    ObjIter b = scene->objectBegin();
    ObjIter e = scene->objectEnd();
    for (ObjIter iter = b; iter != e; ++iter)
    {
        if (!(*iter))
            throw NoDrawingObjectException();

        if ((*iter)->isVisible())
        {
            std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);
            std::vector<Node> nodes = model->getNodes();
            if (nodes.empty())
                throw NoTransformingNodesException();

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                nodes[i].rotateX(ax);
                nodes[i].rotateY(ay);
                nodes[i].rotateZ(az);
            }
        }
    }
}


void RotateManager::rotate(std::vector<Node> nodes, double ax, double ay, double az)
{
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].rotateX(ax);
        nodes[i].rotateY(ay);
        nodes[i].rotateZ(az);
    }
}
