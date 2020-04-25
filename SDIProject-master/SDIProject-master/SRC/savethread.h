#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <QtCore>
#include "mainwindow.h"

class saveThread : public QThread, public MainWindow
{
public:
    saveThread();
    void run();
signals:
    void sendSaveSignal();
};

#endif // SAVETHREAD_H
