#ifndef SCENE_H
#define SCENE_H

#include "QString"
#include "QPixmap"
#include <vector>
#include <memory>

class Object;

class Scene
{
public:
    Scene();

    void load(QString &fname);
    std::shared_ptr<QPixmap> draw();
    /*void move(double dx, double dy, double dz, std::string ids);
    void scale(double kx, double ky, double kz, std::string ids);
    void rotate(double ax, double ay, double az, std::string ids);
*/

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
