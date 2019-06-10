#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include "scene/scene.h"

class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = default;

    virtual void execute(Scene &scene) = 0;
};

class LoadFigureCommand : public BaseCommand
{
private:
    QString fileName;

public:
    LoadFigureCommand(QString fileName);

    void execute(Scene &scene);
};

class DrawSceneCommand : public BaseCommand
{
public:
    DrawSceneCommand();

    void execute(Scene &scene);
};
#endif // COMMAND_H
