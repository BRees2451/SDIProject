#include "drawnshape.h"

/**
 * @brief drawnShape::drawMe
 * Draws the selected shape.
 * The area dragged accross to put the shape in is used to determine the points of each shape.
 * For a rectangle, this is simply the start and end points.
 * For a triangle, the middle of the shape start is used.
 * For a trapezium, it is slightly indented for a quarter of the length.
 * These points are added to the list which plots these points.
 */
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

/**
 * @brief drawnShape::tryToggleSelect
 * Tries to select a shape by drawing a rectangle around the shape
 * and checks to see if the mouse has been clicked within this.
 * @param mousePosition represents the current position of a shape.
 * @return whether the shape has been selected.
 */
bool drawnShape::tryToggleSelect(QPointF mousePosition) {
    QRectF boundingRect = this->shape.boundingRect();
    if(boundingRect.contains(mousePosition)) {
        this->isSelected = true;
        return true;
    }
    else return false;
}

/**
 * @brief drawnShape::getCenter
 * Gets the centre point of a shape.
 * This is done by finding the middle of
 * the start and end points.
 */
void drawnShape::getCenter() {
    center = new QPointF(shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2 - (this->classType.length()*3), shapeStartPoint->y() + (shapeEndPoint->y() - shapeStartPoint->y())/2);
}
