/********************************************************************************
** Form generated from reading UI file 'load_window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_WINDOW_H
#define UI_LOAD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadWindow
{
public:
    QGridLayout *gridLayout;
    QSplitter *navigation_area;
    QPushButton *load_btn;
    QPushButton *verify_btn;
    QPushButton *analyze_btn;
    QSplitter *splitter_6;
    QSplitter *splitter_5;
    QLabel *file_lbl;
    QLabel *selected_file_lbl;
    QSplitter *splitter_3;
    QPushButton *load_pub_btn;
    QPushButton *load_grnt_btn;
    QSplitter *splitter_4;
    QPushButton *load_teach_btn;
    QPushButton *load_pres_btn;
    QSplitter *recent_files_area;
    QLabel *recent_files_lbl;
    QListView *recent_files_list;
    QPushButton *recent_files_btn;

    void setupUi(QWidget *LoadWindow)
    {
        if (LoadWindow->objectName().isEmpty())
            LoadWindow->setObjectName(QStringLiteral("LoadWindow"));
        LoadWindow->resize(800, 600);
        LoadWindow->setMinimumSize(QSize(800, 600));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        LoadWindow->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        LoadWindow->setFont(font);
        gridLayout = new QGridLayout(LoadWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        navigation_area = new QSplitter(LoadWindow);
        navigation_area->setObjectName(QStringLiteral("navigation_area"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        navigation_area->setFont(font1);
        navigation_area->setOrientation(Qt::Horizontal);
        load_btn = new QPushButton(navigation_area);
        load_btn->setObjectName(QStringLiteral("load_btn"));
        load_btn->setMinimumSize(QSize(0, 40));
        load_btn->setMaximumSize(QSize(16777215, 40));
        QPalette palette1;
        QBrush brush1(QColor(170, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        load_btn->setPalette(palette1);
        load_btn->setFlat(true);
        navigation_area->addWidget(load_btn);
        verify_btn = new QPushButton(navigation_area);
        verify_btn->setObjectName(QStringLiteral("verify_btn"));
        verify_btn->setMinimumSize(QSize(0, 40));
        verify_btn->setMaximumSize(QSize(16777215, 40));
        QPalette palette2;
        QBrush brush3(QColor(229, 191, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        verify_btn->setPalette(palette2);
        verify_btn->setFlat(true);
        navigation_area->addWidget(verify_btn);
        analyze_btn = new QPushButton(navigation_area);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));
        analyze_btn->setMinimumSize(QSize(0, 40));
        analyze_btn->setMaximumSize(QSize(16777215, 40));
        QPalette palette3;
        QBrush brush4(QColor(0, 134, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        analyze_btn->setPalette(palette3);
        analyze_btn->setFlat(true);
        navigation_area->addWidget(analyze_btn);

        gridLayout->addWidget(navigation_area, 0, 0, 1, 2);

        splitter_6 = new QSplitter(LoadWindow);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Vertical);
        splitter_5 = new QSplitter(splitter_6);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        file_lbl = new QLabel(splitter_5);
        file_lbl->setObjectName(QStringLiteral("file_lbl"));
        file_lbl->setMinimumSize(QSize(125, 40));
        file_lbl->setMaximumSize(QSize(125, 40));
        file_lbl->setIndent(10);
        splitter_5->addWidget(file_lbl);
        selected_file_lbl = new QLabel(splitter_5);
        selected_file_lbl->setObjectName(QStringLiteral("selected_file_lbl"));
        selected_file_lbl->setMinimumSize(QSize(0, 40));
        selected_file_lbl->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setBold(false);
        font2.setWeight(50);
        selected_file_lbl->setFont(font2);
        splitter_5->addWidget(selected_file_lbl);
        splitter_6->addWidget(splitter_5);
        splitter_3 = new QSplitter(splitter_6);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        QFont font3;
        font3.setPointSize(16);
        splitter_3->setFont(font3);
        splitter_3->setOrientation(Qt::Horizontal);
        load_pub_btn = new QPushButton(splitter_3);
        load_pub_btn->setObjectName(QStringLiteral("load_pub_btn"));
        load_pub_btn->setMinimumSize(QSize(250, 200));
        splitter_3->addWidget(load_pub_btn);
        load_grnt_btn = new QPushButton(splitter_3);
        load_grnt_btn->setObjectName(QStringLiteral("load_grnt_btn"));
        load_grnt_btn->setMinimumSize(QSize(250, 200));
        splitter_3->addWidget(load_grnt_btn);
        splitter_6->addWidget(splitter_3);
        splitter_4 = new QSplitter(splitter_6);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setFont(font3);
        splitter_4->setOrientation(Qt::Horizontal);
        load_teach_btn = new QPushButton(splitter_4);
        load_teach_btn->setObjectName(QStringLiteral("load_teach_btn"));
        load_teach_btn->setMinimumSize(QSize(250, 200));
        splitter_4->addWidget(load_teach_btn);
        load_pres_btn = new QPushButton(splitter_4);
        load_pres_btn->setObjectName(QStringLiteral("load_pres_btn"));
        load_pres_btn->setMinimumSize(QSize(250, 200));
        splitter_4->addWidget(load_pres_btn);
        splitter_6->addWidget(splitter_4);

        gridLayout->addWidget(splitter_6, 1, 1, 1, 1);

        recent_files_area = new QSplitter(LoadWindow);
        recent_files_area->setObjectName(QStringLiteral("recent_files_area"));
        recent_files_area->setOrientation(Qt::Vertical);
        recent_files_lbl = new QLabel(recent_files_area);
        recent_files_lbl->setObjectName(QStringLiteral("recent_files_lbl"));
        recent_files_lbl->setMinimumSize(QSize(0, 40));
        recent_files_lbl->setMaximumSize(QSize(16777215, 40));
        QFont font4;
        font4.setPointSize(12);
        recent_files_lbl->setFont(font4);
        recent_files_lbl->setAlignment(Qt::AlignCenter);
        recent_files_area->addWidget(recent_files_lbl);
        recent_files_list = new QListView(recent_files_area);
        recent_files_list->setObjectName(QStringLiteral("recent_files_list"));
        recent_files_area->addWidget(recent_files_list);
        recent_files_btn = new QPushButton(recent_files_area);
        recent_files_btn->setObjectName(QStringLiteral("recent_files_btn"));
        recent_files_btn->setMinimumSize(QSize(0, 40));
        recent_files_btn->setMaximumSize(QSize(16777215, 40));
        recent_files_area->addWidget(recent_files_btn);

        gridLayout->addWidget(recent_files_area, 1, 0, 1, 1);


        retranslateUi(LoadWindow);

        QMetaObject::connectSlotsByName(LoadWindow);
    } // setupUi

    void retranslateUi(QWidget *LoadWindow)
    {
        LoadWindow->setWindowTitle(QApplication::translate("LoadWindow", "Form", 0));
        load_btn->setText(QApplication::translate("LoadWindow", "LOAD >", 0));
        verify_btn->setText(QApplication::translate("LoadWindow", "VERIFY >", 0));
        analyze_btn->setText(QApplication::translate("LoadWindow", "ANALYZE >", 0));
        file_lbl->setText(QApplication::translate("LoadWindow", "SELECTED FILE:", 0));
        selected_file_lbl->setText(QApplication::translate("LoadWindow", "No File Selected", 0));
        load_pub_btn->setText(QApplication::translate("LoadWindow", "PUBLICATIONS", 0));
        load_grnt_btn->setText(QApplication::translate("LoadWindow", "GRANTS", 0));
        load_teach_btn->setText(QApplication::translate("LoadWindow", "TEACHING", 0));
        load_pres_btn->setText(QApplication::translate("LoadWindow", "PRESENTATIONS", 0));
        recent_files_lbl->setText(QApplication::translate("LoadWindow", "RECENT FILES", 0));
        recent_files_btn->setText(QApplication::translate("LoadWindow", "SELECT RECENT FILE", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadWindow: public Ui_LoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_WINDOW_H
