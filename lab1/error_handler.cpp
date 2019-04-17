#include "error_handler.h"
#include "QMessageBox"
#include <QObject>

void error_message(errors err)
{
    if (err == FILE_NOT_FOUND)
    {
        QMessageBox::critical(NULL, "ERROR", "File is broken, or doesn't exist");
    }
    else if (err == FILE_FORMAT_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "File format error");
    }
    else if (err == FILE_CONTENT_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "File has wrong content");
    }
    else if (err == PTR_ALL_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Error with memory allocation");
    }
    else if (err == NO_DOTS)
    {
        QMessageBox::critical(NULL, "ERROR", "File is empty, or array is empty!");
    }
    else if (err == UNKNOWN_COMMAND)
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown command in enter point!");
    }
    else
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown error");
    }
}
