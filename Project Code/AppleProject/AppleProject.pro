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
    grantdto.cpp \
    teach_bargraph1_vo.cpp \
    presentationdto.cpp \
    teachingdto.cpp \
    graph_combo_box_populator.cpp \
    grant_bargraph1_vo.cpp \
    load_csv.cpp \
    date_filter_combo_populator.cpp


HEADERS  += mainwindow.h \
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
    grantdto.h \
    teach_bargraph1_vo.h \
    presentationdto.h \
    grant_bargraph1_vo.h \
    teachingdto.h \
    bargraph_vo.h \
    graph_combo_box_populator.h \
    treelist_vo.h \
    load_csv.h \
    date_filter_combo_populator.h

FORMS    += mainwindow.ui \
    verify_csv.ui \
    analyze_csv.ui \
    load_csv.ui

DISTFILES += \
    AppleProject.pro.user \
    publication.csv \
    Grants.csv \
    Presentations.csv \
    Teaching.csv \

RESOURCES += \
    apple_resource.qrc
