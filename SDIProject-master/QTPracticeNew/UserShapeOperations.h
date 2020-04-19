#ifndef UserShapeOPPERATIONS_H
#define UserShapeOPPERATIONS_H
#include "drawnshape.h"
#include "polygonshape.h"

using namespace std;

class UserShapeOperation {

public:
    void USize();

    void Move();

    void Delete(QString, QString);

    void DisplayName();


    //Need a list of shapes
    vector<drawnShape*> shapeList;

    UserShapeOperation();

    ~UserShapeOperation()
    {
        //For Deleting?
    }

    void drawShape();

    void handleMouseEvent(QString, QString, QPoint*);
};

#endif
