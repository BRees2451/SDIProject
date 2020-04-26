#ifndef POLYGONSHAPE_H
#define POLYGONSHAPE_H
#include "drawnshape.h"

/**
 * @brief The polygonShape class handles all of the processes involved in creating a polygon shape.
 * This includes adding a new point to the shape and drawing the shape.
 */

class polygonShape : public drawnShape {
    //Q_OBJECT;
public:
    using drawnShape::drawnShape;

    /**
     * @brief pointsVector is a list of the points that make up the polygon shape.
     */
    QVector<QPointF> *pointsVector = new QVector<QPointF>();

    /**
     * @brief addPoint adds a point to the points vector.
     *
     * @param QPointF is the point to be added.
     */
    void addPoint(QPointF);

    /**
     * @brief drawMe is the method that is called to draw the polygon to the GUI.
     */
    void drawMe();

};

#endif // POLYGONSHAPE_H
