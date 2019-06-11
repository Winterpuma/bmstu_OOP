#ifndef TRANSFORMCOMMAND_H
#define TRANSFORMCOMMAND_H

#include "command.h"
class TransformCommand : public BaseCommand
{
protected:
    double x;
    double y;
    double z;

public:
    TransformCommand(struct transformArgs args);
};

class MoveCommand : public TransformCommand
{
public:
    MoveCommand(struct transformArgs args);

    void execute(Scene &scene);
};

class ScaleCommand : public TransformCommand
{
public:
    ScaleCommand(struct transformArgs args);

    void execute(Scene &scene);
};

class RotateCommand : public TransformCommand
{
public:
    RotateCommand(struct transformArgs args);

    void execute(Scene &scene);
};

struct transformArgs
{
    double x;
    double y;
    double z;
};

#endif // TRANSFORMCOMMAND_H
