#ifndef SAVETHREAD_H
#define SAVETHREAD_H
#include <QtCore>


class saveThread : public QThread
{
public:
    saveThread();
    void run();
};

#endif // SAVETHREAD_H
