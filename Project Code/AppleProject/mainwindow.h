#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "load_csv.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_open_program_btn_clicked();

private:
    Ui::MainWindow *ui;
    LoadCSV *load_csv_page;
};

#endif // MAINWINDOW_H
