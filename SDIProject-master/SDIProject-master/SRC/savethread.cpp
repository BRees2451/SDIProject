#include "savethread.h"
#include <QtCore>
#include <QDebug>


saveThread::saveThread()
{

}

void saveThread::run()
{
    bool quit = false;
    while(quit != true){
        this->sleep(60);
        qDebug()<<"File Autosaving...";
        // call mainWindow save (autosave);
        // repeat
        //emit sendSaveSignal();

    }
}
