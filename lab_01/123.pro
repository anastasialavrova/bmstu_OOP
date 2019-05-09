#-------------------------------------------------
#
# Project created by QtCreator 2019-04-11T19:46:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 123
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    file_funcs.cpp \
    init_free_background.cpp \
    move_scale_turn_funcs.cpp \
    pre_file_funcs.cpp \
    pre_move_scale_turn.cpp \
    pre_update_scene.cpp \
    task_manager.cpp \
    update_scene.cpp

HEADERS += \
        mainwindow.h \
    file_funcs.h \
    init_free_background.h \
    move_scale_turn_funcs.h \
    pre_file_funcs.h \
    pre_move_scale_turn.h \
    pre_update_scene.h \
    task_manager.h \
    update_scene.h \
    libraries_and_enum.h \
    mainwindow_buttons_and_errs.h

FORMS += \
        mainwindow.ui
