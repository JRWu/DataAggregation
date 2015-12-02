#ifndef LOAD_CSV_H
#define LOAD_CSV_H

#include <QMainWindow>

#include <vector>
#include <string>

#include "CSV-Parser/csvparser.h" //Error types

//#include "View/verify_csv.h"
//#include "View/analyze_csv.h"

#define NBUT 4

enum CSVType: unsigned int;

class QPushButton;
class Data;

namespace Ui {
class LoadCSV;
}

class LoadCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadCSV(QWidget *parent = 0, std::string err = "");
    bool eventFilter(QObject *obj, QEvent *event);
    ~LoadCSV();

private:
    std::vector<QString> defaultBtntxt;

    Ui::LoadCSV *ui;

    //QStringListModel *recentFilesModel;
    //QStringList recentFilesList;
    int csvType;

    Data *data;

    //Returns the buttons to load csvs
    QPushButton *getCSVButton(CSVType t);
    //changes the text of a button if a corresponding dto is loaded
    void setMouseOverBtnTxt(CSVType t);
    //Resets the button text to default
    void resetBtnTxt(CSVType t);
    //Set the default string for the buttons
    void setDefaultBtnTxt();
    //Used to get a filename from the user
    std::string getFile() ;
    //Tries to load a new csv of the given type
    void loadCSV(CSVType t);
    //Modify this later once we save csvs to HDD
    //void addRecentFile(QString);
protected:


private slots:
    void on_loadRecentFile_btn_clicked();
};

#endif // LOAD_CSV_H
