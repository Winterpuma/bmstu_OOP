#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include "times.h"

class Door : public QObject
{
    Q_OBJECT
    enum StateDoor
    {
        OPEN,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    StateDoor state;
    explicit Door();

signals:
    void DoorIsClosed();
    void DoorIsOpened();

public slots:
    void slotOpen();
    void slotClose();

private slots:
    void slotOpening();
    void slotClosing();

private:
    QTimer timerOpen;
    QTimer timerClose;
    QTimer timerWaitOpen;

signals:
    void StopOpening();
};

#endif // DOOR_H
