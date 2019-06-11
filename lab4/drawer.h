#ifndef DRAWER_H
#define DRAWER_H
#include "result.h"
#include "QPainter"
#include <QGraphicsScene>

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const double xB, const double yB, const double xE,
                          const double yE) = 0;
};

class ModelDrawer : public BaseDrawer
{
public:
    ModelDrawer(int width, int height) : BaseDrawer()
    {
        res = std::shared_ptr<DrawResult>(new DrawResult);
        QPainter canvas(res->GetData(0).get());
        canvas.setBrush(Qt::white);
        canvas.setPen(Qt::magenta);
        canvas.drawRect(-1, 0, width, height);
    }

    void drawLine(const double xB, const double yB, const double xE,
                  const double yE) override
    {
        canvas->addLine(xB, yB, xE, yE);
    }

    std::shared_ptr<DrawResult> getResult()
    {
        return  res;
    }

private:
    std::shared_ptr<DrawResult> res;
    QGraphicsScene* canvas;
};

#endif // DRAWER_H
