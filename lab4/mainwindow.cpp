#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include "QtDebug"

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

void MainWindow::on_LoadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open model", "", \
                                                       "Wavefront (*.txt)");
    if (fileName.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "No file choosen");
        return;
    }

    auto command = LoadFigureCommand(fileName);
    processHandler.ProcessCommand(command);

    SendDrawCommand();
}

void MainWindow::on_moveButton_clicked()
{
    auto command = MoveCommand({10, 10, 10});
    processHandler.ProcessCommand(command);

    SendDrawCommand();
}

void MainWindow::on_scaleButton_clicked()
{
    auto command = ScaleCommand({10, 10, 10});
    processHandler.ProcessCommand(command);

    SendDrawCommand();
}

void MainWindow::on_rotateButton_clicked()
{
    auto command = RotateCommand({10, 10, 10});
    processHandler.ProcessCommand(command);

    SendDrawCommand();
}

void MainWindow::on_rotateCameraButton_clicked()
{
    auto command = RotateCommand({10, 10, 10});
    processHandler.ProcessCommand(command);

    SendDrawCommand();
}

void MainWindow::SendDrawCommand()
{
    auto command = DrawSceneCommand();
    auto res = this->processHandler.ProcessCommand(command);

    ui->canvas->setPixmap(*(static_cast<DrawResult*>(res.get())->GetData(0)));
}
