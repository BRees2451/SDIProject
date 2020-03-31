#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UserShapeOperations.h"
#include <vector>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    UserShapeOperation User = *new UserShapeOperation;

    Image currentImage;

    connect(ui->graphicsView,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));

    /**
      * https://forum.qt.io/topic/64817/how-to-read-all-files-from-a-selected-directory-and-use-them-one-by-one/3
      * This will fetch the jpg files in the directory and add them to a vector.
      */
    //assume the directory exists and contains some files and you want all jpg and JPG files
    QDir directory(defaultPath);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG",QDir::Files);
    for(int i = 0; i < images.length(); i++) {
        QFileInfo modified = QFileInfo(directory, images[i]);
        shareClass::fileData fData;
        fData.name = images[i];
        fData.dateModified = modified.lastModified();
        qDebug() << fData.dateModified.toString() << "Hello" << endl;

        //Add each image to a vector
        cout<<images[i].toUtf8().constData()<<endl;

        filesInDirectory.push_back(fData);
        ui->ImagesWindow->addItem(images[i] + "\t\t" + fData.dateModified.toString("hh:mm\tdd/MM/yy"));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ZoomInButton_clicked()
{
    ui->graphicsView->scale(1.2,1.2);
}

void MainWindow::on_ZoomOutButton_clicked()
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
    QString filePath = QFileDialog::getOpenFileName(this, "Open A File",defaultPath);
    QFileInfo info(filePath);
    fileName = info.fileName();
    qDebug()<<fileName <<endl;

    //ERROR CAUSED HERE
    /*if(!fileName.endsWith(".jpg",Qt::CaseSensitive) || !fileName.endsWith(".png",Qt::CaseSensitive))
    {
        qDebug() << "Not a compatible image format" << endl;
        return;
    }*/


    open(filePath, fileName);


    //}
    /*
    else{
        //Error Handling
    }*/
}

