#include "verify_csv.h"
#include "ui_verify_csv.h"
#include "publicationdto.h"
#include <QtWidgets>
#include <QStandardItemModel>
#include <QStandardItem>


QStandardItemModel* VerifyCSV::PublicationTableModel(QStandardItemModel* _model)
{
    QStandardItemModel *model = _model;
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Domain")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Journal Name")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Title")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("ISBN")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("Status")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("Type")));
    model->setHorizontalHeaderItem(7, new QStandardItem(QString("Role")));
    model->setHorizontalHeaderItem(8, new QStandardItem(QString("Date")));
    model->setHorizontalHeaderItem(9, new QStandardItem(QString("Authors")));
    model->setHorizontalHeaderItem(10, new QStandardItem(QString("Volume")));
    model->setHorizontalHeaderItem(12, new QStandardItem(QString("Issue")));
    model->setHorizontalHeaderItem(13, new QStandardItem(QString("Page Range")));
    model->setHorizontalHeaderItem(14, new QStandardItem(QString("DOI")));
    model->setHorizontalHeaderItem(15, new QStandardItem(QString("Website")));
    model->setHorizontalHeaderItem(16, new QStandardItem(QString("Publisher")));
    model->setHorizontalHeaderItem(17, new QStandardItem(QString("Personal Renumeration")));
    model->setHorizontalHeaderItem(18, new QStandardItem(QString("Trainee Details")));
    model->setHorizontalHeaderItem(19, new QStandardItem(QString("Most Significant Details")));
    model->setHorizontalHeaderItem(20, new QStandardItem(QString("PubMed ID")));
    model->setHorizontalHeaderItem(21, new QStandardItem(QString("Author Number")));
    model->setHorizontalHeaderItem(22, new QStandardItem(QString("Impact Factor")));
    model->setHorizontalHeaderItem(23, new QStandardItem(QString("Peer Reviewed")));
    model->setHorizontalHeaderItem(24, new QStandardItem(QString("International")));
    model->setHorizontalHeaderItem(25, new QStandardItem(QString("Presentation")));
    model->setHorizontalHeaderItem(26, new QStandardItem(QString("Most Significant")));
    model->setHorizontalHeaderItem(27, new QStandardItem(QString("Education")));

    //QStandardItem *firstRow = new QStandardItem(QString("ColumnValue"));
    //model->setItem(0,0,firstRow);

    return model;
}

VerifyCSV::VerifyCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerifyCSV)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(/*will be length of vector*/2,28,this);
    ui->error_table->setModel(PublicationTableModel(model));
}

VerifyCSV::~VerifyCSV()
{
    delete ui;
}

void VerifyCSV::on_analyze_btn_clicked()
{
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV();
    this->setCentralWidget(analyze_csv_page);
}

