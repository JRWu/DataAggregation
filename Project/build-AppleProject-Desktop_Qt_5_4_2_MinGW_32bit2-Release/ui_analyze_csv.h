/********************************************************************************
** Form generated from reading UI file 'analyze_csv.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
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
    QPushButton *load_btn;
    QPushButton *verify_btn;
    QPushButton *analyze_btn;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *tab_area;
    QTreeView *publications_tree;
    QVBoxLayout *verticalLayout;
    QComboBox *graph_combo;
    QToolBox *toolBox;
    QWidget *page;
    QPlainTextEdit *plainTextEdit;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *page_4;
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
        AnalyzeCSV->resize(900, 643);
        centralwidget = new QWidget(AnalyzeCSV);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(900, 600));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 781, 80));
        navigation_area = new QHBoxLayout(horizontalLayoutWidget);
        navigation_area->setObjectName(QStringLiteral("navigation_area"));
        navigation_area->setContentsMargins(0, 0, 0, 0);
        load_btn = new QPushButton(horizontalLayoutWidget);
        load_btn->setObjectName(QStringLiteral("load_btn"));
        QPalette palette;
        QBrush brush(QColor(221, 221, 221, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        load_btn->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        load_btn->setFont(font);
        load_btn->setFlat(true);

        navigation_area->addWidget(load_btn);

        verify_btn = new QPushButton(horizontalLayoutWidget);
        verify_btn->setObjectName(QStringLiteral("verify_btn"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        verify_btn->setPalette(palette1);
        verify_btn->setFont(font);
        verify_btn->setFlat(true);

        navigation_area->addWidget(verify_btn);

        analyze_btn = new QPushButton(horizontalLayoutWidget);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));
        QPalette palette2;
        QBrush brush2(QColor(0, 170, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        analyze_btn->setPalette(palette2);
        analyze_btn->setFont(font);
        analyze_btn->setFlat(true);

        navigation_area->addWidget(analyze_btn);

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

        toolBox = new QToolBox(horizontalLayoutWidget_2);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 373, 83));
        plainTextEdit = new QPlainTextEdit(page);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 10, 381, 79));
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 373, 83));
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        toolBox->addItem(page_3, QStringLiteral("Page 3"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        toolBox->addItem(page_4, QStringLiteral("Page 4"));

        verticalLayout->addWidget(toolBox);

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
        menubar->setGeometry(QRect(0, 0, 900, 22));
        AnalyzeCSV->setMenuBar(menubar);
        statusbar = new QStatusBar(AnalyzeCSV);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AnalyzeCSV->setStatusBar(statusbar);

        retranslateUi(AnalyzeCSV);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnalyzeCSV);
    } // setupUi

    void retranslateUi(QMainWindow *AnalyzeCSV)
    {
        AnalyzeCSV->setWindowTitle(QApplication::translate("AnalyzeCSV", "MainWindow", 0));
        load_btn->setText(QApplication::translate("AnalyzeCSV", "LOAD >", 0));
        verify_btn->setText(QApplication::translate("AnalyzeCSV", "VERIFY >", 0));
        analyze_btn->setText(QApplication::translate("AnalyzeCSV", "ANALYZE >", 0));
#ifndef QT_NO_ACCESSIBILITY
        page->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        page->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        plainTextEdit->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 1 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("AnalyzeCSV", "Page 1", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("AnalyzeCSV", "Page 2", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("AnalyzeCSV", "Page 3", 0));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("AnalyzeCSV", "Page 4", 0));
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
