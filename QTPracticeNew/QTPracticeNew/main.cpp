#include "mainwindow.h"
#include "mytimer.h"

#include <QApplication>
#include <thread>
using namespace std;

thread saveThread;

void callSave(MainWindow);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTimer mTimer;
    MainWindow w;

    //Calls the save function if return is true using a separate thread such that the program can continue.
    if (mTimer.MySlot() == true) thread saveThread(&MainWindow::Save);

    w.show();

    saveThread.join();
    return a.exec();
}
