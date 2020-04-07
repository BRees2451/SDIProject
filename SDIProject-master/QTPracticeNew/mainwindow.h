#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsItem>
#include<QtGui>
#include<QFileDialog>
#include <QMessageBox>
//#include <QtCore>
#include <vector>
#include <iostream>
#include "shareclass.h"
#include "Image.h"
#include "canvas.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString shapeType;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Save();


private slots:
    void on_ZoomInButton_clicked();

    void on_ZoomOutButton_clicked();

    void on_actionOpen_triggered();

    void on_actionQuit_triggered();

    void on_actionSave_triggered();

    void on_DrawRectButton_clicked(QMouseEvent *mouse_event);

    void on_DrawTriangleButton_clicked();

    void on_DrawTrapButton_clicked();

    void on_DrawPolyButton_clicked();

    void on_RotateLButton_clicked();

    void on_RotateRButton_clicked();

    void on_AddImageButton_clicked();

    void on_selectImage_clicked();

    void on_addClassButton_clicked();

    void on_newClassLineEdit_returnPressed();

    void on_sortClassBy_currentIndexChanged(const QString &arg1);

    void on_sortImageBy_currentIndexChanged(const QString &arg1);

    void openImage(QString imagePath);

    void on_resizeShape_clicked();

    void on_DrawRectButton_clicked();

    void clickPoint(QMouseEvent *mouse_event);

    void TesterFunction();

private:
    void open(QString, QString);

    QString fileName = "";

    Ui::MainWindow *ui;

    Canvas *canvas;

    QGraphicsItem *item;
    //QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsPolygonItem *shape;
    QGraphicsEllipseItem *circle;


    ///////////////////////////////////////////////
    //Image* currentImage;
    ///////////////////////////////////////////////

    //QListWidget *ImageList;
    QString defaultPath = QFileInfo(QDir::currentPath()).path() + "/Projects";

    //A vector to contain the shapes
    QVector<QPolygonF> ShapeList;


    QVector<shareClass::fileData> filesInDirectory;
    QVector<shareClass::fileData> classesInFile;

    QDate currentDate = QDate::currentDate();
    QString classFilePath;
    QString classFileName;
    bool imageActive = false;



public slots:
    void showMousePosition(QPoint& pos);
    //void mousePressEvent(QMouseEvent *mouse_event);

};
#endif // MAINWINDOW_H
