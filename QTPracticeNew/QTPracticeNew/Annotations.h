#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H
#include <iostream>
using namespace std;

class Annotations {

private:
    string ShapeType;
	int NoOfShapes;
	string ImageName;
	int BorderColour;
	int NoOfImages;

public:
	void Load();

	void Open();

	void Save();

	void ChangeName();

	void Copy();
};

#endif
