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
    QComboBox *start_date_publications;
    QComboBox *end_date_publications;
    QPushButton *filter_btn;
    QLabel *domain_lbl1;
    QTreeWidget *pub_tree;
    QVBoxLayout *verticalLayout;
    QLabel *graph_lbl_pub;
    QHBoxLayout *horizontalLayout_14;
    QLabel *name_lbl_pub;
    QComboBox *name_combo_pub;
    QHBoxLayout *horizontalLayout_13;
    QLabel *type_lbl_pub;
    QComboBox *type_combo_pub;
    QGraphicsView *graph_area;
    QWidget *grant_tab;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *tab_area_6;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *date_filter_lbl3_2;
    QComboBox *start_date1_2;
    QComboBox *end_date1_2;
    QPushButton *filter_btn_2;
    QLabel *domain_lbl3_2;
    QTreeWidget *present_tree_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *graph_lbl_grnt;
    QHBoxLayout *horizontalLayout_2;
    QLabel *name_lbl_grnt;
    QComboBox *name_combo_grnt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *type_lbl_grnt;
    QComboBox *type_combo_grnt;
    QGraphicsView *graph_area_9;
    QWidget *present_tab;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *tab_area_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *date_filter_lbl_presentation;
    QComboBox *start_date_presentation;
    QComboBox *end_date_presentation;
    QPushButton *filter_btn_presentation;
    QLabel *domain_lbl_presentation;
    QTreeWidget *present_tree;
    QVBoxLayout *verticalLayout_7;
    QLabel *graph_lbl_pres;
    QHBoxLayout *horizontalLayout_4;
    QLabel *name_lbl_pres;
    QComboBox *name_combo_pres;
    QHBoxLayout *horizontalLayout_5;
    QLabel *type_lbl_pres;
    QComboBox *type_combo_pres;
    QGraphicsView *graph_area_7;
    QWidget *teach_tab;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *tab_area_4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *date_filter_lbl_teach;
    QComboBox *start_date_teach;
    QComboBox *end_date_teach;
    QPushButton *filter_btn_teaching;
    QLabel *domain_lbl_teach;
    QTreeWidget *teach_tree;
    QVBoxLayout *verticalLayout_8;
    QComboBox *graph_combo_teach;
    QGraphicsView *graph_area_teach;

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

        start_date_publications = new QComboBox(horizontalLayoutWidget_2);
        start_date_publications->setObjectName(QStringLiteral("start_date_publications"));

        horizontalLayout->addWidget(start_date_publications);

        end_date_publications = new QComboBox(horizontalLayoutWidget_2);
        end_date_publications->setObjectName(QStringLiteral("end_date_publications"));
        end_date_publications->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(end_date_publications);

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
        graph_lbl_pub = new QLabel(horizontalLayoutWidget_2);
        graph_lbl_pub->setObjectName(QStringLiteral("graph_lbl_pub"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        graph_lbl_pub->setPalette(palette6);
        graph_lbl_pub->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(graph_lbl_pub);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        name_lbl_pub = new QLabel(horizontalLayoutWidget_2);
        name_lbl_pub->setObjectName(QStringLiteral("name_lbl_pub"));
        name_lbl_pub->setMaximumSize(QSize(100, 40));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name_lbl_pub->setPalette(palette7);

        horizontalLayout_14->addWidget(name_lbl_pub);

        name_combo_pub = new QComboBox(horizontalLayoutWidget_2);
        name_combo_pub->setObjectName(QStringLiteral("name_combo_pub"));

        horizontalLayout_14->addWidget(name_combo_pub);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        type_lbl_pub = new QLabel(horizontalLayoutWidget_2);
        type_lbl_pub->setObjectName(QStringLiteral("type_lbl_pub"));
        type_lbl_pub->setMaximumSize(QSize(100, 40));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        type_lbl_pub->setPalette(palette8);

        horizontalLayout_13->addWidget(type_lbl_pub);

        type_combo_pub = new QComboBox(horizontalLayoutWidget_2);
        type_combo_pub->setObjectName(QStringLiteral("type_combo_pub"));

        horizontalLayout_13->addWidget(type_combo_pub);


        verticalLayout->addLayout(horizontalLayout_13);

        graph_area = new QGraphicsView(horizontalLayoutWidget_2);
        graph_area->setObjectName(QStringLiteral("graph_area"));
        graph_area->setEnabled(true);

        verticalLayout->addWidget(graph_area);


        tab_area->addLayout(verticalLayout);

        tabWidget->addTab(pub_tab, QString());
        grant_tab = new QWidget();
        grant_tab->setObjectName(QStringLiteral("grant_tab"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(0, 85, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        grant_tab->setPalette(palette9);
        grant_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_6 = new QWidget(grant_tab);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 10, 741, 501));
        tab_area_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        tab_area_6->setObjectName(QStringLiteral("tab_area_6"));
        tab_area_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        date_filter_lbl3_2 = new QLabel(horizontalLayoutWidget_6);
        date_filter_lbl3_2->setObjectName(QStringLiteral("date_filter_lbl3_2"));
        date_filter_lbl3_2->setMinimumSize(QSize(75, 0));
        date_filter_lbl3_2->setMaximumSize(QSize(75, 16777215));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        date_filter_lbl3_2->setPalette(palette10);

        horizontalLayout_10->addWidget(date_filter_lbl3_2);

        start_date1_2 = new QComboBox(horizontalLayoutWidget_6);
        start_date1_2->setObjectName(QStringLiteral("start_date1_2"));

        horizontalLayout_10->addWidget(start_date1_2);

        end_date1_2 = new QComboBox(horizontalLayoutWidget_6);
        end_date1_2->setObjectName(QStringLiteral("end_date1_2"));
        end_date1_2->setMinimumSize(QSize(0, 0));

        horizontalLayout_10->addWidget(end_date1_2);

        filter_btn_2 = new QPushButton(horizontalLayoutWidget_6);
        filter_btn_2->setObjectName(QStringLiteral("filter_btn_2"));
        filter_btn_2->setMinimumSize(QSize(75, 0));
        filter_btn_2->setMaximumSize(QSize(75, 16777215));
        filter_btn_2->setFlat(false);

        horizontalLayout_10->addWidget(filter_btn_2);


        verticalLayout_11->addLayout(horizontalLayout_10);

        domain_lbl3_2 = new QLabel(horizontalLayoutWidget_6);
        domain_lbl3_2->setObjectName(QStringLiteral("domain_lbl3_2"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        domain_lbl3_2->setPalette(palette11);
        domain_lbl3_2->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(domain_lbl3_2);

        present_tree_2 = new QTreeWidget(horizontalLayoutWidget_6);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        present_tree_2->setHeaderItem(__qtreewidgetitem1);
        present_tree_2->setObjectName(QStringLiteral("present_tree_2"));

        verticalLayout_11->addWidget(present_tree_2);


        tab_area_6->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        graph_lbl_grnt = new QLabel(horizontalLayoutWidget_6);
        graph_lbl_grnt->setObjectName(QStringLiteral("graph_lbl_grnt"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        graph_lbl_grnt->setPalette(palette12);
        graph_lbl_grnt->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(graph_lbl_grnt);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        name_lbl_grnt = new QLabel(horizontalLayoutWidget_6);
        name_lbl_grnt->setObjectName(QStringLiteral("name_lbl_grnt"));
        name_lbl_grnt->setMaximumSize(QSize(100, 40));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name_lbl_grnt->setPalette(palette13);

        horizontalLayout_2->addWidget(name_lbl_grnt);

        name_combo_grnt = new QComboBox(horizontalLayoutWidget_6);
        name_combo_grnt->setObjectName(QStringLiteral("name_combo_grnt"));

        horizontalLayout_2->addWidget(name_combo_grnt);


        verticalLayout_12->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        type_lbl_grnt = new QLabel(horizontalLayoutWidget_6);
        type_lbl_grnt->setObjectName(QStringLiteral("type_lbl_grnt"));
        type_lbl_grnt->setMaximumSize(QSize(100, 40));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        type_lbl_grnt->setPalette(palette14);

        horizontalLayout_3->addWidget(type_lbl_grnt);

        type_combo_grnt = new QComboBox(horizontalLayoutWidget_6);
        type_combo_grnt->setObjectName(QStringLiteral("type_combo_grnt"));

        horizontalLayout_3->addWidget(type_combo_grnt);


        verticalLayout_12->addLayout(horizontalLayout_3);

        graph_area_9 = new QGraphicsView(horizontalLayoutWidget_6);
        graph_area_9->setObjectName(QStringLiteral("graph_area_9"));
        graph_area_9->setEnabled(true);

        verticalLayout_12->addWidget(graph_area_9);


        tab_area_6->addLayout(verticalLayout_12);

        tabWidget->addTab(grant_tab, QString());
        present_tab = new QWidget();
        present_tab->setObjectName(QStringLiteral("present_tab"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush6(QColor(0, 0, 127, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        present_tab->setPalette(palette15);
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
        date_filter_lbl_presentation = new QLabel(horizontalLayoutWidget_4);
        date_filter_lbl_presentation->setObjectName(QStringLiteral("date_filter_lbl_presentation"));
        date_filter_lbl_presentation->setMinimumSize(QSize(75, 0));
        date_filter_lbl_presentation->setMaximumSize(QSize(75, 16777215));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        date_filter_lbl_presentation->setPalette(palette16);

        horizontalLayout_8->addWidget(date_filter_lbl_presentation);

        start_date_presentation = new QComboBox(horizontalLayoutWidget_4);
        start_date_presentation->setObjectName(QStringLiteral("start_date_presentation"));

        horizontalLayout_8->addWidget(start_date_presentation);

        end_date_presentation = new QComboBox(horizontalLayoutWidget_4);
        end_date_presentation->setObjectName(QStringLiteral("end_date_presentation"));
        end_date_presentation->setMinimumSize(QSize(0, 0));

        horizontalLayout_8->addWidget(end_date_presentation);

        filter_btn_presentation = new QPushButton(horizontalLayoutWidget_4);
        filter_btn_presentation->setObjectName(QStringLiteral("filter_btn_presentation"));
        filter_btn_presentation->setMinimumSize(QSize(75, 0));
        filter_btn_presentation->setMaximumSize(QSize(75, 16777215));
        filter_btn_presentation->setFlat(false);

        horizontalLayout_8->addWidget(filter_btn_presentation);


        verticalLayout_9->addLayout(horizontalLayout_8);

        domain_lbl_presentation = new QLabel(horizontalLayoutWidget_4);
        domain_lbl_presentation->setObjectName(QStringLiteral("domain_lbl_presentation"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        domain_lbl_presentation->setPalette(palette17);
        domain_lbl_presentation->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(domain_lbl_presentation);

        present_tree = new QTreeWidget(horizontalLayoutWidget_4);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        present_tree->setHeaderItem(__qtreewidgetitem2);
        present_tree->setObjectName(QStringLiteral("present_tree"));

        verticalLayout_9->addWidget(present_tree);


        tab_area_5->addLayout(verticalLayout_9);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        graph_lbl_pres = new QLabel(horizontalLayoutWidget_4);
        graph_lbl_pres->setObjectName(QStringLiteral("graph_lbl_pres"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        graph_lbl_pres->setPalette(palette18);
        graph_lbl_pres->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(graph_lbl_pres);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        name_lbl_pres = new QLabel(horizontalLayoutWidget_4);
        name_lbl_pres->setObjectName(QStringLiteral("name_lbl_pres"));
        name_lbl_pres->setMaximumSize(QSize(100, 40));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name_lbl_pres->setPalette(palette19);

        horizontalLayout_4->addWidget(name_lbl_pres);

        name_combo_pres = new QComboBox(horizontalLayoutWidget_4);
        name_combo_pres->setObjectName(QStringLiteral("name_combo_pres"));

        horizontalLayout_4->addWidget(name_combo_pres);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        type_lbl_pres = new QLabel(horizontalLayoutWidget_4);
        type_lbl_pres->setObjectName(QStringLiteral("type_lbl_pres"));
        type_lbl_pres->setMaximumSize(QSize(100, 40));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        type_lbl_pres->setPalette(palette20);

        horizontalLayout_5->addWidget(type_lbl_pres);

        type_combo_pres = new QComboBox(horizontalLayoutWidget_4);
        type_combo_pres->setObjectName(QStringLiteral("type_combo_pres"));

        horizontalLayout_5->addWidget(type_combo_pres);


        verticalLayout_7->addLayout(horizontalLayout_5);

        graph_area_7 = new QGraphicsView(horizontalLayoutWidget_4);
        graph_area_7->setObjectName(QStringLiteral("graph_area_7"));
        graph_area_7->setEnabled(true);

        verticalLayout_7->addWidget(graph_area_7);


        tab_area_5->addLayout(verticalLayout_7);

        tabWidget->addTab(present_tab, QString());
        teach_tab = new QWidget();
        teach_tab->setObjectName(QStringLiteral("teach_tab"));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush7(QColor(213, 178, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        teach_tab->setPalette(palette21);
        teach_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_5 = new QWidget(teach_tab);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 10, 741, 501));
        tab_area_4 = new QHBoxLayout(horizontalLayoutWidget_5);
        tab_area_4->setObjectName(QStringLiteral("tab_area_4"));
        tab_area_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        date_filter_lbl_teach = new QLabel(horizontalLayoutWidget_5);
        date_filter_lbl_teach->setObjectName(QStringLiteral("date_filter_lbl_teach"));
        date_filter_lbl_teach->setMinimumSize(QSize(75, 0));
        date_filter_lbl_teach->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_9->addWidget(date_filter_lbl_teach);

        start_date_teach = new QComboBox(horizontalLayoutWidget_5);
        start_date_teach->setObjectName(QStringLiteral("start_date_teach"));

        horizontalLayout_9->addWidget(start_date_teach);

        end_date_teach = new QComboBox(horizontalLayoutWidget_5);
        end_date_teach->setObjectName(QStringLiteral("end_date_teach"));
        end_date_teach->setMinimumSize(QSize(0, 0));

        horizontalLayout_9->addWidget(end_date_teach);

        filter_btn_teaching = new QPushButton(horizontalLayoutWidget_5);
        filter_btn_teaching->setObjectName(QStringLiteral("filter_btn_teaching"));
        filter_btn_teaching->setMinimumSize(QSize(75, 0));
        filter_btn_teaching->setMaximumSize(QSize(75, 16777215));
        filter_btn_teaching->setFlat(false);

        horizontalLayout_9->addWidget(filter_btn_teaching);


        verticalLayout_10->addLayout(horizontalLayout_9);

        domain_lbl_teach = new QLabel(horizontalLayoutWidget_5);
        domain_lbl_teach->setObjectName(QStringLiteral("domain_lbl_teach"));
        domain_lbl_teach->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(domain_lbl_teach);

        teach_tree = new QTreeWidget(horizontalLayoutWidget_5);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(0, QStringLiteral("1"));
        teach_tree->setHeaderItem(__qtreewidgetitem3);
        teach_tree->setObjectName(QStringLiteral("teach_tree"));

        verticalLayout_10->addWidget(teach_tree);


        tab_area_4->addLayout(verticalLayout_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        graph_combo_teach = new QComboBox(horizontalLayoutWidget_5);
        graph_combo_teach->setObjectName(QStringLiteral("graph_combo_teach"));

        verticalLayout_8->addWidget(graph_combo_teach);

        graph_area_teach = new QGraphicsView(horizontalLayoutWidget_5);
        graph_area_teach->setObjectName(QStringLiteral("graph_area_teach"));
        graph_area_teach->setEnabled(true);

        verticalLayout_8->addWidget(graph_area_teach);


        tab_area_4->addLayout(verticalLayout_8);

        tabWidget->addTab(teach_tab, QString());
        AnalyzeCSV->setCentralWidget(centralwidget);

        retranslateUi(AnalyzeCSV);

        tabWidget->setCurrentIndex(2);
        type_combo_pub->setCurrentIndex(-1);
        name_combo_grnt->setCurrentIndex(-1);
        name_combo_pres->setCurrentIndex(-1);


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
        domain_lbl1->setText(QString());
        graph_lbl_pub->setText(QApplication::translate("AnalyzeCSV", "Graph Analytics", 0));
        name_lbl_pub->setText(QApplication::translate("AnalyzeCSV", "Name:", 0));
        type_lbl_pub->setText(QApplication::translate("AnalyzeCSV", "Type:", 0));
        type_combo_pub->clear();
        type_combo_pub->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(pub_tab), QApplication::translate("AnalyzeCSV", "PUBLICATIONS", 0));
        date_filter_lbl3_2->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        filter_btn_2->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl3_2->setText(QString());
        graph_lbl_grnt->setText(QApplication::translate("AnalyzeCSV", "Graph Analytics", 0));
        name_lbl_grnt->setText(QApplication::translate("AnalyzeCSV", "Name:", 0));
        name_combo_grnt->clear();
        name_combo_grnt->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        name_combo_grnt->setCurrentText(QString());
        type_lbl_grnt->setText(QApplication::translate("AnalyzeCSV", "Funding Type:", 0));
        tabWidget->setTabText(tabWidget->indexOf(grant_tab), QApplication::translate("AnalyzeCSV", "GRANTS", 0));
        date_filter_lbl_presentation->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        filter_btn_presentation->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl_presentation->setText(QString());
        graph_lbl_pres->setText(QApplication::translate("AnalyzeCSV", "Graph Analytics", 0));
        name_lbl_pres->setText(QApplication::translate("AnalyzeCSV", "Name:", 0));
        name_combo_pres->clear();
        name_combo_pres->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        type_lbl_pres->setText(QApplication::translate("AnalyzeCSV", "Type:", 0));
        tabWidget->setTabText(tabWidget->indexOf(present_tab), QApplication::translate("AnalyzeCSV", "PRESENTATIONS", 0));
        date_filter_lbl_teach->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        filter_btn_teaching->setText(QApplication::translate("AnalyzeCSV", "Filter", 0));
        domain_lbl_teach->setText(QString());
        graph_combo_teach->clear();
        graph_combo_teach->insertItems(0, QStringList()
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
