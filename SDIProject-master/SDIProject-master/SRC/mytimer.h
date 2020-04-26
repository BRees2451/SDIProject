#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>

/**
 * @brief The MyTimer class handles all of the processes related to the timer.
 */

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
