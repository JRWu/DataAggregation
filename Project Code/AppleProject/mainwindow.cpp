#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "load_csv.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_btn_clicked()
{
    // open the load page inside the existing window
    load_csv_page = new LoadCSV();
    this->setCentralWidget(load_csv_page);
}
