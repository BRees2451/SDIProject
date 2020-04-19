#include "polygonshape.h"



void polygonShape::addPoint(QPointF point)
{
    pointsVector->push_back(point);
    this->drawMe();
}

void polygonShape::drawMe(){
    for (QPointF a : *pointsVector){
        shape.append(a);
    }
    shape.append(*shapeEndPoint);
    this->drawn = false;
}
