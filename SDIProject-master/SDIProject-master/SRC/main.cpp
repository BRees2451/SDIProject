#include "mainwindow.h"
#include "mytimer.h"
#include <QApplication>
#include "savethread.h"

using namespace std;


//void callSave(MainWindow);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MyTimer mTimer;

    QThread saveThread;

    MainWindow w;




    
    w.show();

    //w.doSetup(saveThread);


    //saveThread.start();
    //Calls the save function if return is true using a separate thread such that the program can continue.
    //if (mTimer.MySlot() == true) thread saveThread(&MainWindow::Save);





    //saveThread.join();
    return a.exec();
}
