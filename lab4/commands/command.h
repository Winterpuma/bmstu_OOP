#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include "scene/scene.h"
#include "result.h"
/*
 * std::shared_ptr<BaseProcessResult>*/

class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = default;

    virtual std::shared_ptr<BaseResult> execute(Scene &scene) = 0;
};

class LoadFigureCommand : public BaseCommand
{
private:
    QString fileName;

public:
    LoadFigureCommand(QString fileName);

    std::shared_ptr<BaseResult> execute(Scene &scene);
};

class DrawSceneCommand : public BaseCommand
{
public:
    DrawSceneCommand();

    std::shared_ptr<BaseResult> execute(Scene &scene);
};
#endif // COMMAND_H
