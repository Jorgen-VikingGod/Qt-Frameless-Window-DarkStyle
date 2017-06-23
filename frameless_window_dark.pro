#-------------------------------------------------
#
# Project created by QtCreator 2017-06-23T12:13:52
#
#-------------------------------------------------


QT        += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET     = frameless_window_dark
TEMPLATE   = app

SOURCES   += main.cpp\
             mainwindow.cpp

HEADERS   += mainwindow.h \
             DarkStyle.h

FORMS     += mainwindow.ui

RESOURCES += darkstyle.qrc
