#ifndef PROCESSHANDLER_H
#define PROCESSHANDLER_H

#include "commands/command.h"
#include "result.h"
class ProcessHandler
{
private:
    std::shared_ptr<Scene> scene;
public:
    ProcessHandler();

    std::shared_ptr<BaseResult> ProcessCommand(BaseCommand &command);
};

#endif // PROCESSHANDLER_H
