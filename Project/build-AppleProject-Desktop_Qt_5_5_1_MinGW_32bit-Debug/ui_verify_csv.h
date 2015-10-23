/********************************************************************************
** Form generated from reading UI file 'verify_csv.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFY_CSV_H
#define UI_VERIFY_CSV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyCSV
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *navigation_area;
    QLabel *load_label;
    QLabel *verify_label;
    QLabel *analyze_label;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *file_name_label;
    QLabel *file_name;
    QPushButton *ignoreall_btn;
    QPushButton *ignore_btn;
    QPushButton *confirm_btn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *table_area;
    QLabel *instruction_label;
    QTableView *error_table;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VerifyCSV)
    {
        if (VerifyCSV->objectName().isEmpty())
            VerifyCSV->setObjectName(QStringLiteral("VerifyCSV"));
        VerifyCSV->resize(800, 600);
        centralwidget = new QWidget(VerifyCSV);
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

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 490, 781, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        file_name_label = new QLabel(horizontalLayoutWidget_3);
        file_name_label->setObjectName(QStringLiteral("file_name_label"));
        file_name_label->setMinimumSize(QSize(110, 40));
        file_name_label->setMaximumSize(QSize(110, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        file_name_label->setFont(font1);

        horizontalLayout->addWidget(file_name_label);

        file_name = new QLabel(horizontalLayoutWidget_3);
        file_name->setObjectName(QStringLiteral("file_name"));
        file_name->setMinimumSize(QSize(0, 40));
        file_name->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(file_name);

        ignoreall_btn = new QPushButton(horizontalLayoutWidget_3);
        ignoreall_btn->setObjectName(QStringLiteral("ignoreall_btn"));
        ignoreall_btn->setMinimumSize(QSize(100, 40));
        ignoreall_btn->setMaximumSize(QSize(200, 40));
        ignoreall_btn->setFont(font1);

        horizontalLayout->addWidget(ignoreall_btn);

        ignore_btn = new QPushButton(horizontalLayoutWidget_3);
        ignore_btn->setObjectName(QStringLiteral("ignore_btn"));
        ignore_btn->setMinimumSize(QSize(100, 40));
        ignore_btn->setMaximumSize(QSize(200, 40));
        ignore_btn->setFont(font1);

        horizontalLayout->addWidget(ignore_btn);

        confirm_btn = new QPushButton(horizontalLayoutWidget_3);
        confirm_btn->setObjectName(QStringLiteral("confirm_btn"));
        confirm_btn->setMinimumSize(QSize(100, 40));
        confirm_btn->setMaximumSize(QSize(200, 40));
        confirm_btn->setFont(font1);

        horizontalLayout->addWidget(confirm_btn);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 90, 781, 391));
        table_area = new QVBoxLayout(verticalLayoutWidget);
        table_area->setObjectName(QStringLiteral("table_area"));
        table_area->setContentsMargins(0, 0, 0, 0);
        instruction_label = new QLabel(verticalLayoutWidget);
        instruction_label->setObjectName(QStringLiteral("instruction_label"));
        instruction_label->setFont(font);
        instruction_label->setAlignment(Qt::AlignCenter);

        table_area->addWidget(instruction_label);

        error_table = new QTableView(verticalLayoutWidget);
        error_table->setObjectName(QStringLiteral("error_table"));

        table_area->addWidget(error_table);

        VerifyCSV->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VerifyCSV);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        VerifyCSV->setMenuBar(menubar);
        statusbar = new QStatusBar(VerifyCSV);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        VerifyCSV->setStatusBar(statusbar);

        retranslateUi(VerifyCSV);

        QMetaObject::connectSlotsByName(VerifyCSV);
    } // setupUi

    void retranslateUi(QMainWindow *VerifyCSV)
    {
        VerifyCSV->setWindowTitle(QApplication::translate("VerifyCSV", "MainWindow", 0));
        load_label->setText(QApplication::translate("VerifyCSV", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#aaaa7f;\">LOAD &gt;</span></p></body></html>", 0));
        verify_label->setText(QApplication::translate("VerifyCSV", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#ffcc00;\">VERIFY &gt;</span></p></body></html>", 0));
        analyze_label->setText(QApplication::translate("VerifyCSV", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#aaaa7f;\">ANALYZE &gt;</span></p></body></html>", 0));
        file_name_label->setText(QApplication::translate("VerifyCSV", "FILE NAME: ", 0));
        file_name->setText(QString());
        ignoreall_btn->setText(QApplication::translate("VerifyCSV", "IGNORE ALL", 0));
        ignore_btn->setText(QApplication::translate("VerifyCSV", "IGNORE", 0));
        confirm_btn->setText(QApplication::translate("VerifyCSV", "CONFIRM CHANGE", 0));
        instruction_label->setText(QApplication::translate("VerifyCSV", "<html><head/><body><p><span style=\" font-weight:600;\">CSV file errors must either be corrected or ignored before proceeding to the 'Analyze' page</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class VerifyCSV: public Ui_VerifyCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFY_CSV_H
