#include "matdisplay.h"
#include <QMessageBox>
#include <QDebug>


/**
 * @brief matDisplay::matDisplay
 * Constructs the 'matDisplay' and allows
 * the mouse to be tracked.
 * @param parent
 */
matDisplay::matDisplay(QWidget* parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    this->setMouseTracking(true);
}

/**
 * @brief matDisplay::~matDisplay
 * Deconstructor
 */
matDisplay::~matDisplay() {

}

/**
 * @brief matDisplay::mouseMoveEvent
 * Deals with the mouse being moved and gets the position
 * of the momevent.
 * @param mouse_event represents the current mouse event.
 */
void matDisplay::mouseMoveEvent(QMouseEvent *mouse_event) {
    QPoint mouse_pos = mouse_event->pos();


    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()) {
        if(mouse_pos.x() >= 0 && mouse_pos.y() >= 0) {

            emit sendMousePosition(mouse_pos);
        }
    }
}

/**
 * @brief matDisplay::mousePressEvent
 * Deals with the mouse being pressed and
 * gets the position of it being pressed.
 * @param mouse_event represents the current mouse event.
 */
void matDisplay::mousePressEvent(QMouseEvent *mouse_event) {
    QMessageBox msg;
    QPoint mouse_pos = mouse_event->pos();
    if(mouse_event->button() == Qt::LeftButton) {
        if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()) {
            if(mouse_pos.x() >= 0 && mouse_pos.y() >= 0) {
                this->buttonDown = true;
                emit sendMousePress(mouse_pos);
            }
        }
    }
}

