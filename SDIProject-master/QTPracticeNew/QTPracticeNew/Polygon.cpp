#include "Polygon.h"

int vertices;

//Mininum number of points???

void Polygon::CheckMax8() {
	// TODO - implement Polygon::CheckMax8
	while(vertices > 8 or vertices < 3){
		cout<<"Invalid number of vertices, please enter in the range of 3-8"<<endl;
		cout<<"Enter: ";
        cin>>vertices>>endl;
	}
	//throw "Not yet implemented";
}
