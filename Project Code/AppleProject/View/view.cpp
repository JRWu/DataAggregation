#include "view.h"

View* View::_instance = 0;

View::View()
{
    mainWindow = new MainWindow();
    loadWindow = 0;
    verifyWindow = 0;
}

View* View::Instance(){
    if(_instance == 0) _instance = new View();
    return _instance;
}

MainWindow *View::getMainWindow(){
    return mainWindow;
}

LoadCSV *View::getNewLoadWindow(){
    free(loadWindow);
    loadWindow = new LoadCSV();
    return loadWindow;
}

VerifyCSV *View::getNewVerifyWindow(size_t i){
    free(verifyWindow);
    verifyWindow = new VerifyCSV(i);
    return verifyWindow;
}
