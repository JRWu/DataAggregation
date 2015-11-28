#include <QApplication>

#include "View/view.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    View *view = View::Instance();
    view->getMainWindow()->show();

    return a.exec();
}
