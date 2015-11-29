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

    recentFilesModel = new QStringListModel(this);
    ui->recent_files_list->setSelectionRectVisible(false);
    ui->recent_files_list->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(std::size_t t = 0; t < NBUT; t++){
        this->getCSVButton(t)->installEventFilter(this);
    }
}

LoadCSV::~LoadCSV()
{
    delete ui;
}

void LoadCSV::addRecentFile(QString file)
{
    recentFilesList.insert(0,file);
    recentFilesModel->setStringList(recentFilesList);
    ui->recent_files_list->setModel(recentFilesModel);
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
    addRecentFile("Publications: " + filename);
    ui->file_name_load->setText(filename);
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
    addRecentFile("Presentations: " + filename);
    ui->file_name_load->setText(filename);
    csvType = 4;
}

void LoadCSV::on_grant_btn_clicked()
{
    // This is what happens when user clicks the button for Grants
    std::cout << "Grant button registered." << "\n";
    filename=QFileDialog::getOpenFileName(
                                          this,
                                          tr("Open File"),        // Dialog for prompt
                                          "C://",                 // Default folder to open
                                          "CSV Files (*.csv)"     // File extension to filter for
                                          );
    ui->verify_btn->setDisabled(false);
    addRecentFile("Grants: " + filename);
    ui->file_name_load->setText(filename);
    csvType = 6;
}

void LoadCSV::on_teaching_btn_clicked()
{
    std::cout << "Teaching button registered." << "\n";
    filename=QFileDialog::getOpenFileName(
                                          this,
                                          tr("Open File"),        // Dialog for prompt
                                          "C://",                 // Default folder to open
                                          "CSV Files (*.csv)"     // File extension to filter for
                                          );
    ui->verify_btn->setDisabled(false);
    addRecentFile("Teaching: " + filename);
    ui->file_name_load->setText(filename);
    csvType = 5;
}


void LoadCSV::on_loadRecentFile_btn_clicked()
{
    QString selectedString = recentFilesList[ui->recent_files_list->currentIndex().row()];
    QStringList splitList = selectedString.split(": ");

    if (!QString::compare(splitList[0],"Publications"))
        csvType = 1;
    else if (!QString::compare(splitList[0],"Presentations"))
        csvType = 4;
    else if (!QString::compare(splitList[0],"Teaching"))
        csvType = 5;
    else if (!QString::compare(splitList[0],"Grants"))
        csvType = 6;
    else
        csvType = 0;

    filename = splitList[1];
    ui->file_name_load->setText(filename);

}


//Hover over button (or other things) listener.
bool LoadCSV::eventFilter(QObject *obj, QEvent *event)
{
    // This function repeatedly call for those QObjects
    // which have installed eventFilter (Step 2)

    for(std::size_t t = 0; t < NBUT; t++){
        if(obj == (QObject*)(this->getCSVButton(t)))
        {
            if (event->type() == QEvent::Enter)
            {
                setMouseOverBtnTxt(t);
            }
            else if(event->type() == QEvent::Leave){
                resetBtnTxt(t);
            }
        }
    }
    // pass the event on to the parent class
    return QWidget::eventFilter(obj, event);
}

QPushButton *LoadCSV::getCSVButton(std::size_t i){
    CSVType t = (CSVType)i;
    if(t == PUBLICATION) return ui->publication_btn;
    else if(t == GRANTS) return ui->grant_btn;
    else if(t == PRESENTATION) return ui->presentation_btn;
    else return ui->teaching_btn;
}

void LoadCSV::setMouseOverBtnTxt(size_t i){
    this->getCSVButton(i)->setText("I'm over you");
}

void LoadCSV::resetBtnTxt(std::size_t i){
    QString txt = QString::fromStdString(defaultButtonTxt[i]);
    this->getCSVButton(i)->setText(txt);
}