void MainWindow::on_AddImageButton_clicked()
{
    on_actionOpen_triggered();
    /*
    QString filePath = QFileDialog::getOpenFileName(this, "Open A File",defaultPath);
    QFileInfo info(filePath);
    fileName = info.fileName();
    if (QString::compare(filePath,QString())!= 0){
        QImage image(filePath);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        scene->addItem(item);
    }*/
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

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
    rectangle = scene->addRect(300,300,500,500,blackPen);
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

void MainWindow::on_RotateLButton_clicked()
{
    ui-> graphicsView ->rotate(-1);
}

void MainWindow::on_RotateRButton_clicked()
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

void MainWindow::showMousePosition(QPoint &pos)
{
    ui->mouse_position_label->setText("x: "+ QString::number(pos.x()) + " y: "+ QString::number(pos.y()));
    double rad = 1;
    //circle = scene->addEllipse(pos.x()-rad,pos.y()-rad,rad*2.0,rad*2.0);

}

void MainWindow::mousePressEvent(QMouseEvent *mouse_event){
    QPoint mouse_pos = mouse_event->pos();
    double rad = 1;
    circle = scene->addEllipse(mouse_pos.x()-rad,mouse_pos.x()-rad,rad*2.0,rad*2.0);
}


void MainWindow::on_selectImage_clicked()
{
    for (int i = 0; i < filesInDirectory.size()-1; i++)
    {
        ui->ImagesWindow->item(i)->setTextColor(Qt::black);
    }
    QListWidgetItem *selected = ui->ImagesWindow->currentItem();
    //selected->setTextColor(Qt::red);
    QStringList fName = selected->text().split("\t");
    QString currentImage = defaultPath + "/" + fName[0];
    open(currentImage, fName[0]);
}


/**
 * @brief MainWindow::open uses will pull the selected image to the scene if the image exists as well as check
 * for whether it is a jpg or png. This method will also validate whether there's a txt file to match the image.
 * If not one will be created.
 * @param filePath
 * @param fileName
 */
void MainWindow::open(QString filePath, QString fileName)
{
    scene->clear();
    if (QString::compare(filePath,QString())!= 0){
        QImage image(filePath);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        scene->addItem(item);
    }
    cout << filePath.toUtf8().constData() << endl;

    QString containString = "QTPracticeNew/Projects/"+fileName;

    QString Destination;
    if (filePath.contains(containString))
    {
        cout << "File is in directory" << endl;
        Destination = QFileInfo(QDir::currentPath()).path();
    }
    else
    {

        Destination = defaultPath + "/" + fileName;
        cout<< "File isn't in directory" << endl;

        bool a = QFile(filePath).copy(Destination);
        if (a){
            cout << "This works" << endl;
        }
        else cout << "This doesnt work" << endl;
    }

    QStringList absoluteFileName = fileName.split(".");
    absoluteFileName[0] = "ClassesFile_" + absoluteFileName[0];
    absoluteFileName[1] = "txt";
    classFileName = absoluteFileName.join(".");

    QStringList classTextFilePath = Destination.split("/");
    classTextFilePath[classTextFilePath.length()-1] = classFileName;
    classFilePath = classTextFilePath.join("/");

    if (classFilePath != NULL)
    {
        QFile file(classFilePath);
        if(QFileInfo::exists(classFilePath))
        {
            cout << "file exists" << endl;
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QStringList dataFromFile;
            QTextStream in(&file);
            while(!in.atEnd()) {
                QString line = in.readLine();
                dataFromFile.append(line);
            }
            ui->ClassWindow->clear();
            for(int i = 1; i < dataFromFile.length()-1;i++)
            {
                classesInFile.push_back({dataFromFile[i], QDateTime::currentDateTime()});
                ui->ClassWindow->addItem(dataFromFile[i]);
            }

            cout<<"file already created"<<endl;
            file.close();
            QDateTime modified = QFileInfo(classFilePath).lastModified();
            if (!modified.isNull()) filesInDirectory.push_back({fileName, QFileInfo(classFilePath).lastModified()});
            else filesInDirectory.push_back({fileName, QDateTime::currentDateTime()});
        }
        else
        {
            cout << "file does not exists" << endl;
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QString dateString = currentDate.toString("hh:mm\tdd/MM/yy");
            file.write("Classes\n");
            file.write(dateString.toUtf8().constData());
            qDebug()<<"file created"<<endl;
            file.close();
            filesInDirectory.push_back({fileName, QDateTime::currentDateTime()});
            ui->ImagesWindow->addItem(fileName);
        }
        imageActive = true;
    }
     else {
        imageActive = false;
        //error handle
    }
}

/**
 * @brief MainWindow::on_addClassButton_clicked This will enable the textbox.
 */
void MainWindow::on_addClassButton_clicked()
{
    if (imageActive) ui->newClassLineEdit->setEnabled(1);
}

/**
 * @brief MainWindow::on_newClassLineEdit_returnPressed This will disable and clear the textbox as well as increment
 * the class vectors and file as well as push this new information to the GUI.
 */
void MainWindow::on_newClassLineEdit_returnPressed()
{
    QString text = ui->newClassLineEdit->text();
    ui->newClassLineEdit->setText("");
    ui->newClassLineEdit->setEnabled(0);

    classesInFile.push_back({text, QDateTime::currentDateTime()});
    ui->ClassWindow->addItem(text);

    QFile file(classFilePath);
    if(QFileInfo::exists(classFilePath))
    {
        cout << "file exists" << endl;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.write("Classes");
        for (int i = 0; i < classesInFile.size(); i++)
        {
            file.write(("\n"+classesInFile[i].name).toUtf8().constData());
        }

        file.close();
    }
    qDebug() << text << endl;
}

/**
 * @brief MainWindow::on_sortClassBy_currentIndexChanged This will react to when the index is changed by directing
 * the information to the correct methods as well as push the sorted list to the GUI.
 * @param arg1
 */
void MainWindow::on_sortClassBy_currentIndexChanged(const QString &arg1)
{
    Image image;
    if (arg1 == "Name (Asc)") classesInFile = image.SortAscendingName(classesInFile);
    else if (arg1 == "Name (Desc)") classesInFile = image.SortDescendingName(classesInFile);
    ui->ClassWindow->clear();
    for (int i = 0; i < classesInFile.size(); i++)
    {
        ui->ClassWindow->addItem(classesInFile[i].name);
        ui->ClassWindow->item(i)->setTextColor(Qt::black);
    }
}

/**
 * @brief MainWindow::on_sortImageBy_currentIndexChanged This also will react to when the index is changed by
 * directing the information to the correct methods as well as push the sorted list to the GUI.
 * @param arg1
 */
void MainWindow::on_sortImageBy_currentIndexChanged(const QString &arg1)
{
    Image image;

    if (arg1 == "Name (Asc)") filesInDirectory = image.SortAscendingName(filesInDirectory);
    else if (arg1 == "Name (Desc)") filesInDirectory = image.SortDescendingName(filesInDirectory);
    else if (arg1 == "Date (Asc)") filesInDirectory = image.SortAscendingDate(filesInDirectory);
    else if (arg1 == "Date (Desc)") filesInDirectory = image.SortDescendingDate(filesInDirectory);
    ui->ImagesWindow->clear();
    for (int i = 0; i < filesInDirectory.size(); i++)
    {
        QString concatenatedItem = filesInDirectory[i].name + "\t\t" + filesInDirectory[i].dateModified.toString("hh:mm\tdd/MM/yy");
        ui->ImagesWindow->addItem(concatenatedItem);
        ui->ImagesWindow->item(i)->setTextColor(Qt::black);
    }
}
