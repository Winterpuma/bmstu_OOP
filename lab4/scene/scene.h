#ifndef SCENE_H
#define SCENE_H

#include "QString"
#include "QPixmap"
#include "QGraphicsScene"
#include <vector>
#include <memory>
#include "iterator/iterator.h"
#include "object/compositeobject.h"
#include "result.h"

class Object;

class Scene
{
protected:
    CompositeObject object;
public:
    Scene();

    void load(QString &fname);
    std::shared_ptr<DrawResult> draw();
    void move(double dx, double dy, double dz);
    void scale(double kx, double ky, double kz);
    void rotate(double ax, double ay, double az);

    void addModel(const std::shared_ptr<Object>& model);
    void removeModel(const size_t index);

    void addCamera(const std::shared_ptr<Object>& camera);
    void removeCamera(const size_t index);

    std::shared_ptr<Object> getModel(const size_t index);
    std::shared_ptr<Object> getCamera(const size_t index);

    ObjIter objectBegin();
    ObjIter objectEnd();
    ObjIter modelIndex(const size_t index);
    ObjIter cameraIndex(const size_t index);

    void setCanvas(QGraphicsScene*);
    void setCamera(ObjIter);

    ObjIter getCurrentCamera();
private:
    QGraphicsScene* canvas;
    ObjIter currentCamera;
};

#endif // SCENE_H
