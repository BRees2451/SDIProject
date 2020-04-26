#ifndef DRAWNSHAPE_H
#define DRAWNSHAPE_H
#include <QtCore>
#include <QGraphicsScene>

/**
 * @brief The drawnShape class represents the shapes that
 * are drawn onto the canvas.
 */
class drawnShape {
public:
    /**
     * @brief isBeingDrawn
     * Determines whether a shape is being drawn or not.
     */
    bool isBeingDrawn;

    /**
     * @brief drawn
     * Determines whether a shape is drawn or not.
     */
    bool drawn = false;

    /**
     * @brief isSelected
     * Determines whether a shape is selected or not.
     */
    bool isSelected = false;

    /**
     * @brief shapeStartPoint
     * Coordinates for the top left corner of the shape
     */
    QPoint *shapeStartPoint;

    /**
     * @brief shapeEndPoint
     * Coordinates for the bottom right corner of the shape.
     */
    QPoint *shapeEndPoint;

    /**
     * @brief classType
     * Type of class
     */
    QString classType;

    /**
     * @brief shapeType
     * Type of shape
     */
    QString shapeType;

    /**
     * @brief shape
     * The current shape
     */
    QPolygonF shape;

    /**
     * @brief pointsVector
     * Vector of sets of points for a shape.
     */
    QVector<QPointF> pointsVector;

    /**
     * @brief center
     * Centre of the shape.
     */
    QPointF *center;

    explicit drawnShape(QString sType, QString cType){
        this->shapeType = sType;
        this->classType = cType;
    };
    //virtual ~drawnShape();

    void drawMe();

    /**
     * @brief tryToggleSelect
     * Attempts to select a shape.
     * @return whether the shape is selected or not.
     */
    bool tryToggleSelect(QPointF);

    /**
     * @brief getCenter
     * Gets centre point of the shape.
     */
    void getCenter();

};

#endif // DRAWNSHAPE_H
