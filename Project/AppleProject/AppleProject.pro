#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T20:01:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppleProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    load_csv.cpp \
    verify_csv.cpp \
    analyze_csv.cpp

HEADERS  += mainwindow.h \
    load_csv.h \
    verify_csv.h \
    analyze_csv.h

FORMS    += mainwindow.ui \
    load_csv.ui \
    verify_csv.ui \
    analyze_csv.ui
