#include "scenemanagers.h"
#include "iterator/iterator.h"
#include "drawer.h"
#include "builder.h"
#include "QGraphicsScene"
BaseSceneManager::BaseSceneManager(Scene *_scene)
{
    this->scene = _scene;
}

SceneDrawManager::SceneDrawManager(Scene *scene) : BaseSceneManager(scene) {}

void SceneDrawManager::draw(QGraphicsScene* canvas)
{
    ModelDrawer drawer(canvas);
    //std::shared_ptr<Camera> cm = std::static_pointer_cast<Camera>(obj);
    //transformtions::Shifting shf(0, 0, 0);
    //ModelTransformator transformator = ModelTransformator(shf, cm);

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

            //transformator.transformNodes(nodes);

            for (size_t i = 0; i < edges.size(); ++i)
            {
                const Node& src = nodes[edges[i].getSrc()];
                const Node& dst = nodes[edges[i].getPurp()];
                drawer.drawLine(getX(src.getX(), src.getZ()), getY(src.getY(), src.getZ()),
                             getX(dst.getX(), dst.getZ()), getY(dst.getY(), dst.getZ()));
            }
        }
    }
/*
    QPainter canvas(res->get_data(0).get());
    canvas.setBrush(Qt::white);
    canvas.setPen(Qt::magenta);
    canvas.drawRect(-1, 0, 650, 680);

    for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
    {
        auto obj_p = (*(obj_i));
        if (obj_p.get_object()->get_is_drawable())
        {
            auto cur_obj = obj_p.get_object().get();
            auto cur_cam = this->scene->get_current_camera();
            auto pts = static_cast<Figure*>(cur_obj)->get_points_coord();

            for (size_t i = 0; i < pts.size(); i++)
            {
                pts[i] = obj_p.get_transform()->vec_mult(pts[i]);
                pts[i] = cur_cam->get_transform()->vec_mult(pts[i]);
            }

            pts = static_cast<Camera*>(cur_cam->get_object().get())->apply_cam(pts);
            static_cast<Figure*>(cur_obj)->set_points(pts);

            auto coord = static_cast<Figure*>(cur_obj)->get_edges();
            for (auto iter : coord)
            {
                canvas.drawLine(int(iter[0]), int(iter[1]), int(iter[4]), int(iter[5]));
            }

            static_cast<Figure*>(cur_obj)->reset_points();
        }
    }
    canvas.end();

    return res;*/
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
    //std::shared_ptr<Model> m = modelBuilder.getModel();
    scene->addModel(modelBuilder.getModel());
    /*
    std::shared_ptr<std::ifstream> fin(new std::ifstream(QString& fileName));

    this->parser->set_file(fin);

    while (true)
    {
        Object *obj = this->parser->parse();

        if (obj == nullptr)
            break;

        this->scene->add_object(obj);
    }

    fin->close();*/
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
