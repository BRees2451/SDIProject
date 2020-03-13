/*
#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGraphicsSceneWheelEvent>

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsItem>
//#include <QWidget>
#include <QtTest/QTest>
#include<QtTestGui>

class CustomView : public QObject
{
    Q_OBJECT

public:
    CustomView(QWidget* parent = 0);
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

CustomView::CustomView(QWidget *parent)  QGraphicsView(parent)
{

}

void CustomView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;

    if(event->delta()>0){
        void QGraphicsView ::scale(scaleFactor, scaleFactor);
    }
    else{
        scale(1/scaleFactor, 1/scaleFactor);
    }
}



#endif // CUSTOMVIEW_H

QTEST_APPLESS_MAIN(CustomView)

#include "tst_testcase_customView.moc"
*/
