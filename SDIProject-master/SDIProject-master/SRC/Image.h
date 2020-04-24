#ifndef IMAGE_H
#define IMAGE_H
#include "mainwindow.h"
#include "Annotations.h"
#include "shareclass.h"
#include <vector>
//For the date sorting
#include <ctime>

class Image{

    friend class MainWindow;
private:
    //int image;  <-- what is this for
    std::vector<Annotations> annotationsVector;
    unsigned int longestImageNameLength;


public:

	void CheckCompatible();

    QVector<shareClass::fileData> SortAscendingName(QVector<shareClass::fileData>);

    QVector<shareClass::fileData> SortDescendingName(QVector<shareClass::fileData>);

    QVector<shareClass::fileData> SortAscendingDate(QVector<shareClass::fileData>);

    QVector<shareClass::fileData> SortDescendingDate(QVector<shareClass::fileData>);

    int searchImageName(QVector<shareClass::fileData>,QString);

    void checkImageNameLength(string);
};

#endif
