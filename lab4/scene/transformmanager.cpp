#include "transformmanager.h"

#include <sstream>

TransformManager::TransformManager(Scene *_scene, std::string _ids) : BaseSceneManager(_scene)
{
    if (_ids.length() > 0)
    {
        std::stringstream ss(_ids);
        std::string item;
        while (std::getline(ss, item, ';'))
        {
            this->ids.push_back(std::move(item));
        }
    }
}

bool TransformManager::in(size_t id)
{
    for (auto i : this->ids)
    {
        if (std::atof(i.c_str()) == id)
            return true;
    }
    return false;
}

MoveManager::MoveManager(Scene *_scene, std::string ids) : TransformManager(_scene, ids)
{

}

void MoveManager::move(double dx, double dy, double dz)
{
    /*if (this->ids.size() == 0)
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (obj_i->get_object()->get_is_drawable())
            {
                Matrix matr({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {dx, dy, dz, 1}});

                obj_i->set_transform(matr);
            }
        }
    }*/
}

ScaleManager::ScaleManager(Scene *_scene, std::string ids) : TransformManager(_scene, ids)
{

}

void ScaleManager::scale(double kx, double ky, double kz)
{
    /*if (this->ids.size() == 0)
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (obj_i->get_object()->get_is_drawable())
            {
                Matrix matr({{kx, 0, 0, 0}, {0, ky, 0, 0}, {0, 0, kz, 0}, {0, 0, 0, 1}});

                obj_i->set_transform(matr);
            }
        }
    }*/
}


RotateManager::RotateManager(Scene *_scene, std::string ids) : TransformManager(_scene, ids)
{

}

void RotateManager::rotate(double ax, double ay, double az)
{
    /*if (this->ids.size() == 0)
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (obj_i->get_object()->get_is_drawable())
            {
                Matrix matrx({{1, 0, 0, 0}, {0, cos(ax), sin(ax), 0}, {0, -sin(ax), cos(ax), 0}, {0, 0, 0, 1}});
                Matrix matry({{cos(ay), 0, -sin(ay), 0}, {0, 1, 0, 0}, {sin(ay), 0, cos(ay), 0}, {0, 0, 0, 1}});
                Matrix matrz({{cos(az), sin(az), 0, 0}, {-sin(az), cos(az), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

                obj_i->set_transform(matrx);
                obj_i->set_transform(matry);
                obj_i->set_transform(matrz);
            }
        }
    }
    else
    {
        for (auto obj_i = this->scene->begin(); obj_i != this->scene->end(); ++obj_i)
        {
            if (this->in(obj_i->get_object()->get_id()))
            {
                Matrix matrx({{1, 0, 0, 0}, {0, cos(ax), sin(ax), 0}, {0, -sin(ax), cos(ax), 0}, {0, 0, 0, 1}});
                Matrix matry({{cos(ay), 0, -sin(ay), 0}, {0, 1, 0, 0}, {sin(ay), 0, cos(ay), 0}, {0, 0, 0, 1}});
                Matrix matrz({{cos(az), sin(az), 0, 0}, {-sin(az), cos(az), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});

                obj_i->set_transform(matrx);
                obj_i->set_transform(matry);
                obj_i->set_transform(matrz);
            }
        }
    }*/
}
