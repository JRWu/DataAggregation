#ifndef VIEW_H
#define VIEW_H

#include "View/mainwindow.h"
#include "View/load_csv.h"
#include "View/verify_csv.h"

class MainWindow;
class LoadCSV;
class VerifyCSV;

class View
{
public:
    static View* Instance();

    MainWindow *getMainWindow();
    LoadCSV *getNewLoadWindow();
    VerifyCSV *getNewVerifyWindow(std::size_t i);

protected:
    View();

private:
    static View *_instance;

    MainWindow *mainWindow;
    LoadCSV *loadWindow;
    VerifyCSV *verifyWindow;
};

#endif // VIEW_H
