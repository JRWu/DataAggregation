#include "verify.h"
#include "ui_verify.h"

Verify::Verify(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Verify)
{
    ui->setupUi(this);
}

Verify::~Verify()
{
    delete ui;
}
