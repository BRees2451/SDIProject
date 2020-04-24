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
    connect(ui->graphicsView,SIGNAL(sendMousePress(QPoint&)), SLOT(clickPoint(QPoint&)));
    connect(ui->graphicsView, SIGNAL(sendMouseRelease(QPoint&)), this, SLOT(mouseReleased(QPoint&)));

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
    this->fileName = info.fileName();
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
    //JSON
    int listSize = shape->shapeList.size();
    QJsonObject Root;
    Root["Number of Annotations"] = listSize;
    /*
    QJsonArray images;
    for(int i = 0; i < filesInDirectory.size(); i++){
        QJsonObject individualImage;
        individualImage["ImageName"] = filesInDirectory[i].name;
        individualImage["Shapes"] =
    }*/
    QJsonObject individualImage;
    for (int i = 0; i < filesInDirectory.size(); i++){
        QJsonArray shapesInImage;

        if (classFileName.split(".")[0] == filesInDirectory[i].name.split(".")[0]){
            for (int j = 0; j < shape->shapeList.size(); j++){
                QJsonObject point;
                QJsonArray pointsArray;
                for (int k = 0; k < shape->shapeList[j]->pointsVector.size(); k++){

                    point["x"] = shape->shapeList[j]->shape[k].x();
                    point["y"] = shape->shapeList[j]->shape[k].y();
                    pointsArray.append(point);
                }
                QJsonObject shapeData;
                shapeData["Shape Type"] = shape->shapeList[j]->shapeType;
                shapeData["Class Type"] = shape->shapeList[j]->classType;
                shapeData["Points"] = pointsArray;

                shapesInImage.append(shapeData);

            }

            individualImage["ImageName"] = filesInDirectory[i].name;
            individualImage["Shapes"] = shapesInImage;


        }


    }
    Root["Image"] = individualImage;
    QJsonDocument annotation;
    annotation.setObject(Root);

    QFile file(annoFilePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(annotation.toJson());



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
    QPainterPath painterPath;
    QFont font;
    if (shapeType == "Polygon") return;
    bool a = QApplication::mouseButtons();
    if (a) {
        if (shapeType == "Select"){
            drawnShape *currentShape;
            for (drawnShape *s : shape->shapeList){
                if (s->isSelected) {
                    currentShape = s;
                    break;
                }

            }
            //prevPoint = pos-(*currentShape->shapeStartPoint);
            //QPoint point = pos-(*currentShape->shapeStartPoint);
            qDebug() << pos-previousPos << endl;
            if (previousPos.x() != NULL) currentShape->shape.translate(pos-previousPos);
            previousPos = pos;
        }
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

            if (s->isSelected) font.setBold(1);
            else font.setBold(0);


            if (s->drawn == false) {
                painterPath.addPolygon(s->shape);
                s->getCenter();
                painterPath.addText(s->center->x(), s->center->y(), font, s->classType);

                QGraphicsPathItem *shapeDrawing = scene->addPath(painterPath);

                //if (this->isSelected) scene->removeItem(shapeDrawing);
                s->drawn = true;
            }


        }
    }

    ui->mouse_position_label->setText("x: "+ QString::number(pos.x()) + " y: "+ QString::number(pos.y()));

}

void MainWindow::clickPoint(QPoint& pos){
    QGraphicsItem *polygon;
    drawnShape *currentShape = new drawnShape("","");
    if (shapeType == "Polygon"){
        for (drawnShape *s : shape->shapeList){
            if (s->isBeingDrawn && s->shapeType == "Polygon") {
                currentShape = s;
                polygonShape *currentPoly = static_cast<polygonShape*>(currentShape);
                if (currentPoly->pointsVector->size() != 8) {
                    //currentPoly->isBeingDrawn = false;
                    currentPoly->addPoint(pos);
                }
                else currentPoly->isBeingDrawn = false;
                if (s->drawn == false) {
                    QPen blackPen(Qt::black);
                    if (s->isSelected) blackPen.setWidth(8);
                    else blackPen.setWidth(6);
                    QPainterPath painterPath;
                    painterPath.addPolygon(s->shape);
                    QPainter painter(this);
                    painter.setPen(Qt::black);
                    painter.drawText(0, 20, "Polygon");
                    polygon = scene->addPath(painterPath);
                    //scene->addPolygon(s->shape,blackPen);
                    s->drawn = true;
                }
            }
        }
        polygonShape *newPolygon = new polygonShape(this->shapeType, this->selectedClass);
        shape->shapeList.push_back(newPolygon);
    }
    if (shapeType == "Select") {
        bool found = false;
        for (drawnShape *s : shape->shapeList){
            this->isSelected = false;
            if (!found) found = s->tryToggleSelect(pos);

        }
    }
    //latest = pos;
    //QPoint mouse_pos = mouse_event->pos();
    //qDebug() << "mouse_pos" <<endl;
    double rad = 1;
    circle = scene->addEllipse(pos.x()-rad,pos.y()-rad,rad*2.0,rad*2.0);
}


