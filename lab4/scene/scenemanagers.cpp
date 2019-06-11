#include "scenemanagers.h"
#include "iterator/iterator.h"
#include "drawer.h"
#include "transformmanager.h"
#include "builder.h"
#include "QGraphicsScene"
#include "QPainter"

BaseSceneManager::BaseSceneManager(Scene *_scene)
{
    this->scene = _scene;
}

SceneDrawManager::SceneDrawManager(Scene *scene) : BaseSceneManager(scene) {}

std::shared_ptr<DrawResult> SceneDrawManager::draw()
{
    ModelDrawer drawer(650, 650);

    std::shared_ptr<Camera> camera = std::static_pointer_cast<Camera>(*(scene->getCurrentCamera()));
    RotateManager rotator(scene);
    ObjIter b = scene->objectBegin();
    ObjIter e = scene->objectEnd();
    for (ObjIter iter = b; iter != e; ++iter)
    {
        if (!(*iter))
            throw NoDrawingObjectException();

        if ((*iter)->isVisible())
        {
            std::shared_ptr<Model> model = std::static_pointer_cast<Model>(*iter);

            const std::vector<Edge> edges = model->getEdges();
            if (edges.empty())
                throw NoDrawingEdgesException();

            std::vector<Node> nodes = model->getNodes();
            if (nodes.empty())
                throw NoDrawingNodesException();

            rotator.rotate(nodes, camera->getRtX(), camera->getRtY(), camera->getRtZ());

            for (size_t i = 0; i < edges.size(); ++i)
            {
                const Node& src = nodes[edges[i].getSrc()];
                const Node& dst = nodes[edges[i].getPurp()];
                drawer.drawLine(getX(src.getX(), src.getZ()), getY(src.getY(), src.getZ()),
                             getX(dst.getX(), dst.getZ()), getY(dst.getY(), dst.getZ()));
            }
        }
    }
    return drawer.getResult();
}

double SceneDrawManager::getX(const double x, const double z) const
{
    return x + z * coeff3D;
}

double SceneDrawManager::getY(const double y, const double z) const
{
    return -y - z * coeff3D;
}

SceneLoadManager::SceneLoadManager(Scene *scene) : BaseSceneManager(scene) {}

void SceneLoadManager::load_from(QString& fileName)
{
    ModelBuilder modelBuilder = ModelBuilder();
    modelBuilder.build(openSrc(fileName));
    scene->addModel(modelBuilder.getModel());
}

std::ifstream SceneLoadManager::openSrc(QString& fileName)
{
    std::ifstream file;
    file.open(fileName.toStdString());
    if (!file)
        throw OpenFileException();
    return file;
}

void SceneLoadManager::closeSrc(std::ifstream file)
{
    try
    {
        file.close();
    }
    catch (const std::ifstream::failure& e)
    {
        throw CloseFileException();
    }
}
