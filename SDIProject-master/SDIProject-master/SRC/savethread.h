#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <QtCore>

class mainWindow;

class saveThread : public QThread
{
    Q_OBJECT
    mainWindow *mainWindow;
public:
    //explicit saveThread(mainWindow *mainWindow, QObject *parent = 0);
protected:
    //saveThread();
    void run();
signals:
    void sendSaveSignal(void);
};

#endif // SAVETHREAD_H
