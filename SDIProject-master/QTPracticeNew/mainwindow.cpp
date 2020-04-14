#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "matdisplay.h"
#include <vector>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    //UserShapeOperation User = *new UserShapeOperation;
    //matDisplay ImagePane = *new matDisplay;

    Image currentImage;

    connect(ui->graphicsView,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
    connect(ui->graphicsView,SIGNAL(mousePressEvent(QMouseEvent *event)), SLOT(clickPoint(QMouseEvent *event)));
    //connect(ui->graphicsView, SIGNAL(mousePressEvent(QMo)))
    //connect(ui->graphicsView, SIGNAL(&Canvas::mousePressed), this, SLOT(&MainWindow::TesterFunction));
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
/*
void matDisplay::mousePressEvent(QMouseEvent *mouse_event){
    //if (MainWindow::shapeType != NULL)
    {


    }

}*/


void MainWindow::on_DrawRectButton_clicked(QMouseEvent *mouse_event)//Draw Rectangle
{
    this->shapeType = "Rectangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Rectangle");

    int xstart;
    int ystart;
    int xend;
    int yend;

    if(ui->DrawRectButton->isChecked()){
        /*
         * i want to use the mouse events from mat display so that it gets it for image pane
         **/

        if (QEvent::MouseButtonPress)
        {
            xstart = mouse_event->x();
            ystart = mouse_event->y();
            xend = mouse_event->x();
            yend = mouse_event->y();
            cout<<mouse_event->x()<<mouse_event->y(); //--------------> doesnt print this

        }
        if (QEvent::MouseMove)
        {
            xend = mouse_event->x();
            yend = mouse_event->y();
        }


        QPolygonF Rectangle;

        Rectangle.append(QPointF(xstart, ystart));
        Rectangle.append(QPointF(xend, ystart));
        Rectangle.append(QPointF(xend, yend));
        Rectangle.append(QPointF(xstart, yend));

        QPen blackPen(Qt::black);
        blackPen.setWidth(6);

        scene->addPolygon(Rectangle,blackPen);
        ShapeList.append(Rectangle);
    }
}

void MainWindow::on_DrawRectButton_clicked()
{
    this->shapeType = "Rectangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Rectangle");

    QPolygonF Rectangle;

    Rectangle.append(QPointF(50, 50));
    Rectangle.append(QPointF(150, 50));
    Rectangle.append(QPointF(150, 150));
    Rectangle.append(QPointF(50, 150));

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    scene->addPolygon(Rectangle,blackPen);
    ShapeList.append(Rectangle);

}

void MainWindow::on_DrawTriangleButton_clicked()//Triangle
{
    this->shapeType = "Triangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Triangle");

    int xstart = 0;
    int ystart = 0;
    int xend = 0;
    int yend = 0;

    //Get mouse posisiton on matdisplay window

    int halfway = xstart + ((xend-xstart)/2);

    QPolygonF Triangle;
    Triangle.append(QPointF(xstart,yend));
    Triangle.append(QPointF(xend,yend));
    Triangle.append(QPointF(halfway,ystart));

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    scene->addPolygon(Triangle,blackPen);
    ShapeList.append(Triangle);
}

void MainWindow::on_DrawTrapButton_clicked()
{
    this->shapeType = "Trapezium";
    this->ui->shapeTypeLabel->setText("Shape Type: Trapezium");

    int xstart = 0;
    int ystart = 0;
    int xend = 0;
    int yend = 0;

    //Get mouse posisiton on matdisplay window

    int trapindent = (xend-xstart)/4;

    QPolygonF Trapezium;
    Trapezium.append(QPointF(xstart + trapindent, ystart));
    Trapezium.append(QPointF(xend - trapindent, ystart));
    Trapezium.append(QPointF(xend,yend));
    Trapezium.append(QPointF(xstart,yend));

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    scene->addPolygon(Trapezium,blackPen);
    ShapeList.append(Trapezium);
}

void MainWindow::on_DrawPolyButton_clicked()

{
    this->shapeType = "Polygon";
    this->ui->shapeTypeLabel->setText("Shape Type: Polygon");

    int x[7];
    int y[7];
    int finalpoint = 0;

    QMessageBox msg;
    msg.setText("Please click up to 8 points.");
    msg.exec();

    for (int i = 0; i < 7; i++)
    {

       // if(mouse_event->button() == Qt::LeftButton)
        //{
          //  QPoint mouse_pos = mouse_event->pos();
            //x[i] = mouse_pos.x();
            //y[i] = mouse_pos.y();
            //i++;
        //}

        if (i==6)
        {
        msg.setText("You have picked the maximum of points, the last one will join back to the first one.");
        msg.exec();
        }

        // will add function to identify final point when it is clicked on/near to the original
    }

    QPolygonF Polygon;

    for(int i = 0; i < finalpoint; i++)
    {
        Polygon.append(QPointF(x[i],y[i]));
    }

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    scene->addPolygon(Polygon,blackPen);
    ShapeList.append(Polygon);


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
    bool a = QApplication::mouseButtons();
    bool pressed;
    if (a) {
        pressed = true;
        if(shapeType != NULL){
            QPoint *position = new QPoint(pos.x(), pos.y());
            shape->handleMouseEvent(shapeType, " ", position);
            double rad = 1;
            circle = scene->addEllipse(pos.x()-rad,pos.y()-rad,rad*2.0,rad*2.0);
            //We get the shapeType and make a new user shape operation
            //Then keep updating the drawing.
        }
    }
    if (a == false){
        for (drawnShape *s : shape->shapeList){
            s->isBeingDrawn = false;
        }
    }

    //qDebug() << "Mouse Pressed" <<endl;
    ui->mouse_position_label->setText("x: "+ QString::number(pos.x()) + " y: "+ QString::number(pos.y()));

}

