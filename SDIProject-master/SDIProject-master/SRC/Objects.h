ifndef Objects_H
#define Objects_H
#include <iostream>
#include <vector>
using namespace std;


class Objects {

    //Set selected class

private:

    int FileLineNo;
    string selectedClassName;

public:
	void SortAscending();

	void SortDescending();

	void SaveAnnotation();

    void AddObject();

    void RemoveObject();

    //void createAnnotationsFile();
};

#endif
