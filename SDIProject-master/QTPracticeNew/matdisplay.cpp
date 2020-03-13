#include "matdisplay.h"
#include <QMessageBox>


matDisplay::matDisplay(QWidget* parent) : QGraphicsView(parent)
{
    this->setMouseTracking(true);
}

matDisplay::~matDisplay()
{

}

void matDisplay::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();


    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()){
        if(mouse_pos.x() >= 0 && mouse_pos.y() >= 0){


            emit sendMousePosition(mouse_pos);
        }
    }
}

/*
void matDisplay::mousePressEvent(QMouseEvent *mouse_event)
{
    QMessageBox msg;
    if(mouse_event->button() == Qt::LeftButton)
    {

        msg.setText("Left mouse button pressed!");
        msg.exec();
    }
    else if(mouse_event->buttons() == Qt::RightButton)
    {
        msg.setText("Right mouse button pressed!");
        msg.exec();
    }
}
*/
