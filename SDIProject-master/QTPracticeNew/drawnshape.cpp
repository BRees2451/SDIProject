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

        QPolygonF Rectangle;

        Rectangle.append(*shapeStartPoint);
        Rectangle.append(QPointF(shapeEndPoint->x(), shapeStartPoint->y()));
        Rectangle.append(*shapeEndPoint);
        Rectangle.append(QPointF(shapeStartPoint->x(), shapeEndPoint->y()));

        QPen blackPen(Qt::black);
        blackPen.setWidth(6);


        //Exception caused here
        scene->addPolygon(Rectangle,blackPen);

    }
    if (this->shapeType == "Triangle"){


    }
    if (this->shapeType == "Trapezium"){


    }
}
