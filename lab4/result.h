#ifndef RESULT_H
#define RESULT_H
#include "QPixmap"

class BaseResult
{
public:
    BaseResult();
    virtual ~BaseResult() = default;
    virtual void GetData() {}
};

class DrawResult : public BaseResult
{
private:
    std::shared_ptr<QPixmap> m;
public:
    DrawResult();

    std::shared_ptr<QPixmap> GetData(int);
};

#endif // RESULT_H
