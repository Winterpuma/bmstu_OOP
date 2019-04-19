#include "task_manager.h"
#include "error_handler.h"
#include "operations.h"
#include "figure.h"

int task_manager(request args)
{
    static figure fig = init();
    int  err = 0;

    switch (args.t)
    {
        case QUIT:
            empty_figure(fig);
            break;
        default:
            err = UNKNOWN_COMMAND;
    }

    return err;
}
