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

    QVector<shareClass::fileData> SortAscendingName(QVector<shareClass::fileData> nameVector);

    QVector<shareClass::fileData> SortDescendingName(QVector<shareClass::fileData> nameVector);

	void SortAscendingDate();

	void SortDescendingDate();

    void checkImageNameLength(string);
};

#endif
