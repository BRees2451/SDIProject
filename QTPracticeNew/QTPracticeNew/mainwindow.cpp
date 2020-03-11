#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->scale(1.2,1.2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(0.8,0.8);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open A File","C://");
    if (QString::compare(fileName,QString())!= 0){
        QImage image(fileName);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        ui->ImagesWindow->setText(fileName);
        scene->addItem(item);
    }
    else{
        //Error Handling
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog:: getSaveFileName(this, "Save Image", QCoreApplication::applicationDirPath(),"BMP Files (*.bmp);;JPEG (*JPEG);;PNG (*png)");
    if (!fileName.isNull()){
        QPixmap pixMap = this->ui->graphicsView->grab();
        pixMap.save(fileName);
    }
}

void MainWindow::on_DrawRectButton_clicked()//Draw Rectangle
{

    //scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
    rectangle = scene->addRect(300,300,500,500,blackPen,redBrush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_DrawTriangleButton_clicked()//Triangle
{
    //Draw Triangle9*
    QPolygonF Triangle;
    Triangle.append(QPointF(-10.,0));
    Triangle.append(QPointF(0.,-10));
    Triangle.append(QPointF(10.,0));
    Triangle.append(QPointF(-10.,0));

    //QGraphicsPolygonItem* pTriangleItem = ui->(Triangle);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui-> graphicsView ->rotate(-1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui-> graphicsView ->rotate(1);
}
