#ifndef IMAGE_H
#define IMAGE_H
#include "Annotations.h"
#include <vector>
//For the date sorting
#include <ctime>
#include "mainwindow.h"
#include "string.h"

class Image {

    string imageName;

    friend class MainWindow;
private:
    //int image;  <-- what is this for
    std::vector<Annotations> annotationsVector;
    unsigned int longestImageNameLength;

public:
    Image(string name)
    {
        this->imageName = name;
    }

	void CheckCompatible();

	void SortAscendingName();

	void SortDescendingName();

	void SortAscendingDate();

	void SortDescendingDate();

    void checkImageNameLength(string);
};

#endif
