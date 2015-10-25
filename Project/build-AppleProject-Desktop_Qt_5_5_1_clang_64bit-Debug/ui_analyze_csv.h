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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
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
    QWidget *pub_tab;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *tab_area;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *date_filter_lbl;
    QComboBox *start_date1;
    QComboBox *end_date1;
    QPushButton *filter_btn;
    QLabel *domain_lbl1;
    QTreeWidget *pub_tree;
    QVBoxLayout *verticalLayout;
    QComboBox *graph_combo;
    QGraphicsView *graph_area;
    QWidget *grant_tab;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *tab_area_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *date_filter_lbl2;
    QComboBox *date_filter_combo2;
    QPushButton *filter_btn2;
    QLabel *domain_lbl2;
    QTreeWidget *grant_tree;
    QVBoxLayout *verticalLayout_6;
    QComboBox *graph_combo_6;
    QGraphicsView *graph_area_6;
    QWidget *present_tab;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *tab_area_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *date_filter_lbl3;
    QComboBox *date_filter_combo3;
    QPushButton *date_filter_btn3;
    QLabel *domain_lbl3;
    QTreeWidget *present_tree;
    QVBoxLayout *verticalLayout_7;
    QComboBox *graph_combo_7;
    QGraphicsView *graph_area_7;
    QWidget *teach_tab;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *tab_area_8;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *date_filter_lbl4;
    QComboBox *comboBox;
    QPushButton *date_filter_btn4;
    QLabel *domain_lbl4;
    QTreeWidget *teach_tree;
    QVBoxLayout *verticalLayout_8;
    QComboBox *graph_combo_8;
    QGraphicsView *graph_area_8;

    void setupUi(QMainWindow *AnalyzeCSV)
    {
        if (AnalyzeCSV->objectName().isEmpty())
            AnalyzeCSV->setObjectName(QStringLiteral("AnalyzeCSV"));
        AnalyzeCSV->resize(800, 600);
        AnalyzeCSV->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(AnalyzeCSV);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMinimumSize(QSize(900, 600));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 62));
        navigation_area = new QHBoxLayout(horizontalLayoutWidget);
        navigation_area->setObjectName(QStringLiteral("navigation_area"));
        navigation_area->setContentsMargins(0, 0, 0, 0);
        load_btn = new QPushButton(horizontalLayoutWidget);
        load_btn->setObjectName(QStringLiteral("load_btn"));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
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
        QBrush brush2(QColor(229, 191, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        verify_btn->setPalette(palette1);
        verify_btn->setFont(font);
        verify_btn->setFlat(true);

        navigation_area->addWidget(verify_btn);

        analyze_btn = new QPushButton(horizontalLayoutWidget);
        analyze_btn->setObjectName(QStringLiteral("analyze_btn"));
        QPalette palette2;
        QBrush brush3(QColor(0, 170, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        analyze_btn->setPalette(palette2);
        analyze_btn->setFont(font);
        analyze_btn->setFlat(true);

        navigation_area->addWidget(analyze_btn);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 70, 781, 521));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        pub_tab = new QWidget();
        pub_tab->setObjectName(QStringLiteral("pub_tab"));
        QPalette palette3;
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pub_tab->setPalette(palette3);
        pub_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_2 = new QWidget(pub_tab);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 741, 501));
        tab_area = new QHBoxLayout(horizontalLayoutWidget_2);
        tab_area->setObjectName(QStringLiteral("tab_area"));
        tab_area->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        date_filter_lbl = new QLabel(horizontalLayoutWidget_2);
        date_filter_lbl->setObjectName(QStringLiteral("date_filter_lbl"));
        date_filter_lbl->setMinimumSize(QSize(75, 0));
        date_filter_lbl->setMaximumSize(QSize(75, 16777215));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        date_filter_lbl->setPalette(palette4);

        horizontalLayout->addWidget(date_filter_lbl);

        start_date1 = new QComboBox(horizontalLayoutWidget_2);
        start_date1->setObjectName(QStringLiteral("start_date1"));

        horizontalLayout->addWidget(start_date1);

        end_date1 = new QComboBox(horizontalLayoutWidget_2);
        end_date1->setObjectName(QStringLiteral("end_date1"));
        end_date1->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(end_date1);

        filter_btn = new QPushButton(horizontalLayoutWidget_2);
        filter_btn->setObjectName(QStringLiteral("filter_btn"));
        filter_btn->setMinimumSize(QSize(75, 0));
        filter_btn->setMaximumSize(QSize(75, 16777215));
        filter_btn->setFlat(false);

        horizontalLayout->addWidget(filter_btn);


        verticalLayout_2->addLayout(horizontalLayout);

        domain_lbl1 = new QLabel(horizontalLayoutWidget_2);
        domain_lbl1->setObjectName(QStringLiteral("domain_lbl1"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        domain_lbl1->setPalette(palette5);
        domain_lbl1->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(domain_lbl1);

        pub_tree = new QTreeWidget(horizontalLayoutWidget_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        pub_tree->setHeaderItem(__qtreewidgetitem);
        pub_tree->setObjectName(QStringLiteral("pub_tree"));

        verticalLayout_2->addWidget(pub_tree);


        tab_area->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graph_combo = new QComboBox(horizontalLayoutWidget_2);
        graph_combo->setObjectName(QStringLiteral("graph_combo"));

        verticalLayout->addWidget(graph_combo);

        graph_area = new QGraphicsView(horizontalLayoutWidget_2);
        graph_area->setObjectName(QStringLiteral("graph_area"));
        graph_area->setEnabled(true);

        verticalLayout->addWidget(graph_area);


        tab_area->addLayout(verticalLayout);

        tabWidget->addTab(pub_tab, QString());
        grant_tab = new QWidget();
        grant_tab->setObjectName(QStringLiteral("grant_tab"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(0, 85, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        grant_tab->setPalette(palette6);
        grant_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_3 = new QWidget(grant_tab);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 741, 491));
        tab_area_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        tab_area_4->setObjectName(QStringLiteral("tab_area_4"));
        tab_area_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        date_filter_lbl2 = new QLabel(horizontalLayoutWidget_3);
        date_filter_lbl2->setObjectName(QStringLiteral("date_filter_lbl2"));
        date_filter_lbl2->setMinimumSize(QSize(75, 0));
        date_filter_lbl2->setMaximumSize(QSize(75, 16777215));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        date_filter_lbl2->setPalette(palette7);

        horizontalLayout_7->addWidget(date_filter_lbl2);

        date_filter_combo2 = new QComboBox(horizontalLayoutWidget_3);
        date_filter_combo2->setObjectName(QStringLiteral("date_filter_combo2"));

        horizontalLayout_7->addWidget(date_filter_combo2);

        filter_btn2 = new QPushButton(horizontalLayoutWidget_3);
        filter_btn2->setObjectName(QStringLiteral("filter_btn2"));
        filter_btn2->setMinimumSize(QSize(75, 0));
        filter_btn2->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_7->addWidget(filter_btn2);


        verticalLayout_5->addLayout(horizontalLayout_7);

        domain_lbl2 = new QLabel(horizontalLayoutWidget_3);
        domain_lbl2->setObjectName(QStringLiteral("domain_lbl2"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        domain_lbl2->setPalette(palette8);
        domain_lbl2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(domain_lbl2);

        grant_tree = new QTreeWidget(horizontalLayoutWidget_3);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        grant_tree->setHeaderItem(__qtreewidgetitem1);
        grant_tree->setObjectName(QStringLiteral("grant_tree"));

        verticalLayout_5->addWidget(grant_tree);


        tab_area_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        graph_combo_6 = new QComboBox(horizontalLayoutWidget_3);
        graph_combo_6->setObjectName(QStringLiteral("graph_combo_6"));

        verticalLayout_6->addWidget(graph_combo_6);

        graph_area_6 = new QGraphicsView(horizontalLayoutWidget_3);
        graph_area_6->setObjectName(QStringLiteral("graph_area_6"));
        graph_area_6->setEnabled(true);

        verticalLayout_6->addWidget(graph_area_6);


        tab_area_4->addLayout(verticalLayout_6);

        tabWidget->addTab(grant_tab, QString());
        present_tab = new QWidget();
        present_tab->setObjectName(QStringLiteral("present_tab"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush6(QColor(0, 0, 127, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        present_tab->setPalette(palette9);
        present_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_4 = new QWidget(present_tab);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 741, 501));
        tab_area_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        tab_area_5->setObjectName(QStringLiteral("tab_area_5"));
        tab_area_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        date_filter_lbl3 = new QLabel(horizontalLayoutWidget_4);
        date_filter_lbl3->setObjectName(QStringLiteral("date_filter_lbl3"));
        date_filter_lbl3->setMinimumSize(QSize(75, 0));
        date_filter_lbl3->setMaximumSize(QSize(75, 16777215));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        date_filter_lbl3->setPalette(palette10);

        horizontalLayout_8->addWidget(date_filter_lbl3);

        date_filter_combo3 = new QComboBox(horizontalLayoutWidget_4);
        date_filter_combo3->setObjectName(QStringLiteral("date_filter_combo3"));

        horizontalLayout_8->addWidget(date_filter_combo3);

        date_filter_btn3 = new QPushButton(horizontalLayoutWidget_4);
        date_filter_btn3->setObjectName(QStringLiteral("date_filter_btn3"));
        date_filter_btn3->setMinimumSize(QSize(75, 0));
        date_filter_btn3->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_8->addWidget(date_filter_btn3);


        verticalLayout_9->addLayout(horizontalLayout_8);

        domain_lbl3 = new QLabel(horizontalLayoutWidget_4);
        domain_lbl3->setObjectName(QStringLiteral("domain_lbl3"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        domain_lbl3->setPalette(palette11);
        domain_lbl3->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(domain_lbl3);

        present_tree = new QTreeWidget(horizontalLayoutWidget_4);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        present_tree->setHeaderItem(__qtreewidgetitem2);
        present_tree->setObjectName(QStringLiteral("present_tree"));

        verticalLayout_9->addWidget(present_tree);


        tab_area_5->addLayout(verticalLayout_9);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        graph_combo_7 = new QComboBox(horizontalLayoutWidget_4);
        graph_combo_7->setObjectName(QStringLiteral("graph_combo_7"));

        verticalLayout_7->addWidget(graph_combo_7);

        graph_area_7 = new QGraphicsView(horizontalLayoutWidget_4);
        graph_area_7->setObjectName(QStringLiteral("graph_area_7"));
        graph_area_7->setEnabled(true);

        verticalLayout_7->addWidget(graph_area_7);


        tab_area_5->addLayout(verticalLayout_7);

        tabWidget->addTab(present_tab, QString());
        horizontalLayoutWidget_4->raise();
        teach_tab = new QWidget();
        teach_tab->setObjectName(QStringLiteral("teach_tab"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush7(QColor(213, 178, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        teach_tab->setPalette(palette12);
        teach_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_5 = new QWidget(teach_tab);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 10, 741, 501));
        tab_area_8 = new QHBoxLayout(horizontalLayoutWidget_5);
        tab_area_8->setObjectName(QStringLiteral("tab_area_8"));
        tab_area_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        date_filter_lbl4 = new QLabel(horizontalLayoutWidget_5);
        date_filter_lbl4->setObjectName(QStringLiteral("date_filter_lbl4"));
        date_filter_lbl4->setMinimumSize(QSize(75, 0));
        date_filter_lbl4->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_9->addWidget(date_filter_lbl4);

        comboBox = new QComboBox(horizontalLayoutWidget_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_9->addWidget(comboBox);

        date_filter_btn4 = new QPushButton(horizontalLayoutWidget_5);
        date_filter_btn4->setObjectName(QStringLiteral("date_filter_btn4"));
        date_filter_btn4->setMinimumSize(QSize(75, 0));
        date_filter_btn4->setMaximumSize(QSize(75, 16777213));

        horizontalLayout_9->addWidget(date_filter_btn4);


        verticalLayout_10->addLayout(horizontalLayout_9);

        domain_lbl4 = new QLabel(horizontalLayoutWidget_5);
        domain_lbl4->setObjectName(QStringLiteral("domain_lbl4"));
        domain_lbl4->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(domain_lbl4);

        teach_tree = new QTreeWidget(horizontalLayoutWidget_5);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(0, QStringLiteral("1"));
        teach_tree->setHeaderItem(__qtreewidgetitem3);
        teach_tree->setObjectName(QStringLiteral("teach_tree"));

        verticalLayout_10->addWidget(teach_tree);


        tab_area_8->addLayout(verticalLayout_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        graph_combo_8 = new QComboBox(horizontalLayoutWidget_5);
        graph_combo_8->setObjectName(QStringLiteral("graph_combo_8"));

        verticalLayout_8->addWidget(graph_combo_8);

        graph_area_8 = new QGraphicsView(horizontalLayoutWidget_5);
        graph_area_8->setObjectName(QStringLiteral("graph_area_8"));
        graph_area_8->setEnabled(true);

        verticalLayout_8->addWidget(graph_area_8);


        tab_area_8->addLayout(verticalLayout_8);

        tabWidget->addTab(teach_tab, QString());
        AnalyzeCSV->setCentralWidget(centralwidget);

        retranslateUi(AnalyzeCSV);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnalyzeCSV);
    } // setupUi

    void retranslateUi(QMainWindow *AnalyzeCSV)
    {
        AnalyzeCSV->setWindowTitle(QApplication::translate("AnalyzeCSV", "MainWindow", 0));
        load_btn->setText(QApplication::translate("AnalyzeCSV", "LOAD >", 0));
        verify_btn->setText(QApplication::translate("AnalyzeCSV", "VERIFY >", 0));
        analyze_btn->setText(QApplication::translate("AnalyzeCSV", "ANALYZE >", 0));
        date_filter_lbl->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        filter_btn->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl1->setText(QApplication::translate("AnalyzeCSV", "Department of Medecine - Summary", 0));
        graph_combo->clear();
        graph_combo->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(pub_tab), QApplication::translate("AnalyzeCSV", "PUBLICATIONS", 0));
        date_filter_lbl2->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        filter_btn2->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl2->setText(QString());
        graph_combo_6->clear();
        graph_combo_6->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(grant_tab), QApplication::translate("AnalyzeCSV", "GRANTS", 0));
        date_filter_lbl3->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        date_filter_btn3->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl3->setText(QString());
        graph_combo_7->clear();
        graph_combo_7->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(present_tab), QApplication::translate("AnalyzeCSV", "PRESENTATIONS", 0));
        date_filter_lbl4->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        date_filter_btn4->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl4->setText(QString());
        graph_combo_8->clear();
        graph_combo_8->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(teach_tab), QApplication::translate("AnalyzeCSV", "TEACHING", 0));
    } // retranslateUi

};

namespace Ui {
    class AnalyzeCSV: public Ui_AnalyzeCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZE_CSV_H
