#include "matdisplay.h"
#include <QMessageBox>
#include <QDebug>


matDisplay::matDisplay(QWidget* parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    this->setMouseTracking(true);
}

matDisplay::~matDisplay() {

}

void matDisplay::mouseMoveEvent(QMouseEvent *mouse_event) {
    QPoint mouse_pos = mouse_event->pos();


    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()) {
        if(mouse_pos.x() >= 0 && mouse_pos.y() >= 0) {

            emit sendMousePosition(mouse_pos);
        }
    }
}

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

