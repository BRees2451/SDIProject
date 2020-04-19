#ifndef UserShapeOPPERATIONS_H
#define UserShapeOPPERATIONS_H
#include "drawnshape.h"


using namespace std;

class UserShapeOperation {
private:
    //Type shape definition
    struct Shape{
        QString ShapeType;
        QPoint startPoint;
        QPoint endPoint;
        QString Class;
    };



    //Initial conditions
    Shape a;

public:
    void USize();

    void Move();

    void Delete(QString sType, QString cType);

    void DisplayName();


    //Need a list of shapes
    vector<drawnShape*> shapeList;

    UserShapeOperation(){
       // drawnShape *header;
       // shapeList.push_back(header);
    };



    ~UserShapeOperation()
    {
        //For Deleting?
    }

    void drawShape();

    void handleMouseEvent(QString, QString, QPoint*);
};

#endif
