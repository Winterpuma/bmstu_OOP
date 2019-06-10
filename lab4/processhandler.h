#ifndef PROCESSHANDLER_H
#define PROCESSHANDLER_H

#include "commands/command.h"

class ProcessHandler
{
private:
    std::shared_ptr<Scene> scene;
public:
    ProcessHandler();

    void ProcessCommand(BaseCommand &command);
};

#endif // PROCESSHANDLER_H
