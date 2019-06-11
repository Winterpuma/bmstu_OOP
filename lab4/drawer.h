#ifndef DRAWER_H
#define DRAWER_H

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
    ModelDrawer(QGraphicsScene* canvas) : BaseDrawer(), canvas(canvas) {}

    void drawLine(const double xB, const double yB, const double xE,
                  const double yE) override
    {
        canvas->addLine(xB, yB, xE, yE);
    }

private:
    QGraphicsScene* canvas;
};

#endif // DRAWER_H
