#-------------------------------------------------
#
# Project created by QtCreator 2019-06-10T20:04:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        builder.cpp \
        commands/command.cpp \
        commands/transformcommand.cpp \
        main.cpp \
        mainwindow.cpp \
        object/camera.cpp \
        object/compositeobject.cpp \
        object/edge.cpp \
        object/model.cpp \
        object/node.cpp \
        processhandler.cpp \
        result.cpp \
        scene/scene.cpp \
        scene/scenebuilder.cpp \
        scene/scenemanagers.cpp \
        scene/transformmanager.cpp

HEADERS += \
        builder.h \
        commands/command.h \
        commands/transformcommand.h \
        drawer.h \
        exceptions/baseException.h \
        exceptions/builderException.h \
        exceptions/drawerException.h \
        exceptions/objectexception.h \
        exceptions/transformerException.h \
        exceptions/uploaderException.h \
        iterator/iterator.h \
        mainwindow.h \
        object/camera.h \
        object/compositeobject.h \
        object/edge.h \
        object/model.h \
        object/node.h \
        object/object.h \
        processhandler.h \
        result.h \
        scene/scene.h \
        scene/scenebuilder.h \
        scene/scenemanagers.h \
        scene/transformmanager.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
