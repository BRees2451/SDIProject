#include "polygonshape.h"



void polygonShape::addPoint(QPointF point)
{
    pointsVector->push_back(point);
    //shape.append(point);
    //this->drawn = false;
    this->drawMe();
}


void polygonShape::drawMe(){
    shape.clear();
    for (QPointF a : *pointsVector){
        shape.append(a);
    }
    //shape.append(pointsVector[pointsVector->size()-1]);
    //shape.append(*shapeEndPoint);
    this->drawn = false;
}
