#ifndef LOAD_CSV_H
#define LOAD_CSV_H

#include <QMainWindow>
#include <QString>
#include <QStringListModel>
#include <QPushButton>
#include <QFileDialog>

#include <vector>
#include <string>
#include <memory>

#include "DTO/csvdto.h"
#include "DTO/data.h"
#include "View/verify_csv.h"
#include "View/analyze_csv.h"

#define NBUT 4

enum CSVType: unsigned int;
class QStringListModel;

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

    QStringListModel *recentFilesModel;
    QStringList recentFilesList;
    int csvType;

    //Returns the buttons to load csvs
    QPushButton *getCSVButton(std::size_t i);
    //changes the text of a button if a corresponding dto is loaded
    void setMouseOverBtnTxt(std::size_t i);
    //Resets the button text to default
    void resetBtnTxt(std::size_t i);
    //Set the default string for the buttons
    void setDefaultBtnTxt();
    //Used to get a filename from the user
    std::string getFile() ;
    //Tries to load a new csv of the given type
    void loadCSV(size_t t);
    //Modify this later once we save csvs to HDD
    void addRecentFile(QString);
protected:


private slots:
    void on_verify_btn_clicked();

    void on_analyze_btn_clicked();

    void on_publication_btn_clicked();
    
    void on_grant_btn_clicked();

    void on_presentation_btn_clicked();

    void on_teaching_btn_clicked();

    void on_loadRecentFile_btn_clicked();
};

#endif // LOAD_CSV_H
