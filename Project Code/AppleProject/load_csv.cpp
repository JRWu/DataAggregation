#include "load_csv.h"
#include "ui_load_csv.h"

LoadCSV::LoadCSV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadCSV)
{
    ui->setupUi(this);
    ui->verify_btn->setDisabled(true);
    ui->analyze_btn->setDisabled(true);
    filename = "";
    csvType = 0;

}

LoadCSV::~LoadCSV()
{
    delete ui;
}

void LoadCSV::on_verify_btn_clicked()
{
    // add if statement for whether a file has been loaded or not
    //open the verify page within the existing window
    verify_csv_page = new VerifyCSV(filename, csvType);
    this->setCentralWidget(verify_csv_page);

}

void LoadCSV::on_analyze_btn_clicked()
{
    // if no file has been loaded or verified yet, then don't allow
    //open the analyze page within the existing window

    /*Analyzecsv requires a data pointer now, user can't click from here
    analyze_csv_page = new AnalyzeCSV();
    this->setCentralWidget(analyze_csv_page);
    */
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
    csvType = 1;
}

void LoadCSV::on_presentation_btn_clicked()
{
    // This is what happens when user clicks the button for Presentations
    std::cout << "Presentation button registered." << "\n";
    filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),        // Dialog for prompt
                "C://",                 // Default folder to open
                "CSV Files (*.csv)"     // File extension to filter for
                );
    ui->verify_btn->setDisabled(false);
    csvType = 4;
}
