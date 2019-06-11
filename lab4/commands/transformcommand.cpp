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

std::shared_ptr<BaseResult> MoveCommand::execute(Scene &scene)
{
    scene.move(x, y, z);
    return std::shared_ptr<BaseResult>(nullptr);
}

ScaleCommand::ScaleCommand(struct transformArgs args): TransformCommand(args)
{

}

std::shared_ptr<BaseResult> ScaleCommand::execute(Scene &scene)
{
    scene.scale(x, y, z);
    return std::shared_ptr<BaseResult>(nullptr);
}

RotateCommand::RotateCommand(struct transformArgs args): TransformCommand(args)
{

}

std::shared_ptr<BaseResult> RotateCommand::execute(Scene &scene)
{
    scene.rotate(x, y, z);
    return std::shared_ptr<BaseResult>(nullptr);
}
