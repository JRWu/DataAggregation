#ifndef VERIFY_CSV_H
#define VERIFY_CSV_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>

#include <vector>
#include <string>
#include <memory>

#include "View/load_csv.h"
#include "DTO/data.h"
#include "CSV-Data/csvfield.h"
#include "DTO/csvdto.h"

namespace Ui {
class VerifyCSV;
}
class LoadCSV;

class VerifyCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerifyCSV(std::size_t i, QWidget *parent = 0);
    ~VerifyCSV();

private slots:
    void on_load_btn_clicked();
    void on_analyze_btn_clicked();
    void on_ignoreall_btn_clicked();
    void on_ignore_btn_clicked();
    void on_confirm_btn_clicked();

private:
    Ui::VerifyCSV *ui;
    std::size_t csvType, col;
    std::vector<std::shared_ptr<std::vector<CSVField>>> *errors;

    //Loads the csv error lines into the ui.
    QStandardItemModel* ErrorTableModel();
    //Ignores all error lines and saves the csv
    void ignoreAll();
};

#endif // VERIFY_CSV_H
