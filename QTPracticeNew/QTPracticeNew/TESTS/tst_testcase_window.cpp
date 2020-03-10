
#include <QtTest/QtTest>
#include <QtWidgets/QMainWindow>
#include<QtWidgets/QGraphicsItem>
#include<QtWidgets/QGraphicsScene>
#include<QtGui/QtGui>
#include<QtWidgets/QFileDialog>
#include <QtCore>
#include <QtWidgets/QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    //void on_actionOpen_triggered();

    void on_actionQuit_triggered();

    //void on_actionSave_triggered();

    //void on_DrawRectButton_clicked();

    //void on_DrawTriangleButton_clicked();

    //void on_pushButton_8_clicked();

    //void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsItem *item;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsPolygonItem *shape;
};

//MainWindow::~MainWindow()
//{
//    delete ui;
//}
void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


QTEST_APPLESS_MAIN(MainWindow)

#include "tst_testcase_window.moc"


//#endif // MAINWINDOW_H

