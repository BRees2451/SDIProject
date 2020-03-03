#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <vector>
using namespace std;


class Classes {

    //Set selected class

private:

    int FileLineNo;
    string selectedClassName;

public:
	void SortAscending();

	void SortDescending();

	void SaveAnnotation();

	void AddClass();

	void RemoveClass();

    //void createAnnotationsFile();
};

#endif
