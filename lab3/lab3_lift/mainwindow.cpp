#include <QVBoxLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(200, 300);
    layout = new QVBoxLayout;
    ui->centralWidget->setLayout(layout);
    layout->addWidget(elevator.GetWidget());
}

MainWindow::~MainWindow()
{
   delete layout;
   delete ui;
}
