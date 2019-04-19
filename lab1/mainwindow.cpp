#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "error_handler.h"

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
    request req;
    req.t = LOAD_FILE;
    req.load_f.filename = "cube.txt";

    errors err = (errors) task_manager(req);
    if (err)
    {
        error_message(err);
        return;
    }

    draw dr;

    dr.gV = ui->graphicsView;
    dr.heigh = ui->graphicsView->height();
    dr.width = ui->graphicsView->width();

    req.t = DRAW;
    req.dr = dr;

    err = (errors) task_manager(req);
    if (err)
        error_message(err);

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
