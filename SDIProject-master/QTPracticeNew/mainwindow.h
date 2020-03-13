#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QtGui>
#include<QFileDialog>
#include <QtCore>
#include <iostream>
#include <string>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //List of images


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Save();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionOpen_triggered();

    void on_actionQuit_triggered();

    void on_actionSave_triggered();

    void on_DrawRectButton_clicked();

    void on_DrawTriangleButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    QString fileName = "";

    Ui::MainWindow *ui;

    QGraphicsItem *item;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsPolygonItem *shape;
};
#endif // MAINWINDOW_H
