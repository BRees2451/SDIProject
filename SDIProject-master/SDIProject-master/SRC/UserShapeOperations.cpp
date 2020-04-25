#include "UserShapeOperations.h"

void UserShapeOperation::Delete(QGraphicsScene *scene) {

    for(drawnShape *s : shapeList) {
       if(s->isSelected) {
           delete s;
       }
     }
}

void UserShapeOperation::drawShape() {
       shapeList[shapeList.size()-1]->drawMe();
}

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
