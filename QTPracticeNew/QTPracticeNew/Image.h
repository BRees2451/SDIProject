#ifndef IMAGE_H
#define IMAGE_H
#include "Annotations.h"
#include <vector>
//For the date sorting
#include <ctime>

class Image {

    string imageName;
private:
    //int image;  <-- what is this for (Michael)
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
