#include "canvas.h"
#include <QPoint>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>



Canvas::Canvas()
{
    scene = new QGraphicsScene(this);
}

/*
void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
        qDebug() << "YEEES";
        emit mousePressed(QPointF(mouseEvent->pos()));
    cout << "Pressed" << endl;
}*/
