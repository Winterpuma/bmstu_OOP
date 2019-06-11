#include "command.h"

BaseCommand::BaseCommand()
{

}

LoadFigureCommand::LoadFigureCommand(QString fileName)
{
    this->fileName = fileName;
}

void LoadFigureCommand::execute(Scene& scene)
{
    scene.load(this->fileName);
}

DrawSceneCommand::DrawSceneCommand()
{

}

void DrawSceneCommand::execute(Scene &scene)
{
    scene.draw();
}
