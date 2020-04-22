#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>
#include <QGraphicsScene>

class drawnShape
{
public:
    bool isBeingDrawn;
    bool drawn;
    bool isSelected = false;
    QPoint *shapeStartPoint;
    QPoint *shapeEndPoint;
    QString classType;
    QString shapeType;

    QPolygonF shape;

    explicit drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;
    };
    //virtual ~drawnShape();

    void drawMe();

    bool tryToggleSelect(QPointF);

};

#endif // DRAWNSHAPE_H
