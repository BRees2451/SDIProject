#ifndef IMAGE_H
#define IMAGE_H
#include "mainwindow.h"
#include "Annotations.h"
#include <vector>
//For the date sorting
#include <ctime>


class Image{

    //friend class MainWindow;
private:
    //int image;  <-- what is this for
    std::vector<Annotations> annotationsVector;
    unsigned int longestImageNameLength;


public:

	void CheckCompatible();

    vector<QString> SortAscendingName(vector<MainWindow::fileData> nameVector);

    vector<QString> SortDescendingName(vector<MainWindow::fileData> nameVector);

	void SortAscendingDate();

	void SortDescendingDate();

    void checkImageNameLength(string);
};

#endif
