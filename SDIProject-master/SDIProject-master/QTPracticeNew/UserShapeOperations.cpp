#include "UserShapeOperations.h"

void UserShapeOperation::USize() {
     /*
     *take current shape type and current shapeStartPoint
     * move curser to current shapeStartPoint
     * set clicked to true
     * at release mousepos = shapeEndPoint
     *
     * */
    throw "Not yet implemented";
}

void UserShapeOperation::Move() {
    // TODO - implement UserShapeOpperations::Move
    /*
     * QPoint *dx;
     * QPoint *dy;
     *
     * dx = mouseclick.x() - mouserelease.x();
     * dy = mouseclick.y() - mouserelease.y();
     * for (drawnShape *s : shapeList){
     *      if (s->isSelected) {
     *          shape.translate(dx,dy)
     *      }
     *  }
        */
    throw "Not yet implemented";
}

void UserShapeOperation::Delete(QString sType, QString cType) {
    /*
     * remove entire ui
     * remove shape from list:
     *
     * for(drawnShape *s : shapeList){
        isSelected = s->
        if(s->isSelected){
            shapeList.pop_back();
        }
     * }
     *
     *redraw ui
     * */
    throw "Not yet implemented";
}

void UserShapeOperation::drawShape()
{
       shapeList[shapeList.size()-1]->drawMe();
}

void UserShapeOperation::handleMouseEvent(QString sType, QString cType, QPoint *thisPos)
{
    qDebug() << shapeList.size() <<endl;
    if (shapeList.size() > 0) {
        for (drawnShape *s : shapeList){
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
    //(polygonShape(currentlyDrawnShape))->addPoint(thisPos);
    currentlyDrawnShape->isBeingDrawn = true;
    shapeList.push_back(currentlyDrawnShape);
    currentlyDrawnShape->shapeStartPoint = thisPos;
}
