/********************************************************************************
** Form generated from reading UI file 'analyze_csv.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZE_CSV_H
#define UI_ANALYZE_CSV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnalyzeCSV
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *navigation_area;
    QLabel *load_label;
    QLabel *verify_label;
    QLabel *analyze_label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *tab_area;
    QTreeView *publications_tree;
    QVBoxLayout *verticalLayout;
    QComboBox *graph_combo;
    QGraphicsView *graph_area;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnalyzeCSV)
    {
        if (AnalyzeCSV->objectName().isEmpty())
            AnalyzeCSV->setObjectName(QStringLiteral("AnalyzeCSV"));
        AnalyzeCSV->resize(800, 600);
        centralwidget = new QWidget(AnalyzeCSV);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(900, 600));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 781, 80));
        navigation_area = new QHBoxLayout(horizontalLayoutWidget);
        navigation_area->setObjectName(QStringLiteral("navigation_area"));
        navigation_area->setContentsMargins(0, 0, 0, 0);
        load_label = new QLabel(horizontalLayoutWidget);
        load_label->setObjectName(QStringLiteral("load_label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setBold(true);
        font.setWeight(75);
        load_label->setFont(font);

        navigation_area->addWidget(load_label);

        verify_label = new QLabel(horizontalLayoutWidget);
        verify_label->setObjectName(QStringLiteral("verify_label"));
        verify_label->setFont(font);

        navigation_area->addWidget(verify_label);

        analyze_label = new QLabel(horizontalLayoutWidget);
        analyze_label->setObjectName(QStringLiteral("analyze_label"));
        analyze_label->setFont(font);

        navigation_area->addWidget(analyze_label);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 90, 781, 471));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 9, 741, 451));
        tab_area = new QHBoxLayout(horizontalLayoutWidget_2);
        tab_area->setObjectName(QStringLiteral("tab_area"));
        tab_area->setContentsMargins(0, 0, 0, 0);
        publications_tree = new QTreeView(horizontalLayoutWidget_2);
        publications_tree->setObjectName(QStringLiteral("publications_tree"));
        publications_tree->setMaximumSize(QSize(350, 16777215));

        tab_area->addWidget(publications_tree);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graph_combo = new QComboBox(horizontalLayoutWidget_2);
        graph_combo->setObjectName(QStringLiteral("graph_combo"));

        verticalLayout->addWidget(graph_combo);

        graph_area = new QGraphicsView(horizontalLayoutWidget_2);
        graph_area->setObjectName(QStringLiteral("graph_area"));

        verticalLayout->addWidget(graph_area);


        tab_area->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        AnalyzeCSV->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnalyzeCSV);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AnalyzeCSV->setMenuBar(menubar);
        statusbar = new QStatusBar(AnalyzeCSV);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AnalyzeCSV->setStatusBar(statusbar);

        retranslateUi(AnalyzeCSV);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnalyzeCSV);
    } // setupUi

    void retranslateUi(QMainWindow *AnalyzeCSV)
    {
        AnalyzeCSV->setWindowTitle(QApplication::translate("AnalyzeCSV", "MainWindow", 0));
        load_label->setText(QApplication::translate("AnalyzeCSV", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#aaaa7f;\">LOAD &gt;</span></p></body></html>", 0));
        verify_label->setText(QApplication::translate("AnalyzeCSV", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#aaaa7f;\">VERIFY &gt;</span></p></body></html>", 0));
        analyze_label->setText(QApplication::translate("AnalyzeCSV", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#00aa00;\">ANALYZE &gt;</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AnalyzeCSV", "PUBLICATIONS", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AnalyzeCSV", "GRANTS", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("AnalyzeCSV", "PRESENTATIONS", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("AnalyzeCSV", "TEACHING", 0));
    } // retranslateUi

};

namespace Ui {
    class AnalyzeCSV: public Ui_AnalyzeCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_CSV_H
