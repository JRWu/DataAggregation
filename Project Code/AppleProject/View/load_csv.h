#ifndef LOAD_CSV_H
#define LOAD_CSV_H

#include <QMainWindow>


#include "DTO/csvdto.h"
#include "verify_csv.h"
#include "analyze_csv.h"
#include "View/view.h"

#define NBUT 4

enum CSVType: unsigned int;

namespace Ui {
class LoadCSV;
}

class LoadCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadCSV(QWidget *parent = 0);
    bool eventFilter(QObject *obj, QEvent *event);
    ~LoadCSV();

private:
    std::string defaultButtonTxt[4] =
                {"PUBLICATIONS", "GRANTS", "TEACHING", "PRESENTATION"};

    Ui::LoadCSV *ui;
    VerifyCSV *verify_csv_page;
    AnalyzeCSV *analyze_csv_page;
    QString filename;
    QStringListModel *recentFilesModel;
    QStringList recentFilesList;
    int csvType;

    QPushButton *getCSVButton(std::size_t i);
    void setMouseOverBtnTxt(std::size_t i);
    void resetBtnTxt(std::size_t i);

protected:
    void addRecentFile(QString file);

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
