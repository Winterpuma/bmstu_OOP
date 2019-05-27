#include "Cabin.h"

Cabin::Cabin(QObject *parent)
{
    state = FREE;
    currentFloor = 0;
    targetFloor = 0;
    direct = STILL;
    QObject::connect(&door, SIGNAL(DoorIsClosed()), this, SLOT(slotMoving()));
    QObject::connect(&timerMoveFloor, SIGNAL(timeout()), this, SLOT(slotMoving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), this, SLOT(slotFree()));
    QObject::connect(this, SIGNAL(Move()), this, SLOT(slotMoving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), &door, SLOT(slotOpening()));
}


void Cabin::slotMoving()
{
    if (state == BUSY)
    {
        state = MOVING;
        if (currentFloor == targetFloor)
        {
            emit FloorAchieved();
        }
        else
        {
            timerMoveFloor.start(TIME_MOVING_FLOOR);
        }
        emit FloorVisited(currentFloor, direct);
    }
    else if (state == MOVING)
    {
        state = MOVING;
        qDebug() << "move, floor" << currentFloor;
        if (currentFloor < targetFloor)
        {
            direct = UP;
            currentFloor += 1;
        }
        else
        {
            direct = DOWN;
            currentFloor -= 1;
        }
        if (currentFloor == targetFloor)
        {
            emit FloorAchieved();
        }
        else
        {
            timerMoveFloor.start(TIME_MOVING_FLOOR);
        }
    }
}


void Cabin::slotFree()
{
    qDebug() << "STOP, floor" << currentFloor;
    state = FREE;
    emit FloorTargetAchieved(currentFloor, direct);
}


void Cabin::slotBusy(int floor)
{
    state = BUSY;
    targetFloor = floor;
    if(currentFloor == targetFloor)
    {
        emit FloorAchieved();
    }
    else
    {
        if(currentFloor < targetFloor)
        {
            direct = UP;
        }
        else {
            direct = DOWN;
        }
        emit Move();
    }
}
