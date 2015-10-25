#ifndef VERIFY_CSV_H
#define VERIFY_CSV_H

#include <QMainWindow>
#include <QStandardItemModel>
//#include "load_csv.h"
#include "analyze_csv.h"

namespace Ui {
class VerifyCSV;
}

class VerifyCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerifyCSV(QString filename,QWidget *parent = 0);
    ~VerifyCSV();

private slots:
    //void on_verify_btn_clicked();

    void on_analyze_btn_clicked();

private:
    Ui::VerifyCSV *ui;
    //VerifyCSV *verify_csv_page;
    AnalyzeCSV *analyze_csv_page;
    QStandardItemModel* PublicationTableModel(QString filename);
    shared_ptr<CSVData<PublicationDTO>> data;
};

#endif // VERIFY_CSV_H
