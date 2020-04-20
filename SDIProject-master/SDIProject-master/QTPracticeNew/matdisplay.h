#ifndef MATDISPLAY_H
#define MATDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QLabel>

#include <QGraphicsView>

#include <QMouseEvent>

class matDisplay : public QGraphicsView
{
    Q_OBJECT;
public:
    QGraphicsScene *scene;
    matDisplay(QWidget *parent = 0);
    ~matDisplay();

protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


signals:
    void sendMousePosition(QPoint&);
};

#endif // MATDISPLAY_H
