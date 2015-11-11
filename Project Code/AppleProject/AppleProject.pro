#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T20:01:45
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppleProject
TEMPLATE = app

CONFIG += c++11
CONFIG += static
#CONFIG += release

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
    tree_list_vo.cpp \
    graphvisualizations.cpp \
    pub_bargraph1_vo.cpp \
    grantdto.cpp \
    teach_bargraph1_vo.cpp \
    presentationdto.cpp \
    teachingdto.cpp \
    pres_bargraph1_vo.cpp

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
    tree_list_vo.h \
    graphvisualizations.h \
    pub_bargraph1_vo.h \
    grantdto.h \
    teach_bargraph1_vo.h \
    presentationdto.h \
    grant_bargraph1_vo.h \
    ui_analyze_csv.h \
    ui_load_csv.h \
    ui_verify_csv.h \
    ui_mainwindow.h \
    teachingdto.h \
    pres_bargraph1_vo.h \

FORMS    += mainwindow.ui \
    load_csv.ui \
    verify_csv.ui \
    analyze_csv.ui

DISTFILES += \
    AppleProject.pro.user \
    publication.csv \
    Grants.csv \
    Presentations.csv \
    Teaching.csv
