#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T19:15:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 10C_Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animal.cpp \
    alien.cpp \
    player.cpp \
    score.cpp \
    lives.cpp

HEADERS  += mainwindow.h \
    animal.h \
    alien.h \
    player.h \
    score.h \
    lives.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
