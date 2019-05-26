#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "Door.h"
#include "times.h"

class Cabin : public QObject
{
    Q_OBJECT
    enum StateCabin
    {
        MOVING,
        BUSY,
        FREE
    };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void FloorVisited(int floor, Direction d);
    void FloorTargetAchieved(int floor, Direction d);

public slots:
    void slotMoving();
    void slotFree();
    void slotBusy(int floor);

private:
    int currentFloor = 0;
    int targetFloor;
    Direction direct;
    StateCabin state;
    Door door;
    QTimer timerMoveFloor;

signals:
    void FloorAchieved();
    void Move();
};

#endif // CABIN_H
