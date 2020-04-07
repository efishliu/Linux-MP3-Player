#-------------------------------------------------
#
# Project created by QtCreator 2018-07-04T20:00:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

QT += phonon

RESOURCES += \
    qrc.qrc

OTHER_FILES +=
