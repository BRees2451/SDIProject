#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>


/**
 * @brief The MyTimer class is used to count down the
 * timer as well as then call a signal when it times out.
 */
class MyTimer : public QObject {
    Q_OBJECT
public:
    /**
     * @brief MyTimer
     * Starts a timer and call the function to increment a counter.
     */
    MyTimer();

    /**
     * @brief timer
     */
    QTimer *timer;
    /**
     * @brief counter
     * Counts the amount of time that has passed.
     */
    int counter = 0;

public slots:
    /**
     * @brief Increments a timer
     * @return whether the timer is up or not
     */
    bool MySlot();

signals:
    void sendTimeout();
};

#endif // MYTIMER_H
