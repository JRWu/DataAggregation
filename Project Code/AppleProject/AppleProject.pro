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
    qcustomplot.cpp \
    View/load_csv.cpp \
    View/mainwindow.cpp \
    View/mainwindowcontroller.cpp \
    Utility/stringfunctions.cpp \
    CSV-Data/csvfieldvalidator.cpp \
    CSV-Data/csvfieldvalidatorfactory.cpp \
    CSV-Data/csvlinevalidator.cpp \
    DTO/csvdto.cpp \
    CSV-Data/csvlinevalidatorfactory.cpp \
    DTO/bargraphadapter.cpp \
    DTO/filteradapter.cpp \
    DTO/treelistadapter.cpp \
    DTO/data.cpp \
    Tab-Objects/dtofilter.cpp \
    View/verify_csv.cpp \
    View/analyze_csv.cpp \
    Tab-Objects/filtervalue.cpp \
    Tab-Objects/combobox.cpp \
    Tab-Objects/tabsubject.cpp \
    Tab-Objects/tabobserver.cpp

HEADERS  += qcustomplot.h \
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
    DTO/bargraphadapter.h \
    DTO/filteradapter.h \
    DTO/treelistadapter.h \
    DTO/data.h \
    Tab-Objects/dtofilter.h \
    View/ui_load_csv.h \
    View/ui_analyze_csv.h \
    View/ui_mainwindow.h \
    View/verify_csv.h \
    View/analyze_csv.h \
    View/ui_verify_csv.h \
    Tab-Objects/filtervalue.h \
    Tab-Objects/tabobserver.h \
    Tab-Objects/tabsubject.h \
    Tab-Objects/combobox.h

FORMS    += View/mainwindow.ui \
    View/load_csv.ui \
    View/verify_csv.ui \
    View/analyze_csv.ui \

DISTFILES += \
    AppleProject.pro.user \
    publication.csv \
    Grants.csv \
    Presentations.csv \
    Teaching.csv \

RESOURCES += \
    apple_resource.qrc

