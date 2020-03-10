#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H
#include <iostream>
using namespace std;

class Annotations {

    //Annotations contain classes and shapes (as well as shape properties)

private:
    string ShapeType;
	int NoOfShapes;
	string ImageName;
	int BorderColour;
	int NoOfImages;
    float[] ShapeSize;

public:
	void Load();

	void Open();

	void Save();

	void ChangeName();

	void Copy();
};

#endif
