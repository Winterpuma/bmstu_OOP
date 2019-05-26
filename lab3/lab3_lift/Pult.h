#ifndef PULT_H
#define PULT_H

#include <QPushButton>
#include <QObject>
#include <QDebug>

class CButton : public QPushButton
{
    Q_OBJECT
    enum StateButton
    {
        PRESSED,
        RELEASED
    };

public:
    explicit CButton(QWidget *parent = nullptr);
    void SetNumberFloor(int floor);
    virtual ~CButton();

public slots:

    void slotPressed();
    void slotReleased();

signals:

    void resetButton();
    void floorRequest(int floor);

private:

    StateButton state;
    int floorNumber;
};

#endif // PULT_H
