#include "scenemanagers.h"

BaseSceneManager::BaseSceneManager(Scene *_scene)
{
    this->scene = _scene;
}

SceneDrawManager::SceneDrawManager(Scene *scene) : BaseSceneManager(scene) {}

std::shared_ptr<QPixmap> SceneDrawManager::draw()
{
    std::shared_ptr<QPixmap> res =std::shared_ptr<QPixmap>(new QPixmap);
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
    canvas.end();*/

    return res;
}

SceneLoadManager::SceneLoadManager(Scene *scene) : BaseSceneManager(scene) {}

void SceneLoadManager::load_from(QString& fileName)
{/*
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
