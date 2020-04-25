#include "shareclass.h"

shareClass::shareClass()
{

}

void shareClass::run(){
    bool quit = false;
    while(quit != true){
        this->sleep(60);
        qDebug()<<"File Autosaving...";
        // call mainWindow save (autosave);
        // repeat
        //emit sendSaveSignal();
        //MainWindow::saveSignal();
    }
}
