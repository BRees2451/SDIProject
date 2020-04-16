#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>
#include <QGraphicsScene>

class drawnShape
{
public:
    bool isBeingDrawn;
    bool drawn;
    bool isSelected;
    QPoint *shapeStartPoint;
    QPoint *shapeEndPoint;
    QString classType;

    QPolygonF shape;

    drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;
    };

    void drawMe();

private:
    QString shapeType;

};

#endif // DRAWNSHAPE_H
