#include "polygonshape.h"



void polygonShape::addPoint(QPointF point) {
    pointsVector->push_back(point);
    //shape.append(point);
    //this->drawn = false;
    this->drawMe();
}


void polygonShape::drawMe() {
    shape.clear();
    for (QPointF a : *pointsVector) {
        shape.append(a);
    }
    this->drawn = false;
}
