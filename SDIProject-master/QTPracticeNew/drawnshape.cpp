#include <QPainterPath>
#include "drawnshape.h"

void drawnShape::drawMe()
{
    QPainterPath rectPath;
    if (this->shapeType == "Rectangle"){
        float width = this->shapeEndPoint->x() - this->shapeStartPoint->x();
        float Height = this->shapeEndPoint->y() - this->shapeStartPoint->y();
        rectPath.addRect(this->shapeStartPoint->x(), this->shapeStartPoint->y(), width, Height);

    }
    if (this->shapeType == "Triangle"){


    }
    if (this->shapeType == "Trapezium"){


    }
}
