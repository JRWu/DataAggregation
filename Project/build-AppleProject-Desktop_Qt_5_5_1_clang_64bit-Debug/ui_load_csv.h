/********************************************************************************
** Form generated from reading UI file 'load_csv.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_CSV_H
#define UI_LOAD_CSV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadCSV
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *recent_files_area;
    QLabel *recent_files_label;
    QListView *recent_files_list;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *select_csv_area;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *publication_btn;
    QPushButton *grant_btn;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *teaching_btn;
    QPushButton *presentation_btn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *navigation_area;
    QPushButton *load_btn;
    QPushButton *verify_btn;
    QPushButton *analyze_btn;

    void setupUi(QMainWindow *LoadCSV)
    {
        if (LoadCSV->objectName().isEmpty())
            LoadCSV->setObjectName(QStringLiteral("LoadCSV"));
        LoadCSV->resize(800, 600);
        LoadCSV->setMinimumSize(QSize(800, 600));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        LoadCSV->setPalette(palette);
        LoadCSV->setAutoFillBackground(true);
        centralwidget = new QWidget(LoadCSV);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 600));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 70, 251, 511));
        recent_files_area = new QVBoxLayout(verticalLayoutWidget);
        recent_files_area->setObjectName(QStringLiteral("recent_files_area"));
        recent_files_area->setContentsMargins(0, 0, 0, 0);
        recent_files_label = new QLabel(verticalLayoutWidget);
        recent_files_label->setObjectName(QStringLiteral("recent_files_label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setBold(true);
        font.setWeight(75);
        recent_files_label->setFont(font);
        recent_files_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        recent_files_area->addWidget(recent_files_label);

        recent_files_list = new QListView(verticalLayoutWidget);
        recent_files_list->setObjectName(QStringLiteral("recent_files_list"));

        recent_files_area->addWidget(recent_files_list);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(270, 70, 521, 511));
        select_csv_area = new QVBoxLayout(verticalLayoutWidget_2);
        select_csv_area->setObjectName(QStringLiteral("select_csv_area"));
        select_csv_area->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        publication_btn = new QPushButton(verticalLayoutWidget_2);
        publication_btn->setObjectName(QStringLiteral("publication_btn"));
        publication_btn->setMinimumSize(QSize(200, 200));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        publication_btn->setFont(font1);

        horizontalLayout_3->addWidget(publication_btn);

        grant_btn = new QPushButton(verticalLayoutWidget_2);
        grant_btn->setObjectName(QStringLiteral("grant_btn"));
        grant_btn->setMinimumSize(QSize(200, 200));
        grant_btn->setFont(font1);

        horizontalLayout_3->addWidget(grant_btn);


        select_csv_area->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        teaching_btn = new QPushButton(verticalLayoutWidget_2);
        teaching_btn->setObjectName(QStringLiteral("teaching_btn"));
        teaching_btn->setMinimumSize(QSize(200, 200));
        teaching_btn->setFont(font1);

        horizontalLayout_2->addWidget(teaching_btn);

        presentation_btn = new QPushButton(verticalLayoutWidget_2);
        presentation_btn->setObjectName(QStringLiteral("presentation_btn"));
        presentation_btn->setMinimumSize(QSize(200, 200));
        presentation_btn->setFont(font1);

        horizontalLayout_2->addWidget(presentation_btn);


        select_csv_area->addLayout(horizontalLayout_2);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 52));
        navigation_area = new QHBoxLayout(horizontalLayoutWidget);
        navigation_area->setObjectName(QStringLiteral("navigation_area"));
        navigation_area->setContentsMargins(0, 0, 0, 0);
        load_btn = new QPushButton(horizontalLayoutWidget);
        load_btn->setObjectName(QStringLiteral("load_btn"));
        load_btn->setMaximumSize(QSize(16777215, 50));
        QPalette palette1;
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        load_btn->setPalette(palette1);
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(28);
        font2.setBold(true);
        font2.setWeight(75);
        load_btn->setFont(font2);
        load_btn->setFlat(true);

        navigation_area->addWidget(load_btn);

        verify_btn = new QPushButton(horizontalLayoutWidget);
        verify_btn->setObjectName(QStringLiteral("verify_btn"));
        verify_btn->setMaximumSize(QSize(16777215, 50));
        QPalette palette2;
        QBrush brush7(QColor(229, 191, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        verify_btn->setPalette(palette2);
        verify_btn->setFont(font2);
        verify_btn->setFlat(true);

        navigation_area->addWidget(verify_btn);

        analyze_btn = new QPushButton(horizontalLayoutWidget);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));
        analyze_btn->setMaximumSize(QSize(16777215, 50));
        QPalette palette3;
        QBrush brush8(QColor(0, 134, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        analyze_btn->setPalette(palette3);
        analyze_btn->setFont(font2);
        analyze_btn->setFlat(true);

        navigation_area->addWidget(analyze_btn);

        LoadCSV->setCentralWidget(centralwidget);

        retranslateUi(LoadCSV);

        QMetaObject::connectSlotsByName(LoadCSV);
    } // setupUi

    void retranslateUi(QMainWindow *LoadCSV)
    {
        LoadCSV->setWindowTitle(QApplication::translate("LoadCSV", "MainWindow", 0));
        recent_files_label->setText(QApplication::translate("LoadCSV", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">RECENT FILES</span></p></body></html>", 0));
        publication_btn->setText(QApplication::translate("LoadCSV", "PUBLICATIONS", 0));
        grant_btn->setText(QApplication::translate("LoadCSV", "GRANTS", 0));
        teaching_btn->setText(QApplication::translate("LoadCSV", "TEACHING", 0));
        presentation_btn->setText(QApplication::translate("LoadCSV", "PRESENTATIONS", 0));
        load_btn->setText(QApplication::translate("LoadCSV", "LOAD >", 0));
        verify_btn->setText(QApplication::translate("LoadCSV", "VERIFY >", 0));
        analyze_btn->setText(QApplication::translate("LoadCSV", "ANALYZE >", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadCSV: public Ui_LoadCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_CSV_H
