#include "UserShapeOperations.h"

/**
 * @brief UserShapeOperation::Delete is repsonsible for removing shapes from the canvas.
 * It will look through the shape list and see if there is one selected to then, once found
 * delete the shape.
 *
 * @param scene will represent the scene which will be edited when deleting the shape from
 * the canvas.
 */
void UserShapeOperation::Delete(QGraphicsScene *scene) {

    for(drawnShape *s : shapeList) {
       if(s->isSelected) {
           delete s;
       }
     }
}

/**
 * @brief UserShapeOperation::drawShape will draw the very last shape in shape list.
 */
void UserShapeOperation::drawShape() {
       shapeList[shapeList.size()-1]->drawMe();
}

/**
 * @brief UserShapeOperation::handleMouseEvent will take the mouse event at the time
 * and then decide what to do with it.
 * It can either create another object or continue drawing the same object depending
 * on whether there is a shape still being drawn.
 *
 * @param sType represents the shape type for the new shape
 * @param cType represents the class type for the new shape
 * @param thisPos represents the position of the mouse when the event is triggered.
 */
void UserShapeOperation::handleMouseEvent(QString sType, QString cType, QPoint *thisPos) {
    if (shapeList.size() > 0) {
        for (drawnShape *s : shapeList) {
            if (s->isBeingDrawn) {
                s->shapeEndPoint = thisPos;

                if (sType != "Polygon" ) return;
                else break;
            }
        }
    }
    drawnShape *currentlyDrawnShape;
    if (sType != "Polygon") currentlyDrawnShape = new drawnShape(sType, cType);
    else currentlyDrawnShape = new polygonShape(sType, cType);

    currentlyDrawnShape->isBeingDrawn = true;
    shapeList.push_back(currentlyDrawnShape);
    currentlyDrawnShape->shapeStartPoint = thisPos;
}
