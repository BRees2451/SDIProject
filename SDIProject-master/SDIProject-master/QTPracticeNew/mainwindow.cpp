#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matdisplay.h"
//#include <vector>
#include <QPixmap>
//#include "h5cpp.h"
//using namespace H5;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Image currentImage;

    connect(ui->graphicsView,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
    connect(ui->graphicsView,SIGNAL(mousePressEvent(QMouseEvent *event)), SLOT(clickPoint(QMouseEvent *event)));

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

void MainWindow::on_DrawRectButton_clicked()
{
    this->shapeType = "Rectangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Rectangle");

}

void MainWindow::on_DrawTriangleButton_clicked()//Triangle
{
    this->shapeType = "Triangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Triangle");
}

void MainWindow::on_DrawTrapButton_clicked()
{
    this->shapeType = "Trapezium";
    this->ui->shapeTypeLabel->setText("Shape Type: Trapezium");
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
    //ShapeList.append(Polygon);


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
    QPointF latest;
    bool a = QApplication::mouseButtons();
    if (a) {
        if(shapeType != NULL && (selectedClass != NULL||selectedClass != "")){
            QPoint *position = new QPoint(pos.x(), pos.y());
            shape->handleMouseEvent(shapeType, selectedClass, position);
        }
        latest = pos;
    }
    if (a == false){
        for (drawnShape *s : shape->shapeList){
            if (s->shapeType == "Polygon"){
                if (s->shape.size() != 8){
                    //((polygonShape)s)->addPoint(latest);
                }
                else s->isBeingDrawn = false;
                shape->drawShape();
            }
            else s->isBeingDrawn = false;
            shape->drawShape();
            if (s->drawn == false) {
                QPen blackPen(Qt::black);
                blackPen.setWidth(6);
                scene->addPolygon(s->shape,blackPen);
                s->drawn = true;
            }


        }
    }

    ui->mouse_position_label->setText("x: "+ QString::number(pos.x()) + " y: "+ QString::number(pos.y()));

}

void MainWindow::clickPoint(QMouseEvent *mouse_event){
    QPoint mouse_pos = mouse_event->pos();
    qDebug() << mouse_pos <<endl;
    double rad = 1;
    circle = scene->addEllipse(mouse_pos.x()-rad,mouse_pos.x()-rad,rad*2.0,rad*2.0);
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
    absoluteFileName = classFileName.split(".");
    absoluteFileName[0] = absoluteFileName[0] + ".annotations";
    absoluteFileName[1] = "";
    annoFileName = absoluteFileName.join(".");

    classFilePath = Destination + "/Projects/" + classFileName;
    annoFilePath = Destination + "/Projects/" + annoFileName;
    if (Destination != NULL && classFileName != NULL && annoFileName != NULL)
    {
        QFile classFile(classFilePath);
        QFile annoFile(annoFilePath);

        if (QFileInfo::exists(annoFilePath)){
            //READ HDF5
            //H5File file( FILE_NAME, H5F_ACC_RDONLY );
            //DataSet dataset = file.openDataSet( DATASET_NAME );
        }
        else{
            annoFile.open(QIODevice::WriteOnly | QIODevice::Text);
            annoFile.write("Annotations\n");
            annoFile.close();
        }

        //If file exists it will read the data into a list
        if(QFileInfo::exists(classFilePath))
        {
            cout << "file exists" << endl;
            classFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QStringList dataFromFile;
            QTextStream in(&classFile);
            while(!in.atEnd()) {
                QString line = in.readLine();
                dataFromFile.append(line);
            }
            //Add the classes to the classWindow
            selectedClass = "";
            ui->ClassWindow->clear();
            classesInFile.clear();
            for(int i = 1; i < dataFromFile.length();i++)
            {
                classesInFile.push_back({dataFromFile[i], QDateTime::currentDateTime()});
                ui->ClassWindow->addItem(dataFromFile[i]);
            }

            cout<<"file already created"<<endl;
            classFile.close();
        }
        else
        {
            //Will create a file at the given path as well as make the new file conform to the display we are using
            cout << "file does not exist" << endl;
            classFile.open(QIODevice::WriteOnly | QIODevice::Text);
            classFile.write("Classes\n");
            qDebug()<<"file created"<<endl;
            classFile.close();
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
    //shape->usize;
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

void MainWindow::on_selectClassButton_clicked()
{
    QListWidgetItem *selected = ui->ClassWindow->currentItem();
    if (selected != NULL){
        selected->setTextColor(Qt::red);
    }
    selectedClass = selected->text();
    //EXCEPTION if you dont select a class
}

void MainWindow::on_deleteShape_clicked()
{
   /* if (on_Selected_clicked(true,){
        shape->Delete(shapeType," ");
    }*/
}

void MainWindow::on_Selected_clicked( QMouseEvent *mouse_event){

    QPoint mpos = mouse_event->pos();
    QPoint *x;
    QPoint *y;

    for (drawnShape *s : shape->shapeList){
       x = s->shapeEndPoint;
       y = s->shapeStartPoint;
        if((x->x()> mpos.x())&&(x->y()>mpos.y())){
            if((y->x()< mpos.x())&&(y->y()<mpos.y())){
                s->isSelected = true;
            }
        }
    }
}
