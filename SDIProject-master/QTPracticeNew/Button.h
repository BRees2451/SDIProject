#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
using namespace std;

class Button {

private:
    string Name;
	int Size;
	int Colour;
    int ButtonCoOrdinates;

public:
	void ButtonPressed();

    void AddButton(int, int, string);

	void RemoveButton();
};

#endif
