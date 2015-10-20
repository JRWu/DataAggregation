#ifndef ANALYZECSV_H
#define ANALYZECSV_H

#include <QMainWindow>

namespace Ui {
class AnalyzeCSV;
}

class AnalyzeCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalyzeCSV(QWidget *parent = 0);
    ~AnalyzeCSV();

private:
    Ui::AnalyzeCSV *ui;
};

#endif // ANALYZECSV_H
