#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Image.h"
#include <vector>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    /**
      * https://forum.qt.io/topic/64817/how-to-read-all-files-from-a-selected-directory-and-use-them-one-by-one/3
      * This will fetch the jpg files in the directory and add them to a vector.
      */
    //assume the directory exists and contains some files and you want all jpg and JPG files
    QDir directory("Pictures/MyPictures");
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);
    foreach(QString filename, images) {
    //Add each image to a vector

    }

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


/**
 * @brief MainWindow::on_actionOpen_triggered
 * When a file is opened, if the file is a jpg or png then it will
 * make a new directory and copy the image into there, while creating
 * an empty classes file. When the directory is saved it will compile
 * the directory into a hdf5 file.
 */
void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open A File","C://");
    QFileInfo info(filePath);
    this->fileName = info.fileName();
    if (QString::compare(filePath,QString())!= 0){
        QImage image(filePath);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        ui->ImagesWindow->setText(fileName);
        scene->addItem(item);

        cout << filePath.toUtf8().constData() << endl;
        cout << fileName.toUtf8().constData() << endl;

        QString containString = "QTPracticeNew/Projects/"+this->fileName;
        QString current = QDir::currentPath();
        QString b = "/Projects/"+this->fileName;
        current += QDir(current).filePath(b);

        //Gives correct path
        qDebug(current.toLatin1());

        if (filePath.contains(containString))
        {
            cout << "File is in directory" << endl;
        }
        else
        {

            cout<< "File isn't in directory" << endl;

            ///DOESN'T WORK
            //////////////////////////////////////////////
            bool a = QFile::copy(filePath, current);   ///
            //////////////////////////////////////////////
            if (a) cout << "File copied" << endl;
            else cout << "Error in copy" << endl;
        }

        if (filePath != NULL)
        {
            /**
             * @brief fileName
             * Needs Work
             */
            cout<< "Hello" << endl;
            QString fileName("./Classes.txt");
            QFile file(fileName);
            if(QFileInfo::exists(fileName))
            {
                qDebug () << "file exists" << endl;
                file.open(QIODevice::ReadWrite | QIODevice::Text);
                QString data =  file.readAll();
                qDebug () << "data in file:" << data << endl;
                qDebug()<<"file already created"<<endl;
                file.close();
            }
            else
            {
                /**
                  * Needs Work
                  */
                qDebug () << "file does not exists" << endl;
                file.open(QIODevice::ReadWrite | QIODevice::Text);
                file.write("Classes.txt");
                qDebug()<<"file created"<<endl;
                file.close();
            }
        }
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
   /* //////////////////////// ////////////////////////////////////////////shapelist add triangle1 */
}

void MainWindow::on_pushButton_8_clicked()
{
    ui-> graphicsView ->rotate(-1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui-> graphicsView ->rotate(1);
}

//USE THREADS AND HDF5 FILE FORMAT

void MainWindow::Save()
{
    //We need to pull the relevant data: fileName, Annotations, and Classes File
    //fileName;
    //&Image::annotationsVector;
    //Need to retrieve the classes file

}
