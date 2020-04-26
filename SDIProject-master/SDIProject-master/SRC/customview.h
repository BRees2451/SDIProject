#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

/**
 * @brief The CustomView class is used to add little
 * elements to the canvas
 */
class CustomView : public QGraphicsView {
public:
    /**
     * @brief CustomView is the constructor to the class.
     * @param parent is the widget of which this resides in.
     */
    CustomView(QWidget* parent = 0);
protected:
    /**
     * @brief wheelEvent
     * @param event
     */
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // CUSTOMVIEW_H
