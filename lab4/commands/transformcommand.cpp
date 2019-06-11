#include "transformcommand.h"

TransformCommand::TransformCommand(struct transformArgs args)
{
    x = args.x;
    y = args.y;
    z = args.z;
}

MoveCommand::MoveCommand(struct transformArgs args): TransformCommand(args)
{

}

void MoveCommand::execute(Scene &scene)
{
    scene.move(x, y, z,  nullptr);
}

ScaleCommand::ScaleCommand(struct transformArgs args): TransformCommand(args)
{

}

void ScaleCommand::execute(Scene &scene)
{
    scene.scale(x, y, z, nullptr);
}

RotateCommand::RotateCommand(struct transformArgs args): TransformCommand(args)
{

}

void RotateCommand::execute(Scene &scene)
{
    scene.rotate(x, y, z, nullptr);
}
