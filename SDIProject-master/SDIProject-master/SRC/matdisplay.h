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

    //virtual void paintEvent(QPaintEvent *event);
private:
    bool buttonDown;

protected:

    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);


signals:
    void sendMousePosition(QPoint&);
    void sendMousePress(QPoint&);
    void sendMouseRelease(QPoint&);
};

#endif // MATDISPLAY_H
