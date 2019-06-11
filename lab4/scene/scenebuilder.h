#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "scene.h"

class SceneBuilder
{
private:
    Scene *scene;
public:
    SceneBuilder(Scene *s);

    void build_scene();
    void set_camera();
    auto set_loadname();
};

#endif // SCENEBUILDER_H
