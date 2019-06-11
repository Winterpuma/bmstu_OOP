#ifndef SCENE_H
#define SCENE_H

#include "QString"
#include "QPixmap"
#include <vector>
#include <memory>
#include "iterator/iterator.h"
#include "object/compositeobject.h"

class Object;

class Scene
{
protected:
    CompositeObject object;
public:
    Scene();

    void load(QString &fname);
    std::shared_ptr<QPixmap> draw();
    void move(double dx, double dy, double dz, std::string ids);
    void scale(double kx, double ky, double kz, std::string ids);
    void rotate(double ax, double ay, double az, std::string ids);


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

/*protected:
    CameraIterator cur_cam;

    std::vector<std::shared_ptr<ObjectPosition>> cameras;
    std::vector<std::shared_ptr<ObjectPosition>> objects;

    friend class CameraIterator;
    friend class SceneObjectIterator;
public:
    Scene();

    void load(std::string &fname);
    std::shared_ptr<DrawResult> draw();
    void move(double dx, double dy, double dz, std::string ids);
    void scale(double kx, double ky, double kz, std::string ids);
    void rotate(double ax, double ay, double az, std::string ids);

    CameraIterator &get_current_camera();

    void add_object(Object *obj);
    void add_object(Camera *obj);
    void add_object(Composite *parent, std::string ids);
    void del_object(ObjectIterator &iter);

    void set_cam(CameraIterator &cam);

    SceneObjectIterator begin();
    SceneObjectIterator end();
    CameraIterator begin_cam();
    CameraIterator end_cam();*/
};

#endif // SCENE_H
