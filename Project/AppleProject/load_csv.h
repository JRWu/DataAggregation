#ifndef LOAD_CSV_H
#define LOAD_CSV_H

#include <QMainWindow>

namespace Ui {
class LoadCSV;
}

class LoadCSV : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadCSV(QWidget *parent = 0);
    ~LoadCSV();

private:
    Ui::LoadCSV *ui;
};

#endif // LOAD_CSV_H
