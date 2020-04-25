#include "mainwindow.h"
#include "mytimer.h"
#include <QApplication>
#include "savethread.h"

using namespace std;


//void callSave(MainWindow);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
