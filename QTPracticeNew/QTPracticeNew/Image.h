#ifndef IMAGE_H
#define IMAGE_H
#include "Annotations.h"
#include <vector>

class Image {

private:
	int Image;
    std::vector<Annotations> annotationsVector;
public:
	void CheckCompatible();

	void SortAscendingName();

	void SortDescendingName();

	void SortAscendingDate();

	void SortDescendingDate();
};

#endif
