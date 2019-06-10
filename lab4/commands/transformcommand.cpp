#include "transformcommand.h"

TransformCommand::TransformCommand(struct transformArgs args)
{
    x = args.x;
    y = args.y;
    z = args.z;
}

void TransformCommand::execute(Scene &scene)
{

}

MoveCommand::MoveCommand(struct transformArgs args): TransformCommand(args)
{

}

void MoveCommand::execute(Scene &scene)
{

}

ScaleCommand::ScaleCommand(struct transformArgs args): TransformCommand(args)
{

}

void ScaleCommand::execute(Scene &scene)
{

}

RotateCommand::RotateCommand(struct transformArgs args): TransformCommand(args)
{

}

void RotateCommand::execute(Scene &scene)
{

}
