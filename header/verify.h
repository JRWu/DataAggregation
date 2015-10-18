#ifndef VERIFY_H
#define VERIFY_H

#include <QMainWindow>

namespace Ui {
class Verify;
}

class Verify : public QMainWindow
{
    Q_OBJECT

public:
    explicit Verify(QWidget *parent = 0);
    ~Verify();

private:
    Ui::Verify *ui;
};

#endif // VERIFY_H
