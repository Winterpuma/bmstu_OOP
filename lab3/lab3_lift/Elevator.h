#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include "times.h"
#include "Controller.h"
#include "Cabin.h"

class Elevator : public QObject
{
    Q_OBJECT
public:
    explicit Elevator(QObject *parent = nullptr);
    QWidget* GetWidget();

private:
    Controller control;
    Cabin cabin;
};

#endif // ELEVATOR_H
