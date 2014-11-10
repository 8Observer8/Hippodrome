#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T16:23:54
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hippodrome
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Horse.cpp

HEADERS  += Dialog.h \
    Horse.h

FORMS    += Dialog.ui
