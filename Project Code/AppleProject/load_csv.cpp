#include "load_csv.h"
#include "ui_load_csv.h"

LoadCSV::LoadCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadCSV)
{
    ui->setupUi(this);
    ui->verify_btn->setDisabled(true);
    filename = "";

}

LoadCSV::~LoadCSV()
{
    delete ui;
}

void LoadCSV::on_verify_btn_clicked()
{
    // add if statement for whether a file has been loaded or not
    //open the verify page within the existing window
    verify_csv_page = new VerifyCSV(filename);
    this->setCentralWidget(verify_csv_page);

}

void LoadCSV::on_analyze_btn_clicked()
{
    // if no file has been loaded or verified yet, then don't allow
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV(filename);
    this->setCentralWidget(analyze_csv_page);
}

void LoadCSV::on_publication_btn_clicked()
{
    // This is what happens when user clicks the button for Publications
    std::cout << "Publication button registered." << "\n";
    filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),        // Dialog for prompt
                "C://",                 // Default folder to open
                "CSV Files (*.csv)"     // File extension to filter for
                );
    ui->verify_btn->setDisabled(false);
}
