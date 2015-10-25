#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T20:01:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppleProject
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    load_csv.cpp \
    verify_csv.cpp \
    analyze_csv.cpp \
    publicationdto.cpp \
    csvdata.cpp \
    csvdataassembler.cpp \
    qcustomplot.cpp \
    validatedto.cpp \
    dtoassembler.cpp \
    publicationdtolist.cpp

HEADERS  += mainwindow.h \
    load_csv.h \
    verify_csv.h \
    analyze_csv.h \
    publicationdto.h \
    fast-cpp-csv-parser-master/csv.h \
    csvdata.h \
    csvdataassembler.h \
    qcustomplot.h \
    validatedto.h \
    dtoassembler.h \
    publicationdtolist.h
    QT += printsupport

FORMS    += mainwindow.ui \
    load_csv.ui \
    verify_csv.ui \
    analyze_csv.ui

DISTFILES += \
    AppleProject.pro.user \
    publication.csv
