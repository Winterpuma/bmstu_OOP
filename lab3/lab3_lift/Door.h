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
    explicit Door();

signals:
    void DoorIsClosed();
    void OpenDoor();

public slots:
    void slotOpen();
    void slotClose();

private slots:
    void slotOpening();
    void slotClosing();

private:
    StateDoor state;
    QTimer timerOpen;
    QTimer timerClose;
    QTimer timerWaitOpen;
};

#endif // DOOR_H
