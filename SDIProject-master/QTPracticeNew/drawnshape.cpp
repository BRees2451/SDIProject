#include <QPen>
#include "drawnshape.h"
#include "mainwindow.h"


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


    }
    if (this->shapeType == "Trapezium"){


    }
}
