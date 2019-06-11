#include "scenebuilder.h"
#include "scenemanagers.h"

SceneBuilder::SceneBuilder(Scene *s)
{
    scene = s;
}

auto SceneBuilder::set_loadname()
{
    auto load = SceneLoadManager(scene);
    QString loadname("tests.txt");

    load.load_from(loadname);

    return load;
}

void SceneBuilder::set_camera()
{
    Camera* cameraPtr = new Camera();
    std::shared_ptr<Object> camera(cameraPtr);
    scene->addCamera(camera);

    auto begCamera = scene->objectBegin();
    scene->setCamera(begCamera);
}

void SceneBuilder::build_scene()
{
    set_camera();
    set_loadname();
}
