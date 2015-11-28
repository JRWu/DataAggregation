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
    date_filter_combo_populator.cpp \
    View/load_csv.cpp \
    View/view.cpp \
    View/mainwindow.cpp \
    View/mainwindowcontroller.cpp \
    Utility/stringfunctions.cpp \
    CSV-Data/csvfieldvalidator.cpp \
    CSV-Data/csvfieldvalidatorfactory.cpp \
    CSV-Data/csvlinevalidator.cpp \
    DTO/csvdto.cpp \
    CSV-Data/csvlinevalidatorfactory.cpp \

HEADERS  += verify_csv.h \
    analyze_csv.h \
    publicationdto.h \
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
    date_filter_combo_populator.h \
    View/view.h \
    View/load_csv.h \
    View/mainwindow.h \
    Utility/stringfunctions.h \
    CSV-Parser/csv.h \
    CSV-Parser/csvparser.h \
    CSV-Data/csvfieldvalidator.h \
    CSV-Data/csvfieldvalidatorfactory.h \
    CSV-Data/csvfield.h \
    CSV-Data/csvlinevalidator.h \
    DTO/csvdto.h \
    CSV-Data/csvlinevalidatorfactory.h \

FORMS    += View/mainwindow.ui \
    verify_csv.ui \
    analyze_csv.ui \
    View/load_csv.ui

DISTFILES += \
    AppleProject.pro.user \
    publication.csv \
    Grants.csv \
    Presentations.csv \
    Teaching.csv \

RESOURCES += \
    apple_resource.qrc
