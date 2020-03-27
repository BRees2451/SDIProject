#ifndef IMAGE_H
#define IMAGE_H
#include "Annotations.h"
#include <vector>
//For the date sorting
#include <ctime>
#include "mainwindow.h"


class Image {

    QString imageName;

    friend class MainWindow;
private:
    //int image;  <-- what is this for
    std::vector<Annotations> annotationsVector;
    unsigned int longestImageNameLength;


public:

	void CheckCompatible();

	void SortAscendingName();

	void SortDescendingName();

	void SortAscendingDate();

	void SortDescendingDate();

    void checkImageNameLength(string);
};

#endif
