#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>
#include <QGraphicsScene>

class drawnShape
{
public:
    bool isBeingDrawn;
    bool drawn = false;
    bool isSelected = false;
    QPoint *shapeStartPoint;
    QPoint *shapeEndPoint;
    QString classType;
    QString shapeType;

    QPolygonF shape;

    QVector<QPointF> pointsVector;

    QPointF *center;

    explicit drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;
    };
    //virtual ~drawnShape();

    void drawMe();

    bool tryToggleSelect(QPointF);

    void getCenter();

};

#endif // DRAWNSHAPE_H
