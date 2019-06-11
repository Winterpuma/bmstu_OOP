#include "result.h"

BaseResult::BaseResult()
{

}

DrawResult::DrawResult() : BaseResult()
{
    this->m = std::shared_ptr<QPixmap>(new QPixmap(651, 461));
}

std::shared_ptr<QPixmap> DrawResult::GetData(int)
{
    return this->m;
}
