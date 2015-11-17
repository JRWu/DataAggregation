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
    explicit VerifyCSV(QString filename, int csvType, QWidget *parent = 0);
    ~VerifyCSV();

private slots:
    //void on_verify_btn_clicked();
    void on_load_btn_clicked();
    void on_analyze_btn_clicked();
    void on_ignoreall_btn_clicked();
    void on_ignore_btn_clicked();
    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

    void on_confirm_btn_clicked();

private:
    Ui::VerifyCSV *ui;
    //VerifyCSV *verify_csv_page;
    AnalyzeCSV *analyze_csv_page;
    QStandardItemModel* PublicationTableModel();
    QStandardItemModel* GrantTableModel();

    // Shared pointers for VO generation
    shared_ptr<CSVData<PublicationDTO>> data_pub;
    shared_ptr<CSVData<GrantDTO>> data_grant;
    shared_ptr<CSVData<TeachingDTO>> data_teach;
    shared_ptr<CSVData<PresentationDTO>> data_pres;

    void enableConfirmChanges();
    int dtoType;
    bool assembled;

};

#endif // VERIFY_CSV_H
