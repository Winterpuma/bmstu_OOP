#include "Elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    QObject::connect(&cabin,  SIGNAL(FloorVisited(int, Direction)),
                     &control, SLOT(slotChangeCurrentFloor(int, Direction)));
    QObject::connect(&cabin,  SIGNAL(FloorTargetAchieved(int, Direction)),
                     &control, SLOT(slotAchieveFloor(int, Direction)));
    QObject::connect(&control, SIGNAL(SendTarget(int)),
                     &cabin,  SLOT(slotBusy(int)));
}

QWidget *Elevator::GetWidget()
{
    return &control;
}
