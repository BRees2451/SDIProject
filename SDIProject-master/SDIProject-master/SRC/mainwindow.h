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



/**
 * @brief The MainWindow class is the bulk of the
 * code. It represents the body of what is going on
 * during the programming process.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * This is the Constructor to the Main Window class
     * @param parent denotes the parent of which the widget is in.
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void showMousePosition(QPoint& pos);
    void clickPoint(QPoint&);
    void saveSignal();

private slots:
    /**
     * @brief on_ZoomInButton_clicked
     * When the button is clicked, the image is zoomed in on by 20%
     */
    void on_ZoomInButton_clicked();

    /**
     * @brief on_ZoomOutButton_clicked
     * When the button is clicked, the image is zoomed out to 80%
     * of the original image.
     */
    void on_ZoomOutButton_clicked();

    /**
     * @brief on_actionOpen_triggered
     * When a file is opened a directory is created which the image is
     * copied into (as long as it is a .jpg or .png) An empty class file
     * is also created for the image. When the directory is saved it is
     * compiled into a hdf5 file.
     */
    void on_actionOpen_triggered();

    /**
     * @brief on_actionQuit_triggered
     * Quits the program.
     */
    void on_actionQuit_triggered();

    /**
     * @brief on_actionSave_triggered
     * Saves the image.
     */
    void on_actionSave_triggered();

    /**
     * @brief on_DrawTriangleButton_clicked
     * Sets a triangle to be drawn.
     */
    void on_DrawTriangleButton_clicked();

    /**
     * @brief on_DrawTrapButton_clicked
     *  * Sets the shape to be drawn as a trapezium.
     */
    void on_DrawTrapButton_clicked();

    /**
     * @brief on_DrawPolyButton_clicked
     *  * Sets the shape to be drawn as a polygon.
     */
    void on_DrawPolyButton_clicked();

    /**
     * @brief on_RotateLButton_clicked
     * Rotates the image towards the left.
     */
    void on_RotateLButton_clicked();

    /**
     * @brief on_RotateRButton_clicked
     * Rotates the image towards the right.
     */
    void on_RotateRButton_clicked();

    /**
     * @brief on_AddImageButton_clicked
     * When the 'Add Image' button is pressed it selects
     * an image in the same way the 'Open' function does.
     */
    void on_AddImageButton_clicked();

    /**
     * @brief on_selectImage_clicked
     * Places the image onto the canvas once the image is selected.
     */
    void on_selectImage_clicked();

    /**
     * @brief on_addClassButton_clicked
     * Enables the add class textbox.
     */
    void on_addClassButton_clicked();

    /**
     * @brief on_newClassLineEdit_returnPressed
     * Disables and clears the textbox aswell as incrementing the
     * class vectors and file. Pushes this to the GUI.
     */
    void on_newClassLineEdit_returnPressed();

    /**
     * @brief on_sortClassBy_currentIndexChanged
     * Reacts to when the index is changed by directing
     * the information to the correct methods as well as
     * push the sorted list to the GUI.
     * @param arg1
     */
    void on_sortClassBy_currentIndexChanged(const QString &arg1);

    /**
     * @brief on_sortImageBy_currentIndexChanged
     * Reacts to when the index is changed by directing the information
     * to the correct methods as well as push the sorted list to the GUI.
     * @param arg1
     */
    void on_sortImageBy_currentIndexChanged(const QString &arg1);

    /**
     * @brief openImage
     * Opens the chosen image to put onto the canvas.
     * @param imagePath represents the path of where the chosen image is located
     */
    void openImage(QString imagePath);

    /**
     * @brief on_DrawRectButton_clicked
     *  * Sets the shape to be drawn as a rectangle.
     */
    void on_DrawRectButton_clicked();

    /**
     * @brief on_ImageSearchButton_clicked
     * Searches the images imported into the pane for a certain
     * specified image.
     */
    void on_ImageSearchButton_clicked();

    /**
     * @brief on_selectClassButton_clicked
     * Searches the images imported into the pane for a certain
     * specified image.
     */
    void on_selectClassButton_clicked();

    /**
     * @brief on_deleteShape_clicked
     * Deletes a shape.
     */
    void on_deleteShape_clicked();

    /**
     * @brief on_selectButton_clicked
     * Selects a shape.
     */
    void on_selectButton_clicked();

    /**
     * @brief on_RemoveClassButton_clicked
     * Removes a class.
     */
    void on_RemoveClassButton_clicked();


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

    QString imageFilePath;

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
