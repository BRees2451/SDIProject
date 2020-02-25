#include "mytimer.h"
#include<QtCore>
#include <QtDebug>

int count = 0;

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));

    timer->start(1000);
}

void MyTimer::MySlot(){
    //Use function to save
    qDebug()<<"Timer executed";
    count += 1;
    if(count == 60){
        //Save Program


        count = 0;//Restart Timer
    }

}
