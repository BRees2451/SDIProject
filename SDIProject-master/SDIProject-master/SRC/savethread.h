#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <QtCore>

class saveThread : public QThread
{
public:
    saveThread();
    void run();
signals:
    void sendSaveSignal(void);
};

#endif // SAVETHREAD_H
