#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "drawing.h"
#include "operations.h"

enum task
{
    LOAD_FILE,
    L_TURN,
    V_TURN,
    DRAW,
    SET_SCALE,
    QUIT
};

struct load_file
{
    const char* filename;
};

struct request
{
    task t;
    union
    {
        struct draw dr;
        struct turn tu;
        struct scale sc;
        struct load_file load_f;
    };
};

int task_manager(request args);

#endif // TASK_MANAGER_H