void MainWindow::on_selectImage_clicked() //Displays the image selected on the pane
{
    shape->shapeList.clear();
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

    QString containString = "/RESULTS/"+fileName;

    QString Destination;

    //Will check whether file is in 'RESULTS' folder
    if (filePath.contains(containString))
    {
        cout << "File is in directory" << endl;
        Destination = QFileInfo(QDir::currentPath()).path();
        qDebug() << Destination << endl;
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
    absoluteFileName[1] = "annotations";
    absoluteFileName[absoluteFileName.size()-1] = ".json";
    annoFileName = absoluteFileName.join(".");

    classFilePath = Destination + "/RESULTS/" + classFileName;
    annoFilePath = Destination + "/RESULTS/" + annoFileName;
    if (Destination != NULL && classFileName != NULL && annoFileName != NULL)
    {
        QFile classFile(classFilePath);
        QFile annoFile(annoFilePath);

        if (QFileInfo::exists(annoFilePath)){
            //READ JSON

            annoFile.open(QFile::ReadOnly | QIODevice::Text);
            QString readFile = annoFile.readAll();
            annoFile.close();

            QJsonDocument jDoc = QJsonDocument::fromJson(readFile.toUtf8());


            QJsonObject root = jDoc.object();
            //QJsonValue child = root.value(QString("Image"));
            QJsonObject individualImage = root["Image"].toObject();



            QJsonArray shapesInImage = individualImage["Shapes"].toArray();

            //For every shape
            for (int i = 0; i < shapesInImage.size(); i++){
                QJsonObject shapeData = shapesInImage[i].toObject();
                QString shapeType = shapeData["Shape Type"].toString();

                QString classType = shapeData["Class Type"].toString();

                drawnShape *newShape = new drawnShape(shapeType, classType);
                shape->shapeList.push_back(newShape);

                QJsonArray pointsArray = shapeData["Points"].toArray();

                //For every point
                for (int j = 0; j < pointsArray.size(); j++){
                    QJsonObject Point = pointsArray[j].toObject();
                    float x = Point["x"].toDouble();
                    float y = Point["y"].toDouble();
                    QPointF *newPoint = new QPointF(x,y);

                    newShape->pointsVector.push_back(*newPoint);
                    newShape->shape.append(*newPoint);

                }
                newShape->shape.push_back(newShape->shape[0]);

                newShape->isSelected = false;
                newShape->isBeingDrawn = false;
                newShape->drawn = false;
                if (newShape->shapeType == "Rectangle"){
                    QPoint shapeStart = newShape->pointsVector[0].toPoint();
                    newShape->shapeStartPoint = &shapeStart;
                    QPoint shapeEnd = newShape->pointsVector[2].toPoint();
                    newShape->shapeEndPoint = &shapeEnd;
                }
                else if (newShape->shapeType == "Triangle"){
                    QPoint *shapeStart = new QPoint(newShape->pointsVector[0].x(), newShape->pointsVector[2].y());
                    newShape->shapeStartPoint = shapeStart;
                    QPoint shapeEnd = newShape->pointsVector[1].toPoint();
                    newShape->shapeEndPoint = &shapeEnd;
                }
                else if (newShape->shapeType == "Trapezium"){
                    QPoint *shapeStart = new QPoint(newShape->pointsVector[3].x(), newShape->pointsVector[0].y());
                    newShape->shapeStartPoint = shapeStart;
                    QPoint shapeEnd = newShape->pointsVector[2].toPoint();
                    newShape->shapeEndPoint = &shapeEnd;
                }
                newShape->center = new QPointF(newShape->shapeStartPoint->x() + (newShape->shapeEndPoint->x() - newShape->shapeStartPoint->x())/2 - (newShape->classType.length()*3), newShape->shapeStartPoint->y() + (newShape->shapeEndPoint->y() - newShape->shapeStartPoint->y())/2);
                QPoint *basePoint = new QPoint(0,0);
                this->showMousePosition(*basePoint);

                newShape->shape.isClosed();



            }

            int numberOfAnno = root["Number of Annotations"].toInt();
            qDebug() << numberOfAnno << endl;
        }
        else{
            annoFile.open(QIODevice::WriteOnly | QIODevice::Text);
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
    if (imageActive) {
        if (ui->newClassLineEdit->isEnabled()){
            ui->newClassLineEdit->setEnabled(0);
            ui->selectClassButton->setEnabled(1);
            return;
        }
        ui->newClassLineEdit->setEnabled(1);
        ui->selectClassButton->setEnabled(0);
    }
}

/**
 * @brief MainWindow::on_newClassLineEdit_returnPressed This will disable and clear the textbox as well as increment
 * the class vectors and file as well as push this new information to the GUI.
 */
void MainWindow::on_newClassLineEdit_returnPressed()
{
    QString text = ui->newClassLineEdit->text();
    ui->newClassLineEdit->setText("");
    ui->selectClassButton->setEnabled(1);
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
        ui->ImagesWindow->item(searchIndex)->setForeground(Qt::green);
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
    if (shapeType == "Select"){
        shape->Delete(scene);
    }
}

void MainWindow:: on_resizeShape_clicked()
{
    //shape->usize;
}

void MainWindow::on_selectButton_clicked()
{
    this->shapeType = "Select";
    this->ui->shapeTypeLabel->setText("Shape Type: Select");
}

void MainWindow::mouseReleased(QPoint &)
{
    qDebug() << "mouseReleased" << endl;
}

void MainWindow::on_RemoveClassButton_clicked()
{
    QString selectedName;
    QList<QListWidgetItem*> items = ui->ClassWindow->selectedItems();
    foreach(QListWidgetItem * item, items){
        QListWidgetItem *selected = ui->ClassWindow->takeItem(ui->ClassWindow->row(item));
        selectedName = selected->text();
        delete selected;

    }
    QFile classFile(classFilePath);
    cout << "file does not exist" << endl;
    classFile.open(QIODevice::WriteOnly | QIODevice::Text);
    classFile.write("Classes\n");
    int index;
    for (int i = 0; i < classesInFile.size(); i++){
        if (classesInFile[i].name == selectedName) index = i;
        else {
            classFile.write(classesInFile[i].name.toUtf8().constData());
            classFile.write("\n");
        }
    }
    classesInFile.remove(index);
    classFile.close();

}

void MainWindow::on_replaceImageFileName_clicked()
{
    Image image;

    //get the contents of line edit
    QString searchName = ui->oldImagelineEdit->text();
    QString replaceName = ui->newImagelineEdit->text();

    // Call search algorithm inside image class
    int searchIndex = image.searchImageName(filesInDirectory,searchName);
    // returns the index of the location in the image vector

    if(searchIndex == -1){
        ui->newImagelineEdit->setText("Image not found");
    }
    else{
        //ui->ImagesWindow->item(searchIndex)->setText(replaceName);
        cout<<"????????";
        QDir directory(defaultPath);
        QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG",QDir::Files);
        for(int i = 0; i < images.length(); i++) {
            QFileInfo modified = QFileInfo(directory, images[i]);
            shareClass::fileData fData;
            fData.name = images[i];
            cout<<" before if";
            if (fData.name == searchName){
                cout<<" in to if";
                images[i] = replaceName;
            }
        ui->ImagesWindow->item(searchIndex)->setText(images[searchIndex] + "\t\t" + fData.dateModified.toString("hh:mm\tdd/MM/yy"));
    }
    }
}
