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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadCSV
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QPushButton *load_btn;
    QPushButton *verify_btn;
    QPushButton *analyze_btn;
    QSplitter *splitter_2;
    QLabel *recent_files_label;
    QListView *recent_files_list;
    QPushButton *loadRecentFile_btn;
    QSplitter *splitter_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *selected_file_lbl;
    QLabel *file_name_load;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *publication_btn;
    QPushButton *grant_btn;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *teaching_btn;
    QPushButton *presentation_btn;

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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        load_btn = new QPushButton(splitter);
        load_btn->setObjectName(QStringLiteral("load_btn"));
        load_btn->setMinimumSize(QSize(250, 50));
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
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        load_btn->setFont(font);
        load_btn->setFlat(true);
        splitter->addWidget(load_btn);
        verify_btn = new QPushButton(splitter);
        verify_btn->setObjectName(QStringLiteral("verify_btn"));
        verify_btn->setMinimumSize(QSize(250, 50));
        verify_btn->setMaximumSize(QSize(16777215, 50));
        QPalette palette2;
        QBrush brush7(QColor(229, 191, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        verify_btn->setPalette(palette2);
        verify_btn->setFont(font);
        verify_btn->setFlat(true);
        splitter->addWidget(verify_btn);
        analyze_btn = new QPushButton(splitter);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));
        analyze_btn->setMinimumSize(QSize(250, 50));
        analyze_btn->setMaximumSize(QSize(16777215, 50));
        QPalette palette3;
        QBrush brush8(QColor(0, 134, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        analyze_btn->setPalette(palette3);
        analyze_btn->setFont(font);
        analyze_btn->setFlat(true);
        splitter->addWidget(analyze_btn);

        gridLayout->addWidget(splitter, 0, 0, 1, 2);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        recent_files_label = new QLabel(splitter_2);
        recent_files_label->setObjectName(QStringLiteral("recent_files_label"));
        recent_files_label->setMinimumSize(QSize(0, 40));
        recent_files_label->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        recent_files_label->setFont(font1);
        recent_files_label->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(recent_files_label);
        recent_files_list = new QListView(splitter_2);
        recent_files_list->setObjectName(QStringLiteral("recent_files_list"));
        recent_files_list->setMaximumSize(QSize(400, 16777215));
        splitter_2->addWidget(recent_files_list);
        loadRecentFile_btn = new QPushButton(splitter_2);
        loadRecentFile_btn->setObjectName(QStringLiteral("loadRecentFile_btn"));
        loadRecentFile_btn->setMinimumSize(QSize(0, 30));
        loadRecentFile_btn->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        loadRecentFile_btn->setFont(font2);
        splitter_2->addWidget(loadRecentFile_btn);

        gridLayout->addWidget(splitter_2, 1, 0, 1, 1);

        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter_3);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        selected_file_lbl = new QLabel(widget);
        selected_file_lbl->setObjectName(QStringLiteral("selected_file_lbl"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selected_file_lbl->sizePolicy().hasHeightForWidth());
        selected_file_lbl->setSizePolicy(sizePolicy);
        selected_file_lbl->setMinimumSize(QSize(110, 40));
        selected_file_lbl->setMaximumSize(QSize(110, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial Black"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        selected_file_lbl->setFont(font3);
        selected_file_lbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        selected_file_lbl->setIndent(10);

        horizontalLayout_3->addWidget(selected_file_lbl);

        file_name_load = new QLabel(widget);
        file_name_load->setObjectName(QStringLiteral("file_name_load"));
        file_name_load->setMinimumSize(QSize(0, 40));
        file_name_load->setMaximumSize(QSize(16777215, 40));
        file_name_load->setScaledContents(false);
        file_name_load->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        file_name_load->setWordWrap(true);

        horizontalLayout_3->addWidget(file_name_load);

        splitter_3->addWidget(widget);
        widget1 = new QWidget(splitter_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        publication_btn = new QPushButton(widget1);
        publication_btn->setObjectName(QStringLiteral("publication_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(publication_btn->sizePolicy().hasHeightForWidth());
        publication_btn->setSizePolicy(sizePolicy1);
        publication_btn->setMinimumSize(QSize(200, 200));
        publication_btn->setFont(font1);

        horizontalLayout->addWidget(publication_btn);

        grant_btn = new QPushButton(widget1);
        grant_btn->setObjectName(QStringLiteral("grant_btn"));
        sizePolicy1.setHeightForWidth(grant_btn->sizePolicy().hasHeightForWidth());
        grant_btn->setSizePolicy(sizePolicy1);
        grant_btn->setMinimumSize(QSize(200, 200));
        grant_btn->setFont(font1);

        horizontalLayout->addWidget(grant_btn);

        splitter_3->addWidget(widget1);
        grant_btn->raise();
        widget2 = new QWidget(splitter_3);
        widget2->setObjectName(QStringLiteral("widget2"));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        teaching_btn = new QPushButton(widget2);
        teaching_btn->setObjectName(QStringLiteral("teaching_btn"));
        sizePolicy1.setHeightForWidth(teaching_btn->sizePolicy().hasHeightForWidth());
        teaching_btn->setSizePolicy(sizePolicy1);
        teaching_btn->setMinimumSize(QSize(200, 200));
        teaching_btn->setFont(font1);

        horizontalLayout_2->addWidget(teaching_btn);

        presentation_btn = new QPushButton(widget2);
        presentation_btn->setObjectName(QStringLiteral("presentation_btn"));
        sizePolicy1.setHeightForWidth(presentation_btn->sizePolicy().hasHeightForWidth());
        presentation_btn->setSizePolicy(sizePolicy1);
        presentation_btn->setMinimumSize(QSize(200, 200));
        presentation_btn->setFont(font1);

        horizontalLayout_2->addWidget(presentation_btn);

        splitter_3->addWidget(widget2);

        gridLayout->addWidget(splitter_3, 1, 1, 1, 1);

        LoadCSV->setCentralWidget(centralwidget);

        retranslateUi(LoadCSV);

        QMetaObject::connectSlotsByName(LoadCSV);
    } // setupUi

    void retranslateUi(QMainWindow *LoadCSV)
    {
        LoadCSV->setWindowTitle(QApplication::translate("LoadCSV", "MainWindow", 0));
        load_btn->setText(QApplication::translate("LoadCSV", "LOAD >", 0));
        verify_btn->setText(QApplication::translate("LoadCSV", "VERIFY >", 0));
        analyze_btn->setText(QApplication::translate("LoadCSV", "ANALYZE >", 0));
        recent_files_label->setText(QApplication::translate("LoadCSV", "RECENT FILES", 0));
        loadRecentFile_btn->setText(QApplication::translate("LoadCSV", "Load Recent File", 0));
        selected_file_lbl->setText(QApplication::translate("LoadCSV", "Selected File:", 0));
        file_name_load->setText(QApplication::translate("LoadCSV", "No file selected", 0));
        publication_btn->setText(QApplication::translate("LoadCSV", "PUBLICATIONS", 0));
        grant_btn->setText(QApplication::translate("LoadCSV", "GRANTS", 0));
        teaching_btn->setText(QApplication::translate("LoadCSV", "TEACHING", 0));
        presentation_btn->setText(QApplication::translate("LoadCSV", "PRESENTATIONS", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadCSV: public Ui_LoadCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_CSV_H