#ifndef VERIFY_CSV_H
#define VERIFY_CSV_H

#include <QMainWindow>

namespace Ui {
class VerifyCSV;
}

class VerifyCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerifyCSV(QWidget *parent = 0);
    ~VerifyCSV();

private slots:
    void on_load_btn_clicked();

    void on_analyze_btn_clicked();

private:
    Ui::VerifyCSV *ui;
};

#endif // VERIFY_CSV_H
