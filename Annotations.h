#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

class Annotations {

private:
	string ShapeType;
	int NoOfShapes;
	string ImageName;
	boolean Fill;
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
