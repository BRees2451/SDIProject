#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include<QGraphicsScene>
#include<QMouseEvent>
#include <QtCore>

using namespace std;

class Canvas : public QGraphicsScene {
    Q_OBJECT
public:
    QGraphicsScene *scene;
    Canvas();


    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    //void mousePressed(QPointF);
};

#endif // CANVAS_H
