#ifndef BUTTON_H
#define BUTTON_H
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QtGui>
#include <QMainWindow>
#include <QtCore>
#include <iostream>
using namespace std;

class Button: public QGraphicsRectItem {

private:
    string Name;

signals:
    void Clicked();

public:
    //constructor
    Button(QString name, QGraphicsItem* parent = NULL);

    void ButtonPressed();

    void AddButton(QMouseEvent *mouse_event, string, QGraphicsRectItem);

    void RemoveButton(QMouseEvent *mouse_event);
};

#endif
