#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QDebug>

class MyButton : public QPushButton
{
    Q_OBJECT
    enum ButtonState
    {
        ACTIVE,
        PASSIVE
    };

public:
    explicit MyButton(QWidget *parent = nullptr);
    void setFloorNumber(int floor);
    virtual ~MyButton();

public slots:
    void processPress();
    void reset();

signals:
    void resetButton();
    void floorRequest(int floor);

private:
    ButtonState state;
    int floorNumber;
};

#endif // MYBUTTON_H
