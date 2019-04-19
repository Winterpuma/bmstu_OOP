#include "task_manager.h"
#include "error_handler.h"
#include "operations.h"
#include "figure.h"

int task_manager(request req)
{
    static figure fig = init();
    int  err = 0;

    switch (req.t)
    {
    case INIT:
        break;
    case LOAD_FILE:
        err = load_figure_from_file(fig, req.load_f.filename);
        break;
    case DRAW:
        err = draw_figure(fig, req.dr);
        break;
    case MOVE:
        err = move_figure(fig, req.mo);
        break;
    case SCALE:
        err = scale_figure(fig, req.sc);
        break;
    case TURN:
        err = turn_figure(fig, req.tu);
        break;
    case QUIT:
        empty_figure(fig);
        break;
    default:
        err = UNKNOWN_COMMAND;
    }

    return err;
}
