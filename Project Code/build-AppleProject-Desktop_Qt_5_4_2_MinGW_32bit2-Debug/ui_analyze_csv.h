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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
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
    QComboBox *date_filter_combo;
    QLabel *domain_lbl;
    QTreeWidget *pub_tree;
    QVBoxLayout *verticalLayout;
    QComboBox *graph_combo;
    QGraphicsView *graph_area;
    QWidget *grant_tab;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *tab_area_4;
    QToolBox *toolBox_6;
    QWidget *page_21;
    QPlainTextEdit *plainTextEdit_21;
    QWidget *page_22;
    QPlainTextEdit *plainTextEdit_22;
    QWidget *page_23;
    QPlainTextEdit *plainTextEdit_23;
    QWidget *page_24;
    QPlainTextEdit *plainTextEdit_24;
    QVBoxLayout *verticalLayout_6;
    QComboBox *graph_combo_6;
    QGraphicsView *graph_area_6;
    QWidget *present_tab;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *tab_area_5;
    QToolBox *toolBox_7;
    QWidget *page_25;
    QPlainTextEdit *plainTextEdit_25;
    QWidget *page_26;
    QPlainTextEdit *plainTextEdit_26;
    QWidget *page_27;
    QPlainTextEdit *plainTextEdit_27;
    QWidget *page_28;
    QPlainTextEdit *plainTextEdit_28;
    QVBoxLayout *verticalLayout_7;
    QComboBox *graph_combo_7;
    QGraphicsView *graph_area_7;
    QWidget *teach_tab;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *tab_area_8;
    QToolBox *toolBox_8;
    QWidget *page_29;
    QPlainTextEdit *plainTextEdit_29;
    QWidget *page_30;
    QPlainTextEdit *plainTextEdit_30;
    QWidget *page_31;
    QPlainTextEdit *plainTextEdit_31;
    QWidget *page_32;
    QPlainTextEdit *plainTextEdit_32;
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
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 51));
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
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush4);
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
        date_filter_lbl->setMinimumSize(QSize(50, 0));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        date_filter_lbl->setPalette(palette4);

        horizontalLayout->addWidget(date_filter_lbl);

        date_filter_combo = new QComboBox(horizontalLayoutWidget_2);
        date_filter_combo->setObjectName(QStringLiteral("date_filter_combo"));
        date_filter_combo->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(date_filter_combo);


        verticalLayout_2->addLayout(horizontalLayout);

        domain_lbl = new QLabel(horizontalLayoutWidget_2);
        domain_lbl->setObjectName(QStringLiteral("domain_lbl"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        domain_lbl->setPalette(palette5);
        domain_lbl->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(domain_lbl);

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
        palette6.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush5(QColor(0, 85, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        grant_tab->setPalette(palette6);
        grant_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_3 = new QWidget(grant_tab);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 40, 751, 421));
        tab_area_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        tab_area_4->setObjectName(QStringLiteral("tab_area_4"));
        tab_area_4->setContentsMargins(0, 0, 0, 0);
        toolBox_6 = new QToolBox(horizontalLayoutWidget_3);
        toolBox_6->setObjectName(QStringLiteral("toolBox_6"));
        page_21 = new QWidget();
        page_21->setObjectName(QStringLiteral("page_21"));
        page_21->setGeometry(QRect(0, 0, 372, 303));
        plainTextEdit_21 = new QPlainTextEdit(page_21);
        plainTextEdit_21->setObjectName(QStringLiteral("plainTextEdit_21"));
        plainTextEdit_21->setGeometry(QRect(0, 10, 381, 341));
        toolBox_6->addItem(page_21, QStringLiteral("Page 1"));
        page_22 = new QWidget();
        page_22->setObjectName(QStringLiteral("page_22"));
        page_22->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_22 = new QPlainTextEdit(page_22);
        plainTextEdit_22->setObjectName(QStringLiteral("plainTextEdit_22"));
        plainTextEdit_22->setGeometry(QRect(0, 0, 381, 341));
        toolBox_6->addItem(page_22, QStringLiteral("Page 2"));
        page_23 = new QWidget();
        page_23->setObjectName(QStringLiteral("page_23"));
        page_23->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_23 = new QPlainTextEdit(page_23);
        plainTextEdit_23->setObjectName(QStringLiteral("plainTextEdit_23"));
        plainTextEdit_23->setGeometry(QRect(0, 0, 381, 341));
        toolBox_6->addItem(page_23, QStringLiteral("Page 3"));
        page_24 = new QWidget();
        page_24->setObjectName(QStringLiteral("page_24"));
        page_24->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_24 = new QPlainTextEdit(page_24);
        plainTextEdit_24->setObjectName(QStringLiteral("plainTextEdit_24"));
        plainTextEdit_24->setGeometry(QRect(0, 0, 381, 341));
        toolBox_6->addItem(page_24, QStringLiteral("Page 4"));

        tab_area_4->addWidget(toolBox_6);

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
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush6(QColor(0, 0, 127, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        present_tab->setPalette(palette7);
        present_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_4 = new QWidget(present_tab);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 40, 751, 421));
        tab_area_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        tab_area_5->setObjectName(QStringLiteral("tab_area_5"));
        tab_area_5->setContentsMargins(0, 0, 0, 0);
        toolBox_7 = new QToolBox(horizontalLayoutWidget_4);
        toolBox_7->setObjectName(QStringLiteral("toolBox_7"));
        page_25 = new QWidget();
        page_25->setObjectName(QStringLiteral("page_25"));
        page_25->setGeometry(QRect(0, 0, 372, 303));
        plainTextEdit_25 = new QPlainTextEdit(page_25);
        plainTextEdit_25->setObjectName(QStringLiteral("plainTextEdit_25"));
        plainTextEdit_25->setGeometry(QRect(0, 10, 381, 341));
        toolBox_7->addItem(page_25, QStringLiteral("Page 1"));
        page_26 = new QWidget();
        page_26->setObjectName(QStringLiteral("page_26"));
        page_26->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_26 = new QPlainTextEdit(page_26);
        plainTextEdit_26->setObjectName(QStringLiteral("plainTextEdit_26"));
        plainTextEdit_26->setGeometry(QRect(0, 0, 381, 341));
        toolBox_7->addItem(page_26, QStringLiteral("Page 2"));
        page_27 = new QWidget();
        page_27->setObjectName(QStringLiteral("page_27"));
        page_27->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_27 = new QPlainTextEdit(page_27);
        plainTextEdit_27->setObjectName(QStringLiteral("plainTextEdit_27"));
        plainTextEdit_27->setGeometry(QRect(0, 0, 381, 341));
        toolBox_7->addItem(page_27, QStringLiteral("Page 3"));
        page_28 = new QWidget();
        page_28->setObjectName(QStringLiteral("page_28"));
        page_28->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_28 = new QPlainTextEdit(page_28);
        plainTextEdit_28->setObjectName(QStringLiteral("plainTextEdit_28"));
        plainTextEdit_28->setGeometry(QRect(0, 0, 381, 341));
        toolBox_7->addItem(page_28, QStringLiteral("Page 4"));

        tab_area_5->addWidget(toolBox_7);

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
        teach_tab = new QWidget();
        teach_tab->setObjectName(QStringLiteral("teach_tab"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush7(QColor(213, 178, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        teach_tab->setPalette(palette8);
        teach_tab->setAutoFillBackground(true);
        horizontalLayoutWidget_5 = new QWidget(teach_tab);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(0, 40, 751, 421));
        tab_area_8 = new QHBoxLayout(horizontalLayoutWidget_5);
        tab_area_8->setObjectName(QStringLiteral("tab_area_8"));
        tab_area_8->setContentsMargins(0, 0, 0, 0);
        toolBox_8 = new QToolBox(horizontalLayoutWidget_5);
        toolBox_8->setObjectName(QStringLiteral("toolBox_8"));
        page_29 = new QWidget();
        page_29->setObjectName(QStringLiteral("page_29"));
        page_29->setGeometry(QRect(0, 0, 372, 303));
        plainTextEdit_29 = new QPlainTextEdit(page_29);
        plainTextEdit_29->setObjectName(QStringLiteral("plainTextEdit_29"));
        plainTextEdit_29->setGeometry(QRect(0, 10, 381, 341));
        toolBox_8->addItem(page_29, QStringLiteral("Page 1"));
        page_30 = new QWidget();
        page_30->setObjectName(QStringLiteral("page_30"));
        page_30->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_30 = new QPlainTextEdit(page_30);
        plainTextEdit_30->setObjectName(QStringLiteral("plainTextEdit_30"));
        plainTextEdit_30->setGeometry(QRect(0, 0, 381, 341));
        toolBox_8->addItem(page_30, QStringLiteral("Page 2"));
        page_31 = new QWidget();
        page_31->setObjectName(QStringLiteral("page_31"));
        page_31->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_31 = new QPlainTextEdit(page_31);
        plainTextEdit_31->setObjectName(QStringLiteral("plainTextEdit_31"));
        plainTextEdit_31->setGeometry(QRect(0, 0, 381, 341));
        toolBox_8->addItem(page_31, QStringLiteral("Page 3"));
        page_32 = new QWidget();
        page_32->setObjectName(QStringLiteral("page_32"));
        page_32->setGeometry(QRect(0, 0, 100, 30));
        plainTextEdit_32 = new QPlainTextEdit(page_32);
        plainTextEdit_32->setObjectName(QStringLiteral("plainTextEdit_32"));
        plainTextEdit_32->setGeometry(QRect(0, 0, 381, 341));
        toolBox_8->addItem(page_32, QStringLiteral("Page 4"));

        tab_area_8->addWidget(toolBox_8);

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
        toolBox_6->setCurrentIndex(0);
        toolBox_7->setCurrentIndex(0);
        toolBox_8->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnalyzeCSV);
    } // setupUi

    void retranslateUi(QMainWindow *AnalyzeCSV)
    {
        AnalyzeCSV->setWindowTitle(QApplication::translate("AnalyzeCSV", "MainWindow", 0));
        load_btn->setText(QApplication::translate("AnalyzeCSV", "LOAD >", 0));
        verify_btn->setText(QApplication::translate("AnalyzeCSV", "VERIFY >", 0));
        analyze_btn->setText(QApplication::translate("AnalyzeCSV", "ANALYZE >", 0));
        date_filter_lbl->setText(QApplication::translate("AnalyzeCSV", "Date Filter:", 0));
        domain_lbl->setText(QApplication::translate("AnalyzeCSV", "Department of Medecine - Summary", 0));
        graph_combo->clear();
        graph_combo->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(pub_tab), QApplication::translate("AnalyzeCSV", "PUBLICATIONS", 0));
#ifndef QT_NO_ACCESSIBILITY
        page_21->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        page_21->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        plainTextEdit_21->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 1\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"Hey", 0));
        toolBox_6->setItemText(toolBox_6->indexOf(page_21), QApplication::translate("AnalyzeCSV", "Page 1", 0));
        plainTextEdit_22->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 2 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_6->setItemText(toolBox_6->indexOf(page_22), QApplication::translate("AnalyzeCSV", "Page 2", 0));
        plainTextEdit_23->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 3 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_6->setItemText(toolBox_6->indexOf(page_23), QApplication::translate("AnalyzeCSV", "Page 3", 0));
        plainTextEdit_24->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 4 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_6->setItemText(toolBox_6->indexOf(page_24), QApplication::translate("AnalyzeCSV", "Page 4", 0));
        graph_combo_6->clear();
        graph_combo_6->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(grant_tab), QApplication::translate("AnalyzeCSV", "GRANTS", 0));
