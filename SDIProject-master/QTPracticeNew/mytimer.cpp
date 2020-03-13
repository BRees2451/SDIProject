#include "mytimer.h"
#include<QtCore>
#include <QtDebug>

/*!
 * \brief MyTimer::MyTimer
 * This function will start a timer and call the MyTimer::MySlot() function to incrament a counter.
 * This counter will be checked if it makes a minute, reset and save (SAVE NOT IMPLEMENTED)
 */

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));

    timer->start(1000);
}

bool MyTimer::MySlot(){
    int counter = 0;
    //Use function to save
    qDebug()<<"Timer executed";
    counter ++;
    if(counter == 60){
        return true;


        counter = 0;//Restart Timer
    }
    else return false;

}


