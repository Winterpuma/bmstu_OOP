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

}

DrawSceneCommand::DrawSceneCommand()
{

}

void DrawSceneCommand::execute(Scene &scene)
{

}
