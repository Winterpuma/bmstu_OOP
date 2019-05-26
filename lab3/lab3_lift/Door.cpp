#include "Door.h"


Door::Door()
{
    state = CLOSED;
    QObject::connect(this, SIGNAL(OpenDoor()), this, SLOT(slotOpening()));
    QObject::connect(&timerOpen, SIGNAL(timeout()), this, SLOT(slotOpen()));
    QObject::connect(&timerClose, SIGNAL(timeout()), this, SLOT(slotClose()));
    QObject::connect(&timerWaitOpen, SIGNAL(timeout()), this, SLOT(slotClosing()));
}


void Door::slotOpen()
{
    if(state == OPENING)
    {
        state = OPEN;
        qDebug() << "Doors opened";
        timerWaitOpen.start(TIME_DOOR_WAIT);
        emit OpenDoor();
    }
}


void Door::slotClose()
{
    if(state == CLOSING)
    {
        state = CLOSED;
        qDebug() << "Doors closed";
        emit DoorIsClosed();
    }
}


void Door::slotOpening()
{
    if(state == CLOSED)
    {
        state = OPENING;
        qDebug() << "Opening doors";
        timerOpen.start(TIME_DOOR);
    }
    if(state == CLOSING)
    {
        state = OPENING;
        qDebug() << "Opening doors";
        int t = timerClose.remainingTime();
        timerClose.stop();
        timerOpen.start(TIME_DOOR - t);
    }
}


void Door::slotClosing()
{
    if(state == OPEN)
    {
        state = CLOSING;
        qDebug() << "Closing doors";
        timerClose.start(TIME_DOOR);
    }
}
