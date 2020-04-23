#include <QPen>
#include "drawnshape.h"


void drawnShape::drawMe()
{
    //scene = new QGraphicsScene;
    //QPainterPath rectPath;
    if (this->shapeType == "Rectangle"){
        //float width = this->shapeEndPoint->x() - this->shapeStartPoint->x();
        //float Height = this->shapeEndPoint->y() - this->shapeStartPoint->y();
        //rectPath.addRect(this->shapeStartPoint->x(), this->shapeStartPoint->y(), width, Height);

        shape.append(*shapeStartPoint);
        shape.append(QPointF(shapeEndPoint->x(), shapeStartPoint->y()));
        shape.append(*shapeEndPoint);
        shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));

        QPen blackPen(Qt::black);
        blackPen.setWidth(6);


    }
    if (this->shapeType == "Triangle"){
        shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));
        shape.append(QPointF(shapeEndPoint->x(), shapeEndPoint->y()));
        //QPointF topPoint = new
        //topPoint->x() = (shapeStartPoint->y() - shapeStartPoint->x());
        shape.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2), shapeStartPoint->y()));


    }
    if (this->shapeType == "Trapezium"){
        shape.append(QPointF((shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));
        shape.append(QPointF((shapeEndPoint->x() - (shapeEndPoint->x() - shapeStartPoint->x())/4), shapeStartPoint->y()));
        shape.append(QPointF(shapeEndPoint->x(), shapeEndPoint->y()));
        shape.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));

    }
    if(this->shapeType == "Select"){


    }
    center = new QPointF(shapeStartPoint->x() + (shapeEndPoint->x() - shapeStartPoint->x())/2 - (this->classType.length()*3), shapeStartPoint->y() + (shapeEndPoint->y() - shapeStartPoint->y())/2);
    drawn = false;
}

bool drawnShape::tryToggleSelect(QPointF mousePosition){
    QRectF boundingRect = this->shape.boundingRect();
    if(boundingRect.contains(mousePosition)){
        this->isSelected = true;
        //this->drawn = false;
        return true;
    }
    else return false;
}
