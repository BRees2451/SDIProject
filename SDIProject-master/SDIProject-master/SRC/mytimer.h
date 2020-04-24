#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include <thread>


class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;
    std::thread saveThread;

public slots:
    bool MySlot();
};

#endif // MYTIMER_H
