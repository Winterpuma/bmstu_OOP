#include "command.h"

BaseCommand::BaseCommand()
{

}

LoadFigureCommand::LoadFigureCommand(QString fileName)
{
    this->fileName = fileName;
}

std::shared_ptr<BaseResult> LoadFigureCommand::execute(Scene& scene)
{
    scene.load(this->fileName);
    return std::shared_ptr<BaseResult>(nullptr);
}

DrawSceneCommand::DrawSceneCommand()
{

}

std::shared_ptr<BaseResult> DrawSceneCommand::execute(Scene &scene)
{
    return scene.draw();
}
