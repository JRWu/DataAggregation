/* Controller for actions of the main window of the program.
 */

#include "View/mainwindow.h"

//When the open button is clicked more into the load window
void MainWindow::on_open_program_btn_clicked()
{
    this->setCentralWidget(new LoadCSV());
}

