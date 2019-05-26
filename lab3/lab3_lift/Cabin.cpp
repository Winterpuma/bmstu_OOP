#include "Cabin.h"

Cabin::Cabin(QObject *parent)
{
    state = FREE;
    currentFloor = 0;
    targetFloor = 0;
    direct = STILL;
    QObject::connect(&door, SIGNAL(DoorIsClosed()), this, SLOT(slotMoving())); //! не позволяет уехать лифту с открытыми дверями
    QObject::connect(&timerMoveFloor, SIGNAL(timeout()), this, SLOT(slotMoving()));
    QObject::connect(this, SIGNAL(FloorAchieved()), this, SLOT(
                         slotFree()));
    QObject::connect(this, SIGNAL(Move()), this, SLOT(slotMoving()));
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
//    qDebug() << "slotFree";
    state = FREE;
    //timerMoveFloor.stop();
    emit FloorTargetAchieved(currentFloor, direct);
}

void Cabin::slotBusy(int floor)
{
//    qDebug() << "slotBusy";
    state = BUSY;
    targetFloor = floor;
    if(currentFloor == targetFloor) {
        emit FloorAchieved();
    }
    else {
        if(currentFloor < targetFloor) {
            direct = UP;
        }
        else {
            direct = DOWN;
        }
        emit Move();
    }
}
