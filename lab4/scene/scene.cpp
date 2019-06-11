#include "scene.h"

#include <iostream>
#include <QString>

#include "scenemanagers.h"
#include "transformmanager.h"

Scene::Scene()
{

}

void Scene::load(QString &fileName)
{
    auto loader = SceneLoadManager(this);
    loader.load_from(fileName);
}

std::shared_ptr<DrawResult> Scene::draw()
{
    auto drawer = SceneDrawManager(this);

    return drawer.draw();
}


void Scene::move(double dx, double dy, double dz)
{
    auto mover = MoveManager(this);

    mover.move(dx, dy, dz);
}

void Scene::scale(double kx, double ky, double kz)
{
    auto scaler = ScaleManager(this);

    scaler.scale(kx, ky, kz);
}

void Scene::rotate(double ax, double ay, double az)
{
    auto rotater = RotateManager(this);

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

void Scene::setCanvas(QGraphicsScene *g)
{
    canvas = g;
}

void Scene::setCamera(ObjIter cam)
{
    this->currentCamera = cam;
}

ObjIter Scene::getCurrentCamera()
{
    return currentCamera;
}
