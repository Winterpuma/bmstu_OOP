#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "scenemanagers.h"

class TransformManager : public BaseSceneManager
{
protected:
    std::vector<std::string> ids;

    bool in(size_t id);
public:
    TransformManager(Scene *_scene, std::string ids);
};

class MoveManager : public TransformManager
{
public:
    MoveManager(Scene *_scene, std::string ids);

    void move(double dx, double dy, double dz);
};

class ScaleManager : public TransformManager
{
public:
    ScaleManager(Scene *_scene, std::string ids);

    void scale(double kx, double ky, double kz);
};

class RotateManager : public TransformManager
{
public:
    RotateManager(Scene *_scene, std::string ids);

    void rotate(double ax, double ay, double az);
};

#endif // TRANSFORMMANAGER_H
