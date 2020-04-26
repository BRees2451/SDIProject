#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>
#include <QGraphicsScene>

/**
 * @brief The drawnShape class is the class that contains all the relating data and proccesses of the shapes.
 *
 */

class drawnShape {
public:
    bool isBeingDrawn;
    bool drawn = false;
    bool isSelected = false;
    QPoint *shapeStartPoint;
    QPoint *shapeEndPoint;
    QString classType;
    QString shapeType;

    QPolygonF shape;

    QVector<QPointF> pointsVector;

    QPointF *center;

    /**
     * @brief drawnShape is a constructor of a shape.
     * @param sType is the shape type of the shape.
     * @param cType is the class type of the shape.
     */
    explicit drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;
    };
    //virtual ~drawnShape();

    /**
     * @brief drawMe is the method that draws all the shapes to the GUI.
     */
    void drawMe();

    /**
     * @brief tryToggleSelect is a method called to test if a shape has been selected.
     * It returns true or false if the shape has or has not been selected.
     * @param QPointF is the mouse position to check if the mouse is over the shape.
     */
    bool tryToggleSelect(QPointF);

    /**
     * @brief getCenter is a method that finds the center of a shape.
     */
    void getCenter();

};

#endif // DRAWNSHAPE_H
