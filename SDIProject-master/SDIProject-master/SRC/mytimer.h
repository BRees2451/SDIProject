#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>



class MyTimer : public QObject {
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;

    int counter = 0;

public slots:
    bool MySlot();

signals:
    void sendTimeout();
};

#endif // MYTIMER_H
