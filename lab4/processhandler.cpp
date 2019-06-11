#include "processhandler.h"
#include "scene/scenebuilder.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "result.h"

ProcessHandler::ProcessHandler()
{
    this->scene = std::shared_ptr<Scene>(new Scene);

    auto scene_pointer = this->scene.get();

    SceneBuilder builder(scene_pointer);
    builder.build_scene();
}

std::shared_ptr<BaseResult> ProcessHandler::ProcessCommand(BaseCommand &command)
{
    return command.execute(*(this->scene));
}
