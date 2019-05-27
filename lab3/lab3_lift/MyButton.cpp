#include "MyButton.h"


MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    state = PASSIVE;
    floorNumber = 0;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(processPress()));
    QObject::connect(this, SIGNAL(resetButton()), this, SLOT(reset()));

}


MyButton::~MyButton()
{

}


void MyButton::setFloorNumber(int floor)
{
    floorNumber = floor;
}


void MyButton::processPress()
{
    if(state == PASSIVE)
    {
        state = ACTIVE;
        this->setEnabled(false);
        emit floorRequest(floorNumber);
    }
}


void MyButton::reset()
{
    if(state == ACTIVE)
    {
        this->setEnabled(true);
        state = PASSIVE;
    }
}
