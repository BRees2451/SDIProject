
//#include <QtWidgets>
#include <QtTest/QtTest>
#include <QtCore>

// add necessary includes here

class MyTimer : public QObject
{
    Q_OBJECT

public:
    MyTimer();
    QTimer *timer;

private slots:
    void MySlot();

};

MyTimer::MyTimer()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(MySlot()));

    timer->start(1000);
}

void MyTimer::MySlot()
{
    int counter = 0;
    //Use function to save
    qDebug()<<"Timer executed";
    counter ++;
    if(counter == 60){
        //Save Program using threads


        counter = 0;//Restart Timer
    }
}





QTEST_APPLESS_MAIN(MyTimer)

#include "tst_testcase_MyTimer.moc"

