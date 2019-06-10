#ifndef SCENEMANAGERS_H
#define SCENEMANAGERS_H

#include "QPixmap"
#include "QString"
#include "scene.h"

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

public:
    SceneDrawManager(Scene *_scene);

    std::shared_ptr<QPixmap> draw();
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
};

#endif // SCENEMANAGERS_H
