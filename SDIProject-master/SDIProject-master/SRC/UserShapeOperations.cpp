#include "UserShapeOperations.h"

void UserShapeOperation::USize(QString sType, QString cType, QPoint *thisPos){
   // QCursor::setPos(x,y);

    /*
     *take current shape type and current shapeStartPoint
     * move curser to current shapeStartPoint
     * set clicked to true
     * at release mousepos = shapeEndPoint
     *
     * */

   /* for (drawnShape *s : shapeList){
        if (s->isSelected) {
            s->shapeStartPoint = s->shapeStartPoint;
            c.setPos(shapeStartPoinf.x(), shapeStartPoint.y());
            setCursor(c);
            s->shapeEndPoint = thisPos;

            if (sType != "Polygon" ) return;
            else break;
        }
    }

    drawnShape *currentlyDrawnShape;

*/

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

void UserShapeOperation::Delete(QGraphicsScene *scene) {
    //scene->clear();//clear works

    for(drawnShape *s : shapeList){
       if(s->isSelected){
           delete s;
           //set drawn to true
       }
     }
    scene->update();
}

void UserShapeOperation::drawShape()
{
       shapeList[shapeList.size()-1]->drawMe();
}

void UserShapeOperation::handleMouseEvent(QString sType, QString cType, QPoint *thisPos)
{
    //qDebug() << shapeList.size() <<endl;
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