#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "error_handler.h"
#include "operations.h"

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

errors draw_action(Ui::MainWindow* ui)
{
    draw dr;

    dr.gV = ui->graphicsView;
    dr.h = ui->graphicsView->height();
    dr.w = ui->graphicsView->width();

    request req;
    req.t = DRAW;
    req.dr = dr;

    errors err = (errors) task_manager(req);
    return err;
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

    err = draw_action(ui);
    if (err)
        error_message(err);

}

// Transformation
void MainWindow::on_button_Move_clicked()
{
    request req;
    req.t = MOVE;

    req.mo.dx = ui->lineEdit_MoveX->text().toInt();
    req.mo.dy = ui->lineEdit_MoveY->text().toInt();
    req.mo.dz = ui->lineEdit_MoveZ->text().toInt();

    errors err = (errors) task_manager(req);
    if (err)
        error_message(err);

    err = draw_action(ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Scale_clicked()
{
    request req;
    req.t = SCALE;

    req.sc.kx = ui->lineEdit_ScaleX->text().toFloat();
    req.sc.ky = ui->lineEdit_ScaleY->text().toFloat();
    req.sc.kz = ui->lineEdit_ScaleZ->text().toFloat();

    errors err = (errors) task_manager(req);
    if (err)
        error_message(err);

    err = draw_action(ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Turn_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = ui->lineEdit_TurnX->text().toFloat();
    req.tu.oy = ui->lineEdit_TurnY->text().toFloat();
    req.tu.oz = ui->lineEdit_TurnZ->text().toFloat();

    errors err = (errors) task_manager(req);
    if (err)
        error_message(err);

    err = draw_action(ui);
    if (err)
        error_message(err);
}
