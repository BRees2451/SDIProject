#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>

class drawnShape
{
public:
    bool isBeingDrawn;
    QPoint *shapeStartPoint;
    QPoint *shapeEndPoint;



    drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;

    };

    //drawnShape();

    void drawMe();
private:
    QString shapeType;
    QString classType;
};

#endif // DRAWNSHAPE_H
