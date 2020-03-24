#include "Button.h"
#include <QGraphicsTextItem>

void Button::ButtonPressed() {
    //emit Clicked();
	throw "Not yet implemented";
}

void Button::AddButton(QMouseEvent *mouse_event, string Text, QGraphicsRectItem) {
    /*
    if (addbutton == true){
        QPoint mouse_pos = mouse_event->pos();
        QWidget *wdg = new QWidget(this,mouse_pos.x(),mouse_pos.y());
        QPushButton *AButon = new QPushButton(wdg);
        AButton->setText(tr(Text));
        setCentralWidget(wdg);
    }
    */
    /*setRect(mouse_pos.x(),mouse_pos.y(),101,31);
    Name = new QGraphicsTextItem(Text,this);
    int xPos = rect().width()/2 - Name.boundingRect().width/2;
    int yPos = rect().height()/2 - Name.boundingRect().height/2;
    Name.setPos(xPos,yPos);*/
	throw "Not yet implemented";
}

void Button::RemoveButton(QMouseEvent *mouse_event) {
    /*
     * QPoint mouse_pos = mouse_event->pos();
     * */

	// TODO - implement Button::RemoveButton
	throw "Not yet implemented";
}
