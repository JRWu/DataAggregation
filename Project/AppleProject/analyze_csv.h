#ifndef ANALYZE_CSV_H
#define ANALYZE_CSV_H

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

#endif // ANALYZE_CSV_H
