#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>



class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;

public slots:
    bool MySlot();
};

#endif // MYTIMER_H