#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "drawnshape.h"


/**
 * @brief The polygonShape class is an extension of
 * drawnShape however is made to.
 */
class polygonShape : public drawnShape {
    //Q_OBJECT;
public:

    using drawnShape::drawnShape;

    /**
     * @brief pointsVector
     * Vector containing the points of the polygon.
     */
    QVector<QPointF> *pointsVector = new QVector<QPointF>();

    /**
     * @brief addPoint
     * Adds a point to the polygon when it is clicked.
     */

    void addPoint(QPointF);
    /**
     * @brief drawMe
     * Draws the polygon.
     */
    void drawMe();

};

#endif // POLYGONSHAPE_H
