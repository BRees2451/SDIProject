#ifndef UserShapeOPPERATIONS_H
#define UserShapeOPPERATIONS_H
#include "drawnshape.h"
#include "polygonshape.h"

using namespace std;


/*!
 * @brief The UserShapeOperation class handles all of the processes involved
 * when using the shapes. This may include drawing and displaying the names.
 */
class UserShapeOperation {

public:
    /**
     * @brief Delete is called when dealing with deleting a shape.
     *
     * @param scene such that we can delete from the scene in this class.
     */
    void Delete(QGraphicsScene *scene);

    /**
     * @brief shapeList is a list of the shapes that are drawn onto the canvas.
     */
    vector<drawnShape*> shapeList;

    /**
     * @brief UserShapeOperation the constructor of the class.
     */
    UserShapeOperation(){};

    ~UserShapeOperation(){};

    /**
     * @brief drawShape is the method that is called and will then
     * subsequently call all of the drawnShapes drawMe functions.
     */
    void drawShape();

    /**
     * @brief handleMouseEvent will take the mouse event and decide whether
     * to create a new instance of the shape that we are trying to draw or
     * carry on drawing a shape that has been started.
     *
     * @param sType represents the shape type.
     * @param cType represents the class type.
     * @param thisPos represents the mouse position at the time.
     */
    void handleMouseEvent(QString sType, QString cType, QPoint *thisPos);



};

#endif
