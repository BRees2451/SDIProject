#include "savethread.h"
#include <QtCore>
#include <QDebug>
#include "mainwindow.h"

/*
saveThread::saveThread(MainWindow *mainWindow), QObject *parent) : QThread(parent){
    MainWindow = mainWindow;
}
*/
saveThread::saveThread()
{

}

void saveThread::run()
{
    bool quit = false;
    bool autoSave = true;
    while(quit != true){
        this->sleep(60);

        //mainWindow->save(autoSave);

        qDebug()<<"File Autosaving...";
        // call mainWindow save (autosave);
        // repeat
        //emit sendSaveSignal();

    }
}
