#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>

class Button {

private:
	String Name;
	int Size;
	int Colour;
	int ButtonCoOrdinates;

public:
	void ButtonPressed();

	void AddButton();

	void RemoveButton();
};

#endif
