#include "mytimer.h"
#include<QtCore>
#include <QtDebug>

/*!
 * \brief MyTimer::MyTimer
 * This function will start a timer and call the MyTimer::MySlot() function to incrament a counter.
 * This counter will be checked if it makes a minute, reset and save (SAVE NOT IMPLEMENTED)
 */

MyTimer::MyTimer() {
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));

    timer->start(1000);
}

bool MyTimer::MySlot() {

    //Use function to save
    counter ++;
    if(counter == 60) {
        qDebug()<<"Timer executed";

        counter = 0;//Restart Timer
        emit sendTimeout();
        return true;
    }
    else return false;

}


