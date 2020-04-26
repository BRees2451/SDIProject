#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main
 * The main function to run the program.
 */

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
