#include "drawnshape.h"


void drawnShape::drawMe()
{
    pointsVector.clear();
    shape.clear();

    if (this->shape.size() != 3 || this->shape.size() != 4 || this->shape.size() != 5) {
        if (this->shapeType == "Rectangle") {

            shape.append(*shapeStartPoint);
            pointsVector.append(*shapeStartPoint);
            shape.append(QPointF(shapeEndPoint->x(), shapeStartPoint->y()));
            pointsVector.append(QPointF(shapeEndPoint->x(), shapeStartPoint->y()));
            shape.append(*shapeEndPoint);
            pointsVector.append(*shapeEndPoint);
            shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
            pointsVector.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
            shape.append(*shapeStartPoint);

        }
        if (this->shapeType == "Triangle") {
            shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
            pointsVector.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
            shape.append(QPointF(shapeEndPoint->x(), shapeEndPoint->y()));
            pointsVector.append(QPointF(shapeEndPoint->x(), shapeEndPoint->y()));

            shape.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2), shapeStartPoint->y()));
            pointsVector.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2), shapeStartPoint->y()));
            shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
        }
        if (this->shapeType == "Trapezium") {
            shape.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));
            pointsVector.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));
            shape.append(QPointF((shapeEndPoint->x() - (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));
            pointsVector.append(QPointF((shapeEndPoint->x() - (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));
            shape.append(QPointF(shapeEndPoint->x(), shapeEndPoint->y()));
            pointsVector.append(QPointF(shapeEndPoint->x(), shapeEndPoint->y()));
            shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
            pointsVector.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
            shape.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));

        }
        if(this->shapeType == "Select") {


        }
    }

    center = new QPointF(shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2 - (this->classType.length()*3), shapeStartPoint->y() + (shapeEndPoint->y() - shapeStartPoint->y())/2);
    drawn = false;
}

bool drawnShape::tryToggleSelect(QPointF mousePosition) {
    QRectF boundingRect = this->shape.boundingRect();
    if(boundingRect.contains(mousePosition)) {
        this->isSelected = true;
        return true;
    }
    else return false;
}

void drawnShape::getCenter() {
    center = new QPointF(shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2 - (this->classType.length()*3), shapeStartPoint->y() + (shapeEndPoint->y() - shapeStartPoint->y())/2);
}