void MainWindow::clickPoint(QMouseEvent *mouse_event){
    QPoint mouse_pos = mouse_event->pos();
    qDebug() << mouse_pos <<endl;
    double rad = 1;
    circle = scene->addEllipse(mouse_pos.x()-rad,mouse_pos.x()-rad,rad*2.0,rad*2.0);
}

void MainWindow::TesterFunction()
{
    qDebug() << "THIS WORKS";
}


void MainWindow::on_selectImage_clicked() //Displays the image selected on the pane
{
    for (int i = 0; i < filesInDirectory.size()-1; i++)
    {
        qDebug() << ui->ImagesWindow->item(i)->text() << endl;
        ui->ImagesWindow->item(i)->setTextColor(Qt::black);

    }
    QListWidgetItem *selected = ui->ImagesWindow->currentItem();
    if (selected != NULL){
        selected->setTextColor(Qt::red);
        QStringList a = selected->text().split("\t");
        QString currentImage = defaultPath + "/" + a[0];
        open(currentImage, a[0]);
    }
    else {
        qDebug() << "Click on an image before pressing 'Select Image'" << endl;
    }

}

void MainWindow::openImage(QString imagePath) //Opens image onto pane
{
    scene->clear();
    if (QString::compare(imagePath,QString())!= 0){
        QImage image(imagePath);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        scene->addItem(item);
    }
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
    //Put this back because if someone is looking to open an image then they are planning on editting it
    //We can discuss about this later.
    if (QString::compare(filePath,QString())!= 0){
           QImage image(filePath);
           item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
           ui->graphicsView->setScene(scene);
           scene->addItem(item);
       }
    cout << filePath.toUtf8().constData() << endl;

    QString containString = "/Projects/"+fileName;

    QString Destination;

    //Will check whether file is in 'Projects' folder
    if (filePath.contains(containString))
    {
        cout << "File is in directory" << endl;
        Destination = QFileInfo(QDir::currentPath()).path();
    }
    else
    {
        //Will construct a destination
        Destination = defaultPath + "/" + fileName;
        cout<< "File isn't in directory" << endl;

        //Copy the file to the destination and check
        bool a = QFile(filePath).copy(Destination);
        if (a){
            cout << "This works" << endl;
        }
        else cout << "This doesnt work" << endl;
    }

    //Will minipulate the string to give a .txt file path
    QStringList absoluteFileName = fileName.split(".");
    absoluteFileName[0] = absoluteFileName[0] + ".names";
    absoluteFileName[1] = "txt";
    classFileName = absoluteFileName.join(".");

    classFilePath = Destination + "/Projects/" + classFileName;

    if (classFilePath != NULL)
    {
        QFile file(classFilePath);
        //If file exists it will read the data into a list
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
            //Add the classes to the classWindow
            ui->ClassWindow->clear();
            classesInFile.clear();
            for(int i = 1; i < dataFromFile.length();i++)
            {
                classesInFile.push_back({dataFromFile[i], QDateTime::currentDateTime()});
                ui->ClassWindow->addItem(dataFromFile[i]);
            }

            cout<<"file already created"<<endl;
            file.close();
        }
        else
        {
            //Will create a file at the given path as well as make the new file conform to the display we are using
            cout << "file does not exist" << endl;
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            file.write("Classes\n");
            qDebug()<<"file created"<<endl;
            file.close();
            filesInDirectory.push_back({fileName, QDateTime::currentDateTime()});
            QString itemString = fileName+"\t\t" + QDateTime::currentDateTime().toString("hh:mm\tdd/MM/yy");
            ui->ImagesWindow->addItem(itemString);
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

void MainWindow:: on_resizeShape_clicked()
{
    //UserShapeOperation user;
   // user.USize();

}



void MainWindow::on_ImageSearchButton_clicked()
{
    Image image;

    //get the contents of line edit
    QString searchName = ui->ImageSearchLine->text();

    // Call search algorithm inside image class
    int searchIndex = image.searchImageName(filesInDirectory,searchName);
    // returns the index of the location in the image vector

    if(searchIndex == -1){
        ui->ImageSearchLine->setText("Image not found");
    }
    else{
        ui->ImageSearchLine->setText("Image found");
        // set the colour of the image searched to green ???
        // using searchIndex
    }
}
