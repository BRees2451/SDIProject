#ifndef IMAGE_H
#define IMAGE_H
#include "Annotations.h"
#include <vector>

class Image {

private:
	int Image;
    std::vector<Annotations> annotationsVector;
    int longestImageNameLength;
public:
	void CheckCompatible();

	void SortAscendingName();

	void SortDescendingName();

	void SortAscendingDate();

	void SortDescendingDate();

    int convertToAscii(char);

    string convertToString(string, int);
};

#endif
