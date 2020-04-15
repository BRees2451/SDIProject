#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>
#include <QGraphicsScene>

class drawnShape
{
public:
    bool isBeingDrawn;
    bool drawn;
    QPoint *shapeStartPoint;
    QPoint *shapeEndPoint;

    //QGraphicsScene *scene;

    drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;

    };

    QPolygonF shape;

    void drawMe();
private:
    QString shapeType;
    QString classType;
};

#endif // DRAWNSHAPE_H
