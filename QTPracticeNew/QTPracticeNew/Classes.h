#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;

class Classes {

private:
	int FIleLineNo;
    string Classname;

public:
	void SortAscending();

	void SortDescending();

	void SaveAnnotation();

	void AddClass();

	void RemoveClass();

	void DisplayClass();

    //void createAnnotationsFile();
};

#endif
