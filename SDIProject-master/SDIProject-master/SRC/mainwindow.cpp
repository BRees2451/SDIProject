#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matdisplay.h"
#include <QPixmap>

/**
 * @brief MainWindow::MainWindow
 * Constructor of the main window
 *
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    Image currentImage;

    connect(ui->graphicsView,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
    connect(ui->graphicsView,SIGNAL(sendMousePress(QPoint&)), SLOT(clickPoint(QPoint&)));

    connect(mTimer, SIGNAL(sendTimeout()), this, SLOT(saveSignal()));

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

        filesInDirectory.push_back(fData);
        ui->ImagesWindow->addItem(images[i] + "\t\t" + fData.dateModified.toString("hh:mm\tdd/MM/yy"));
    }

    //saveThread.start();

}
/**
 * @brief MainWindow::~MainWindow
 * Deconstructor of the main window
 */
MainWindow::~MainWindow() {
    delete ui;
}

/**
 * @brief MainWindow::on_ZoomInButton_clicked
 * When the button is clicked, the image is zoomed in on by 20%.
 */
void MainWindow::on_ZoomInButton_clicked() {
    ui->graphicsView->scale(1.2,1.2);
}

/**
 * @brief MainWindow::on_ZoomInButton_clicked
 * When the button is clicked, the image is zoomed out to 80%
 * of the original image.
 */
void MainWindow::on_ZoomOutButton_clicked() {
    ui->graphicsView->scale(0.8,0.8);
}

/**
 * @brief MainWindow::on_actionOpen_triggered
 * When a file is opened a directory is created which the image is
 * copied into (as long as it is a .jpg or .png) An empty class file
 * is also created for the image. When the directory is saved it is
 * compiled into a hdf5 file.
 */
void MainWindow::on_actionOpen_triggered() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open A File",defaultPath);
    QFileInfo info(filePath);
    this->fileName = info.fileName();

    open(filePath, fileName);

}

/**
 * @brief MainWindow::on_AddImageButton_clicked
 * When the 'Add Image' button is pressed it selects
 * an image in the same way the 'Open' function does.
 */
void MainWindow::on_AddImageButton_clicked() {
    on_actionOpen_triggered();
}

/**
 * @brief MainWindow::on_actionQuit_triggered
 * Closes the program
 */
void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

/**
 * @brief MainWindow::on_actionSave_triggered
 * Prompts the user with a message box asking them if they are
 * sure they would like to overrwrite the previous file.
 * If 'Yes' is selected the save function is launched.
 */
void MainWindow::on_actionSave_triggered() {

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "SAVE", "Any changes will override the previous file.\nContinue?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::No) return;
    Save(0);

}

/**
 * @brief MainWindow::on_DrawRectButton_clicked
 * Sets the shape to be drawn as a rectangle.
 * Sets the shape type label to rectangle.
 */
void MainWindow::on_DrawRectButton_clicked() {
    this->shapeType = "Rectangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Rectangle");

}

/**
 * @brief MainWindow::on_DrawTriangleButton_clicked
 * Sets the shape to be drawn as a triangle.
 * Sets the shape type label to triangle.
 */
void MainWindow::on_DrawTriangleButton_clicked() {
    this->shapeType = "Triangle";
    this->ui->shapeTypeLabel->setText("Shape Type: Triangle");
}

/**
 * @brief MainWindow::on_DrawTrapButton_clicked
 * Sets the shape to be drawn as a trapezium.
 * Sets the shape type label to trapezium.
 */
void MainWindow::on_DrawTrapButton_clicked() {
    this->shapeType = "Trapezium";
    this->ui->shapeTypeLabel->setText("Shape Type: Trapezium");
}

/**
 * @brief MainWindow::on_DrawPolyButton_clicked
 * Sets the shape to be drawn as a polygon.
 * Sets the shape type label to polygon.
 */
void MainWindow::on_DrawPolyButton_clicked() {
    this->shapeType = "Polygon";
    this->ui->shapeTypeLabel->setText("Shape Type: Polygon");
}

/**
 * @brief MainWindow::on_RotateLButton_clicked
 * When the button is clicked the image is
 * rotated slightly to the left.
 */
void MainWindow::on_RotateLButton_clicked() {
    ui-> graphicsView ->rotate(-1);
}

/**
 * @brief MainWindow::on_RotateRButton_clicked
 * When the button is clicked the image is
 * rotated slightly to the right.
 */
