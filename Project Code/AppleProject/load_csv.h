#ifndef LOAD_CSV_H
#define LOAD_CSV_H

#include <QMainWindow>
#include "verify_csv.h"
#include "analyze_csv.h"

namespace Ui {
class LoadCSV;
}

class LoadCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadCSV(QWidget *parent = 0);
    ~LoadCSV();

private slots:
    void on_verify_btn_clicked();

    void on_analyze_btn_clicked();

    void on_publication_btn_clicked();

    void on_presentation_btn_clicked();
private:
    Ui::LoadCSV *ui;
    VerifyCSV *verify_csv_page;
    AnalyzeCSV *analyze_csv_page;
    QString filename;
    int csvType;
};

#endif // LOAD_CSV_H
