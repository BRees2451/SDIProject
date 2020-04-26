#ifndef MATDISPLAY_H
#define MATDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QMouseEvent>

class matDisplay : public QGraphicsView {
    Q_OBJECT;
public:
    QGraphicsScene *scene;
    matDisplay(QWidget *parent = 0);
    ~matDisplay();

    //virtual void paintEvent(QPaintEvent *event);
private:
    /**
     * @brief buttonDown
     * Detects whether the mouse button is being pressed.
     */
    bool buttonDown;

protected:

    /**
     * @brief mouseMoveEvent
     * Deals with the mouse being moved and gets the position
     * of the momevent.
     * @param mouse_event represents the current mouse event.
     */
    void mouseMoveEvent(QMouseEvent *mouse_event);

    /**
     * @brief mousePressEvent
     * Deals with the mouse being pressed and
     * gets the position of it being pressed.
     * @param mouse_event represents the current mouse event.
     */
    void mousePressEvent(QMouseEvent *mouse_event);


signals:
    /**
     * @brief sendMousePosition
     */
    void sendMousePosition(QPoint&);
    /**
     * @brief sendMousePress
     */
    void sendMousePress(QPoint&);
    /**
     * @brief sendMouseRelease
     */
    void sendMouseRelease(QPoint&);
};

#endif // MATDISPLAY_H
