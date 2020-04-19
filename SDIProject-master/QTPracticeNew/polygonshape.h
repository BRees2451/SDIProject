#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "drawnshape.h"

class polygonShape : public drawnShape
{
public:
    //polygonShape(QString, QString);

    QVector<QPointF> *pointsVector = new QVector<QPointF>();
};

#endif // POLYGONSHAPE_H
