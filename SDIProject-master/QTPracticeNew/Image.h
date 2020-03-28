#ifndef IMAGE_H
#define IMAGE_H
#include "Annotations.h"
#include <vector>
//For the date sorting
#include <ctime>
#include "mainwindow.h"


class Image {

    QString imageName;

    //friend class MainWindow;
private:

    std::vector<Annotations> annotationsVector;
    unsigned int longestImageNameLength;


public:
    Image();

	void CheckCompatible();

    vector<QString> SortAscendingName(vector<QString>);

    vector<QString> SortDescendingName(vector<QString>);

	void SortAscendingDate();

	void SortDescendingDate();

    void checkImageNameLength(string);
};

#endif
