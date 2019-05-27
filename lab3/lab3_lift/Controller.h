#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "MyButton.h"
#include "times.h"
#include "Door.h"

class Controller : public QWidget
{
    Q_OBJECT
    enum StateController
    {
        NO_TARGET,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();

signals:
    void SendTarget(int floor);

public slots:
    void slotChangeCurrentFloor(int floor, Direction d);
    void slotAchieveFloor(int floor, Direction d);

private slots:
    void slotAddFloorToVisit(int floor);

private:
    bool GetNewTarget(int &newFloor);

    StateController state;
    int currentFloor;
    Direction direct;

    bool targetArray[FLOOR_NUMBERS];
    MyButton* buttons[FLOOR_NUMBERS];

    QVBoxLayout* layout;
};

#endif // CONTROLLER_H
