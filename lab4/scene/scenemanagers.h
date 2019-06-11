#ifndef SCENEMANAGERS_H
#define SCENEMANAGERS_H

#include "QPixmap"
#include "QString"
#include "QGraphicsScene"
#include "scene.h"
#include "exceptions/drawerException.h"
#include "exceptions/uploaderException.h"
#include "result.h"
class BaseSceneManager
{
protected:
    Scene *scene;
public:
    BaseSceneManager(Scene *_scene);
};

class SceneDrawManager : public BaseSceneManager
{
private:
    static constexpr double coeff3D = 0.5;

    double getX(const double x, const double z) const;
    double getY(const double y, const double z) const;

public:
    SceneDrawManager(Scene *_scene);

    std::shared_ptr<DrawResult> draw();
};

#define NOFILE -1
#define SUCCESS 1

class SceneLoadManager : public BaseSceneManager
{
/*private:
    std::shared_ptr<BaseParser> parser;*/
public:
    SceneLoadManager(Scene *_scene);

    //void set_parser(BaseParser *new_parser);

    void load_from(QString &fname);
    std::ifstream openSrc(QString& fileName);
    void closeSrc(std::ifstream);
};

#endif // SCENEMANAGERS_H
