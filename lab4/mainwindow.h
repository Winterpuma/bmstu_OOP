#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include "commands/command.h"
#include "commands/transformcommand.h"
#include "processhandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoadButton_clicked();

    void on_moveButton_clicked();

    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_rotateCameraButton_clicked();

private:
    void SendDrawCommand();

    Ui::MainWindow *ui;
    ProcessHandler processHandler;
};

#endif // MAINWINDOW_H
