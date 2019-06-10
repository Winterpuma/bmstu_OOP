#include "processhandler.h"

ProcessHandler::ProcessHandler()
{
    this->scene = std::shared_ptr<Scene>(new Scene);

    /*    auto scene_pointer = this->scene.get();

    SceneBuilder builder(scene_pointer);
    builder.build_scene(scene_pointer);*/
}

void ProcessHandler::ProcessCommand(BaseCommand &command)
{
    command.execute(*(this->scene));
}
