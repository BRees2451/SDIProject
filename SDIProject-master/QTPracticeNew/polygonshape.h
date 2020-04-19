#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "drawnshape.h"

class polygonShape : public drawnShape
{
    //Q_OBJECT;
public:
    using drawnShape::drawnShape;

    QVector<QPointF> *pointsVector = new QVector<QPointF>();

    void addPoint(QPointF);

    void drawMe();

};

#endif // POLYGONSHAPE_H
