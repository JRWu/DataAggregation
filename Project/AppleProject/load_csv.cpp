#include "load_csv.h"
#include "ui_load_csv.h"

LoadCSV::LoadCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadCSV)
{
    ui->setupUi(this);

}

LoadCSV::~LoadCSV()
{
    delete ui;
}

void LoadCSV::on_verify_btn_clicked()
{
    //open the verify page within the existing window
    verify_csv_page = new VerifyCSV();
    this->setCentralWidget(verify_csv_page);
}

void LoadCSV::on_analyze_btn_clicked()
{
    //open the analyze page within the existing window
    analyze_csv_page = new AnalyzeCSV();
    this->setCentralWidget(analyze_csv_page);
}

void LoadCSV::on_publication_btn_clicked()
{
    // This is what happens when user clicks the button for Publications
    std::cout << "Publication button registered." << "\n";
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),        // Dialog for prompt
                "C://",                 // Default folder to open
                "CSV Files (*.csv)"     // File extension to filter for
                );


    //vvv Comment out this if don't want popup vvv
    QMessageBox::information(
                this,
                tr("File Name: "),
                filename
                );
    //^^^ Comment out this if don't want popup ^^^
}