void MainWindow::on_RotateRButton_clicked() {
    ui-> graphicsView ->rotate(1);
}

/**
 * @brief MainWindow::Save
 * TO-DO
 * @param autosave represents whether the image is being autosaved or not.
 */
void MainWindow::Save(bool autosave) {
    if (!imageActive) return;

    //Need to retrieve the classes file
    int listSize = shape->shapeList.size();
    QJsonObject Root;
    Root["Number of Annotations"] = listSize;

    QJsonObject individualImage;
    for (int i = 0; i < filesInDirectory.size(); i++) {
        QJsonArray shapesInImage;

        if (classFileName.split(".")[0] == filesInDirectory[i].name.split(".")[0]) {
            for (int j = 0; j < shape->shapeList.size(); j++){
                QJsonObject point;
                QJsonArray pointsArray;
                for (int k = 0; k < shape->shapeList[j]->pointsVector.size(); k++) {

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

    if (autosave) {
        if (!QDir(defaultPath+"/autosave").exists()) QDir().mkdir(defaultPath+"/autosave");
        QString autosaveName = defaultPath+"/autosave/autosave" + QString::number(autosaveCounter) + ".json";
        QFile file(autosaveName);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.write(annotation.toJson());
        if (autosaveCounter == 20) autosaveCounter = 0;
        autosaveCounter++;
        file.close();
    }
    else {
        QFile file(annoFilePath);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.write(annotation.toJson());
        file.close();
    }




}

/**
 * @brief MainWindow::closeEvent
 * Deals with closing the window
 * @param event represents the current event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "Window Closed" << endl;
}

/**
 * @brief MainWindow::showMousePosition
 * Gets the current mouse position and displays it.
 * @param pos represents the current position of the mouse.
 */
void MainWindow::showMousePosition(QPoint &pos)
{
    QPointF latest;
    QPainterPath painterPath;
    QFont font;
    if (shapeType == "Polygon") return;
    bool a = QApplication::mouseButtons();
    if (a) {
        if (shapeType == "Select") {
            drawnShape *currentShape;
            for (drawnShape *s : shape->shapeList) {
                if (s->isSelected) {
                    currentShape = s;
                    break;
                }

            }
            if (previousPos.x() != NULL) currentShape->shape.translate(pos-previousPos);
            previousPos = pos;
        }
        else {
            for (drawnShape *s : shape->shapeList) {
                if (s->isBeingDrawn){
                    s->shapeEndPoint = &pos;
                    s->drawMe();
                    break;
                }
            }
        }
        if(shapeType != NULL && (selectedClass != NULL||selectedClass != "")) {
            QPoint *position = new QPoint(pos.x(), pos.y());
            shape->handleMouseEvent(shapeType, selectedClass, position);
        }

        latest = pos;
    }
    if (a == false) {
        for (drawnShape *s : shape->shapeList) {
            if (s->shapeType == "Polygon") {
                if (s->shape.size() != 8) {
                }
                else s->isBeingDrawn = false;
                shape->drawShape();
            }
            else s->isBeingDrawn = false;

            if (s->isSelected) font.setBold(1);
            else font.setBold(0);


            if (s->drawn == false) {
                painterPath.addPolygon(s->shape);
                s->getCenter();
                painterPath.addText(s->center->x(), s->center->y(), font, s->classType);

                shapeDrawing = scene->addPath(painterPath);

                s->drawn = true;
            }
        }
    }

    ui->mouse_position_label->setText("x: "+ QString::number(pos.x()) + " y: "+ QString::number(pos.y()));

}

/**
 * @brief MainWindow::clickPoint
 * Identifies the position as where the mouse is clicked in order to
 * draw a polygon. Adds the corresponding point to the polygon drawing.
 * @param pos represents the current mouse position
 */
void MainWindow::clickPoint(QPoint& pos) {
    QGraphicsItem *polygon;
    drawnShape *currentShape = new drawnShape("","");
    if (shapeType == "Polygon") {
        for (drawnShape *s : shape->shapeList) {
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
        for (drawnShape *s : shape->shapeList) {
            this->isSelected = false;
            if (!found) found = s->tryToggleSelect(pos);
        }
    }
}

/**
 * @brief MainWindow::on_selectImage_clicked
 * Places the image onto the canvas once the image is selected.
 */
void MainWindow::on_selectImage_clicked() {
    shape->shapeList.clear();
    for (int i = 0; i < filesInDirectory.size()-1; i++) {
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

/**
 * @brief MainWindow::openImage
 * Opens the chosen image to put onto the canvas.
 * @param imagePath represents the path of where the chosen image is located
 */
void MainWindow::openImage(QString imagePath) {
    scene->clear();
    if (QString::compare(imagePath,QString())!= 0) {
        QImage image(imagePath);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        ui->graphicsView->setScene(scene);
        scene->addItem(item);
    }
}

/**
 * @brief MainWindow::open
 * Checks if the selected image exists and checks it is the correct type.
 * Checks if there is a .txt file for the image and creates one if not.
 * Pulls the image if it exists.
 * @param filePath represents the path of the file.
 * @param fileName represents the name of the file.
 */
void MainWindow::open(QString filePath, QString fileName) {
    scene->clear();
    //Put this back because if someone is looking to open an image then they are planning on editting it
    //We can discuss about this later.
    if (QString::compare(filePath,QString())!= 0){
           QImage image(filePath);
           item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
           ui->graphicsView->setScene(scene);
           scene->addItem(item);
       }

    QString containString = "/RESULTS/"+fileName;

    QString Destination;

    Destination = QFileInfo(QDir::currentPath()).path();

    imageFilePath = defaultPath + "/" + fileName;

    //Will check whether file is in 'RESULTS' folder
    if (!filePath.contains(containString)) {
        //Copy the file to the destination and check
        QFile(filePath).copy(imageFilePath);
    }

    qDebug() << Destination << endl;

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
    if (Destination != NULL && classFileName != NULL && annoFileName != NULL) {
        QFile classFile(classFilePath);
        QFile annoFile(annoFilePath);

        if (QFileInfo::exists(annoFilePath)) {
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
            for (int i = 0; i < shapesInImage.size(); i++) {
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
                if (newShape->shapeType == "Rectangle") {
                    QPoint shapeStart = newShape->pointsVector[0].toPoint();
                    newShape->shapeStartPoint = &shapeStart;
                    QPoint shapeEnd = newShape->pointsVector[2].toPoint();
                    newShape->shapeEndPoint = &shapeEnd;
                }
                else if (newShape->shapeType == "Triangle") {
                    QPoint *shapeStart = new QPoint(newShape->pointsVector[0].x(), newShape->pointsVector[2].y());
                    newShape->shapeStartPoint = shapeStart;
                    QPoint shapeEnd = newShape->pointsVector[1].toPoint();
                    newShape->shapeEndPoint = &shapeEnd;
                }
                else if (newShape->shapeType == "Trapezium") {
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

        }
        else {
            annoFile.open(QIODevice::WriteOnly | QIODevice::Text);
            annoFile.close();
        }

        //If file exists it will read the data into a list
        if(QFileInfo::exists(classFilePath)) {
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
            for(int i = 1; i < dataFromFile.length();i++) {
                classesInFile.push_back({dataFromFile[i], QDateTime::currentDateTime()});
                ui->ClassWindow->addItem(dataFromFile[i]);
            }

            cout<<"file already created"<<endl;
            classFile.close();
        }
        else {
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
 * @brief MainWindow::on_addClassButton_clicked
 * Enables the textbox.
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
 * @brief MainWindow::on_newClassLineEdit_returnPressed
 * Disables and clears the textbox aswell as incrementing the
 * class vectors and file. Pushes this to the GUI.
 */
void MainWindow::on_newClassLineEdit_returnPressed() {
    QString text = ui->newClassLineEdit->text();
    ui->newClassLineEdit->setText("");
    ui->selectClassButton->setEnabled(1);
    ui->newClassLineEdit->setEnabled(0);

    classesInFile.push_back({text, QDateTime::currentDateTime()});
    ui->ClassWindow->addItem(text);

    QFile file(classFilePath);
    if(QFileInfo::exists(classFilePath)) {
        cout << "file exists" << endl;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.write("Classes");
        for (int i = 0; i < classesInFile.size(); i++) {
            file.write(("\n"+classesInFile[i].name).toUtf8().constData());
        }

        file.close();
    }

}

/**
 * @brief MainWindow::on_sortClassBy_currentIndexChanged
 * Reacts to when the index is changed by directing
 * the information to the correct methods as well as
 * push the sorted list to the GUI.
 * @param arg1
 */
void MainWindow::on_sortClassBy_currentIndexChanged(const QString &arg1) {
    Image image;
    if (arg1 == "Name (Asc)") classesInFile = image.SortAscendingName(classesInFile);
    else if (arg1 == "Name (Desc)") classesInFile = image.SortDescendingName(classesInFile);
    ui->ClassWindow->clear();
    for (int i = 0; i < classesInFile.size(); i++) {
        ui->ClassWindow->addItem(classesInFile[i].name);
        ui->ClassWindow->item(i)->setTextColor(Qt::black);
    }
}

/**
 * @brief MainWindow::on_sortImageBy_currentIndexChanged
 * Reacts to when the index is changed by directing the information
 * to the correct methods as well as push the sorted list to the GUI.
 * @param arg1
 */
void MainWindow::on_sortImageBy_currentIndexChanged(const QString &arg1) {
    Image image;

    if (arg1 == "Name (Asc)") filesInDirectory = image.SortAscendingName(filesInDirectory);
    else if (arg1 == "Name (Desc)") filesInDirectory = image.SortDescendingName(filesInDirectory);
    else if (arg1 == "Date (Asc)") filesInDirectory = image.SortAscendingDate(filesInDirectory);
    else if (arg1 == "Date (Desc)") filesInDirectory = image.SortDescendingDate(filesInDirectory);
    ui->ImagesWindow->clear();
    for (int i = 0; i < filesInDirectory.size(); i++) {
        QString concatenatedItem = filesInDirectory[i].name + "\t\t" + filesInDirectory[i].dateModified.toString("hh:mm\tdd/MM/yy");
        ui->ImagesWindow->addItem(concatenatedItem);
        ui->ImagesWindow->item(i)->setTextColor(Qt::black);
    }
}



/**
 * @brief MainWindow::on_ImageSearchButton_clicked
 * Searches the images imported into the pane for a certain
 * specified image.
 */
void MainWindow::on_ImageSearchButton_clicked() {
    Image image;

    //get the contents of line edit
    QString searchName = ui->ImageSearchLine->text();

    // Call search algorithm inside image class
    int searchIndex = image.searchImageName(filesInDirectory,searchName);
    // returns the index of the location in the image vector

    if(searchIndex == -1) {
        ui->ImageSearchLine->setText("Image not found");
    }
    else{
        ui->ImagesWindow->item(searchIndex)->setForeground(Qt::green);
        ui->ImageSearchLine->setText("Image found");
        
        // set the colour of the image searched to green ???
        
        // using searchIndex
    }
}
/**
 * @brief MainWindow::on_selectClassButton_clicked
 * Chooses the selected class from the list.
 */
void MainWindow::on_selectClassButton_clicked() {
    QListWidgetItem *selected = ui->ClassWindow->currentItem();
    if (selected != NULL) {
        selected->setTextColor(Qt::red);
    }
    selectedClass = selected->text();
}

/**
 * @brief MainWindow::on_deleteShape_clicked
 * Deletes a shape.
 */
void MainWindow::on_deleteShape_clicked() {
    if (shapeType == "Select") {
        shape->Delete(scene);
    }
}

/**
 * @brief MainWindow::on_selectButton_clicked
 * Selects a shape.
 */
void MainWindow::on_selectButton_clicked() {
    this->shapeType = "Select";
    this->ui->shapeTypeLabel->setText("Shape Type: Select");
}

/**
 * @brief MainWindow::on_RemoveClassButton_clicked
 * Removes a class.
 */
void MainWindow::on_RemoveClassButton_clicked() {
    QString selectedName;
    QList<QListWidgetItem*> items = ui->ClassWindow->selectedItems();
    foreach(QListWidgetItem * item, items) {
        QListWidgetItem *selected = ui->ClassWindow->takeItem(ui->ClassWindow->row(item));
        selectedName = selected->text();
        delete selected;

    }
    QFile classFile(classFilePath);
    cout << "file does not exist" << endl;
    classFile.open(QIODevice::WriteOnly | QIODevice::Text);
    classFile.write("Classes\n");
    int index;
    for (int i = 0; i < classesInFile.size(); i++) {
        if (classesInFile[i].name == selectedName) index = i;
        else {
            classFile.write(classesInFile[i].name.toUtf8().constData());
            classFile.write("\n");
        }
    }
    classesInFile.remove(index);
    classFile.close();

}

/**
 * @brief MainWindow::saveSignal
 * Picks up the signal for the image to be saved.
 */
void MainWindow::saveSignal() {

    qDebug() << "SIGNAL RECEIVED" << endl;
    std::thread runThread(&MainWindow::Save, this, 1);
    runThread.join();
}
