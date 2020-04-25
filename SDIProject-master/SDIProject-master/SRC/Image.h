#ifndef IMAGE_H
#define IMAGE_H
#include "mainwindow.h"
#include "Annotations.h"
#include "shareclass.h"
#include <vector>
#include <ctime>

/**
 * @brief The Image class
 */
class Image {

    friend class MainWindow;
private:
    std::vector<Annotations> annotationsVector;

public:

    QVector<shareClass::fileData> SortAscendingName(QVector<shareClass::fileData>);

    QVector<shareClass::fileData> SortDescendingName(QVector<shareClass::fileData>);

    QVector<shareClass::fileData> SortAscendingDate(QVector<shareClass::fileData>);

    QVector<shareClass::fileData> SortDescendingDate(QVector<shareClass::fileData>);

    int searchImageName(QVector<shareClass::fileData>,QString);

};

#endif
