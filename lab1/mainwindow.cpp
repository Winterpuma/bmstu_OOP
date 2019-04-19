#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Load figure
void MainWindow::on_actionOpen_triggered()
{
    ;
}

// Transformation
void MainWindow::on_button_Move_clicked()
{
    ;
}

void MainWindow::on_button_Scale_clicked()
{
    ;
}

void MainWindow::on_button_Turn_clicked()
{
    ;
}
