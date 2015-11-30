#include "View/mainwindow.h"
#include "View/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap mypix(":/images/images/apple.jpg");
    ui->logo_lbl->setPixmap(mypix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
