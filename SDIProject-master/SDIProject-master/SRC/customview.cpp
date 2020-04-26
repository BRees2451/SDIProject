#include "customview.h"
/**
 * @brief CustomView::CustomView is an empty constructor to which
 * will instantiate this class.
 * @param parent denotes the parent widget of which this resides in.
 */
CustomView::CustomView(QWidget *parent) : QGraphicsView(parent)
{

}

/**
 * @brief CustomView::wheelEvent is used to scroll/zoom in on the canvas.
 * @param event is an mouse wheel event passed in.
 */
void CustomView::wheelEvent(QWheelEvent *event) {
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;

    if(event->delta()>0) {
        scale(scaleFactor, scaleFactor);
    }
    else {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}
