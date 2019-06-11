#include "scene.h"

#include <iostream>
#include <QString>

#include "scenemanagers.h"
#include "transformmanager.h"

/*#include "sceneloadmanager.h"
#include "scenesavemanager.h"
#include "scenedrawmanager.h"
#include "scenemovemanager.h"
#include "scenescalemanager.h"
#include "scenerotatemanager.h"

*/

Scene::Scene()
{

}

void Scene::load(QString &fileName)
{
    auto loader = SceneLoadManager(this);
    loader.load_from(fileName);
}

std::shared_ptr<QPixmap> Scene::draw()
{
    auto drawer = SceneDrawManager(this);

    return drawer.draw();
}


void Scene::move(double dx, double dy, double dz, std::string ids)
{
    auto mover = MoveManager(this, ids);

    mover.move(dx, dy, dz);
}

void Scene::scale(double kx, double ky, double kz, std::string ids)
{
    auto scaler = ScaleManager(this, ids);

    scaler.scale(kx, ky, kz);
}

void Scene::rotate(double ax, double ay, double az, std::string ids)
{
    auto rotater = RotateManager(this, ids);

    rotater.rotate(ax, ay, az);
}

void Scene::addModel(const std::shared_ptr<Object>& object)
{
    this->object.addModel(object);
}

void Scene::removeModel(const size_t index)
{
    this->object.removeModel(index);
}

void Scene::addCamera(const std::shared_ptr<Object>& object)
{
    this->object.addCamera(object);
}

void Scene::removeCamera(const size_t index)
{
    this->object.removeCamera(index);
}

std::shared_ptr<Object> Scene::getModel(const size_t index)
{
    return this->object.getModel(index);
}

std::shared_ptr<Object> Scene::getCamera(const size_t index)
{
    return this->object.getCamera(index);
}

ObjIter Scene::objectBegin()
{
    return this->object.objectBegin();
}

ObjIter Scene::objectEnd()
{
    return this->object.objectEnd();
}

ObjIter Scene::modelIndex(const size_t index)
{
    return this->object.modelIndex(index);
}

ObjIter Scene::cameraIndex(const size_t index)
{
    return this->object.cameraIndex(index);
}

/*
CameraIterator &Scene::get_current_camera()
{
    return this->cur_cam;
}

void Scene::add_object(Object *_obj)
{
    auto pos = std::shared_ptr<ObjectPosition>(new ObjectPosition(_obj));

    this->objects.push_back(pos);
}

void Scene::add_object(Camera *_obj)
{
    auto pos = std::shared_ptr<ObjectPosition>(new ObjectPosition(_obj));

    this->objects.push_back(pos);
    this->cameras.push_back(pos);
}

void Scene::add_object(Composite *parent, std::string ids)
{

}

void Scene::del_object(ObjectIterator &iter)
{

}

void Scene::set_cam(CameraIterator &cam)
{
    this->cur_cam = cam;
}

SceneObjectIterator Scene::begin()
{
    SceneObjectIterator iter(this);
    return iter;
}

SceneObjectIterator Scene::end()
{
    SceneObjectIterator iter(this);
    for (size_t i = 0; i < this->objects.size(); ++iter, i++);
    return iter;
}

CameraIterator Scene::begin_cam()
{
    CameraIterator iter(this);
    return iter;
}

CameraIterator Scene::end_cam()
{
    CameraIterator iter(this);
    for (size_t i = 0; i < this->cameras.size(); ++iter, i++);
    return iter;
}
*/
