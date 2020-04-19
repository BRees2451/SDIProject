#include "UserShapeOperations.h"

void UserShapeOperation::USize() {
     /* if user input recieved{
     * change weidth
     * change height }
     * else {width = 500;
     *  height = 500;}
     *
     * to be called when drawshape is clicekd
     * */

    //option 1
    /* list shapes
     * select shape with mouse
     * return selected shape index
     * enter shape index
     * enter shapesize
     * edit shapesize
     * exit shape
     *
     * */
    throw "Not yet implemented";
}

void UserShapeOperation::Move() {
    // TODO - implement UserShapeOpperations::Move
    /* list shapes
     * select shape with mouse
     * return selected shape index
     * track mouse movements while mousepressed == true
     * when mouse pressed == false retrieve coordiantes
     * place shape at new coordiantes
     * edit shape coordinates in list
     * exit shape
     *
     *
     * //////// mouse posistion on shape stays the same or ato implements to centre of shape ??????????????
     * */
    throw "Not yet implemented";
}

void UserShapeOperation::Delete(QString sType, QString cType) {
    // TODO - implement UserShapeOpperations::Delete
    /* list shapes
     * select shape
     * return selected shape index
     * enter shape list at index
     * delete shape at index
     *
     *
     * //////////////////ask for confirmation????
     *
     *  for(drawnShape *s : shapeList){
            isSelected = s->
            if(s->isSelected){
                shapeList.pop_back();
            }
        }
        shapeList[shapeList.size()-1]->drawMe();
     * */
    throw "Not yet implemented";
}

void UserShapeOperation::DisplayName() {
    // TODO - implement UserShapeOpperations::DisplayName
    /* list shapes
     * select shape
     * return shape index
     * enter list at shape index
     * return name of shape
     * display name of shape on gui ///////// cout<< shape[i].name
     *
     *
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
                return;
            }
        }
    }
    drawnShape *currentlyDrawnShape = new drawnShape(sType, cType);
    currentlyDrawnShape->isBeingDrawn = true;
    shapeList.push_back(currentlyDrawnShape);
    currentlyDrawnShape->shapeStartPoint = thisPos;
}
