#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T12:01:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glass.cpp \
    figure.cpp \
    nextpattern.cpp

HEADERS  += mainwindow.h \
    glass.h \
    figure.h \
    nextpattern.h

CONFIG += C++11

FORMS    += mainwindow.ui
