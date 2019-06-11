#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "scenemanagers.h"

class TransformManager : public BaseSceneManager
{
public:
    TransformManager(Scene *_scene);
};

class MoveManager : public TransformManager
{
public:
    MoveManager(Scene *_scene);

    void move(double dx, double dy, double dz);
};

class ScaleManager : public TransformManager
{
public:
    ScaleManager(Scene *_scene);

    void scale(double kx, double ky, double kz);
};

class RotateManager : public TransformManager
{
public:
    RotateManager(Scene *_scene);

    void rotate(double ax, double ay, double az);
    void rotate(std::vector<Node> nodes, double ax, double ay, double az);
};

#endif // TRANSFORMMANAGER_H
