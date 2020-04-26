#include "polygonshape.h"

/**
 * @brief polygonShape::addPoint is responsible for adding a new point to the list of polygon points.
 * It appends a given point to the beginning of the list. Then calls the drawMe function to draw the shape.
 *
 * @param point is the point to be added.
 */
void polygonShape::addPoint(QPointF point) {
    pointsVector->push_back(point);
    //shape.append(point);
    //this->drawn = false;
    this->drawMe();
}

/**
 * @brief polygonShape::drawMe will create a polygon shape out of the collected points list.
 * It will then draw the shape.
 */
void polygonShape::drawMe() {
    shape.clear();
    for (QPointF a : *pointsVector) {
        shape.append(a);
    }
    this->drawn = false;
}
