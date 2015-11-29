#ifndef VIEW_H
#define VIEW_H

#include "View/mainwindow.h"
#include "View/load_csv.h"

class MainWindow;
class LoadCSV;

class View
{
public:
    static View* Instance();

    MainWindow *getMainWindow();
    LoadCSV *getLoadWindow();
    LoadCSV *getNewLoadWindow();

protected:
    View();

private:
    static View *_instance;

    MainWindow *mainWindow;
    LoadCSV *loadWindow;
};

#endif // VIEW_H