#ifndef QT_NO_ACCESSIBILITY
        page_25->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        page_25->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        plainTextEdit_25->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 1\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"Hey", 0));
        toolBox_7->setItemText(toolBox_7->indexOf(page_25), QApplication::translate("AnalyzeCSV", "Page 1", 0));
        plainTextEdit_26->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 2 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_7->setItemText(toolBox_7->indexOf(page_26), QApplication::translate("AnalyzeCSV", "Page 2", 0));
        plainTextEdit_27->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 3 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_7->setItemText(toolBox_7->indexOf(page_27), QApplication::translate("AnalyzeCSV", "Page 3", 0));
        plainTextEdit_28->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 4 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_7->setItemText(toolBox_7->indexOf(page_28), QApplication::translate("AnalyzeCSV", "Page 4", 0));
        graph_combo_7->clear();
        graph_combo_7->insertItems(0, QStringList()
         << QApplication::translate("AnalyzeCSV", "Graph 1", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 2", 0)
         << QApplication::translate("AnalyzeCSV", "Graph 3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(present_tab), QApplication::translate("AnalyzeCSV", "PRESENTATIONS", 0));
#ifndef QT_NO_ACCESSIBILITY
        page_29->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        page_29->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        plainTextEdit_29->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 1\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"Hey", 0));
        toolBox_8->setItemText(toolBox_8->indexOf(page_29), QApplication::translate("AnalyzeCSV", "Page 1", 0));
        plainTextEdit_30->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 2 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_8->setItemText(toolBox_8->indexOf(page_30), QApplication::translate("AnalyzeCSV", "Page 2", 0));
        plainTextEdit_31->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 3 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_8->setItemText(toolBox_8->indexOf(page_31), QApplication::translate("AnalyzeCSV", "Page 3", 0));
        plainTextEdit_32->setPlainText(QApplication::translate("AnalyzeCSV", "This is page 4 of the collapsable menu\n"
"\n"
"Hey", 0));
        toolBox_8->setItemText(toolBox_8->indexOf(page_32), QApplication::translate("AnalyzeCSV", "Page 4", 0));
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
