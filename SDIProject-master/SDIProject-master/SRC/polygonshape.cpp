#include "polygonshape.h"


/**
 * @brief polygonShape::addPoint
 * Adds a point to the current polygon being drawn.
 * @param point represents the coordinates of the point being added to the polygon.
 */
void polygonShape::addPoint(QPointF point) {
    pointsVector->push_back(point);
    //shape.append(point);
    //this->drawn = false;
    this->drawMe();
}

/**
 * @brief polygonShape::drawMe
 * Draws the polygon by appending each point to it.
 */
void polygonShape::drawMe() {
    shape.clear();
    for (QPointF a : *pointsVector) {
        shape.append(a);
    }
    this->drawn = false;
}
