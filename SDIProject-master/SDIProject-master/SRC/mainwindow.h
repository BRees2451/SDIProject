#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsItem>
#include<QtGui>
#include<QFileDialog>
#include <QMessageBox>
#include <vector>
#include <iostream>
#include <thread>
#include "shareclass.h"
#include "Image.h"
#include "UserShapeOperations.h"
#include "mytimer.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void showMousePosition(QPoint& pos);
    void clickPoint(QPoint&);
    void saveSignal();

private slots:
    void on_ZoomInButton_clicked();

    void on_ZoomOutButton_clicked();

    void on_actionOpen_triggered();

    void on_actionQuit_triggered();

    void on_actionSave_triggered();

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

    void on_DrawRectButton_clicked();

    void on_ImageSearchButton_clicked();

    void on_selectClassButton_clicked();

    void on_deleteShape_clicked();

    void on_selectButton_clicked();

    void on_RemoveClassButton_clicked();

    void on_replaceImageFileName_clicked();


private:
    void Save(bool);
    void open(QString, QString);

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);
    UserShapeOperation *shape = new UserShapeOperation();
    MyTimer *mTimer = new MyTimer();

    QString fileName = "";
    QGraphicsItem *item;
    QString defaultPath = QFileInfo(QDir::currentPath()).path() + "/RESULTS";
    QVector<shareClass::fileData> filesInDirectory;
    QVector<shareClass::fileData> classesInFile;

    QDate currentDate = QDate::currentDate();
    QString classFilePath;
    QString classFileName;

    QString annoFileName;
    QString annoFilePath;
    bool imageActive = false;

    QString selectedClass;

    QString shapeType;
    QPointF previousPos;
    drawnShape *isSelected;
    bool Select = false;

    QGraphicsPathItem *shapeDrawing;

    int autosaveCounter = 1;

};
#endif // MAINWINDOW_H
