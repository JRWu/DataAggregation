#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "load_csv.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap mypix(":/images/images/apple.jpg");
    ui->logo_lbl->setPixmap(mypix);

    //usleep(600000);
    //on_open_program_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_program_clicked()
{
    load_csv_page = new LoadCSV();
    this->setCentralWidget(load_csv_page);
}
