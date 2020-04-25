#ifndef UserShapeOPPERATIONS_H
#define UserShapeOPPERATIONS_H
#include "drawnshape.h"
#include "polygonshape.h"

using namespace std;

class UserShapeOperation {

public:
    void Delete(QGraphicsScene *scene);

    void DisplayName();

    //Need a list of shapes
    vector<drawnShape*> shapeList;

    UserShapeOperation(){};

    ~UserShapeOperation(){};

    void drawShape();

    void handleMouseEvent(QString, QString, QPoint*);



};

#endif
