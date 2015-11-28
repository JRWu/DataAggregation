#include "view.h"

View* View::_instance = 0;

View::View()
{
    mainWindow = new MainWindow();
    loadWindow = new LoadCSV();
}

View* View::Instance(){
    if(_instance == 0) _instance = new View();
    return _instance;
}

MainWindow *View::getMainWindow(){
    return mainWindow;
}

LoadCSV *View::getLoadWindow(){
    return loadWindow;
}
