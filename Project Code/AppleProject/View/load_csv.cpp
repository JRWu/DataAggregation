#include "load_csv.h"
#include "View/ui_load_csv.h"

using namespace std;

LoadCSV::LoadCSV(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::LoadCSV)
{
    ui->setupUi(this);
    ui->verify_btn->setDisabled(true);
    ui->analyze_btn->setDisabled(true);

    recentFilesModel = new QStringListModel(this);
    ui->recent_files_list->setSelectionRectVisible(false);
    ui->recent_files_list->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Set up the mouse over listener
    for(std::size_t t = 0; t < NBUT; t++){
        this->getCSVButton(t)->installEventFilter(this);
    }
    setDefaultBtnTxt();
}

LoadCSV::~LoadCSV()
{
    delete ui;
}

void LoadCSV::addRecentFile(QString file)
{
    /*recentFilesList.insert(0,file);
    recentFilesModel->setStringList(recentFilesList);
    ui->recent_files_list->setModel(recentFilesModel);*/
}


void LoadCSV::on_verify_btn_clicked()
{
    // add if statement for whether a file has been loaded or not
    //open the verify page within the existing window
    /*verify_csv_page = new VerifyCSV(filename, csvType);
    this->setCentralWidget(verify_csv_page);*/
    
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
    this->loadCSV(PUBLICATION);
}

void LoadCSV::on_presentation_btn_clicked()
{
    this->loadCSV(PRESENTATION);
}

void LoadCSV::on_grant_btn_clicked()
{
    this->loadCSV(GRANTS);
}

void LoadCSV::on_teaching_btn_clicked()
{
    this->loadCSV(TEACHING);
}


void LoadCSV::on_loadRecentFile_btn_clicked()
{
    /*QString selectedString = recentFilesList[ui->recent_files_list->currentIndex().row()];
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

    filename = splitList[1];*/
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
    if(i == 0) return ui->publication_btn;
    else if(i == 1) return ui->grant_btn;
    else if(i == 2) return ui->presentation_btn;
    else return ui->teaching_btn;
}

void LoadCSV::setMouseOverBtnTxt(size_t i){
    std::shared_ptr<CSVDTO> dto = Data::Instance()->getDTO(i);
    if(dto) this->getCSVButton(i)->setText("Warning: This will\noverwrite data");
}

void LoadCSV::resetBtnTxt(std::size_t i){
    this->getCSVButton(i)->setText(defaultBtntxt.at(i));
}

void LoadCSV::setDefaultBtnTxt(){
    defaultBtntxt.clear();
    std::string def[] = {"PUBLICATIONS", "GRANTS", "PRESENTATIONS", "TEACHING"};
    for(std::size_t i = 0; i < NBUT; i++){
        std::shared_ptr<CSVDTO> dto = Data::Instance()->getDTO(i);
        std::string s = def[i];
        defaultBtntxt.push_back(QString::fromStdString(s));
        QString tooltip = QString::fromStdString(dto?dto->getFile():"");
        this->getCSVButton(i)->setToolTip(tooltip);
    }
}

void LoadCSV::loadCSV(size_t t){
    Data *data = Data::Instance();
    try{
        string file = (this->getFile());
        data->loadDTO(file, t);    }
    catch(error::missing_header_error){
        ui->lblError->setText("  Error: File is missing mandatory headers");
    }
    catch(io::error::can_not_open_file){
        ui->lblError->setText("  Error: Cannot read from file");
    }
    catch(error::csv_format_error){
        ui->lblError->setText("  Error: CSV formatting is not as expcectd");
    }
    /*catch(error::duplicate_header_error){
        ui->lblError->setText("  Error: CSV has duplicate header");
    }*/

    /*if(Data::Instance()->getDTO(t)->getErrorLines()->size() == 0){
        ui->analyze_btn->setEnabled(true);
        //TODO Save CSV
        //Goto analyze page once finished
    }
    else{
        ui->verify_btn->setEnabled(true);

        this->setCentralWidget(new VerifyCSV(t));
    }*/
}

//Later add last file path chosen?
string LoadCSV::getFile(){
    QString f = QFileDialog::getOpenFileName(this,
                                            tr("Open File"),        // Dialog for prompt
                                            "C://",                 // Default folder to open
                                            "CSV Files (*.csv)"     // File extension to filter for
                                            );
    return f.toStdString();
}
