#ifndef BUTTON_H
#define BUTTON_H

class Button {

private:
	int Name;
	int Size;
	int Colour;
	int ButtonCoOrdinates;

public:
	void ButtonPressed();

	void AddButton();

	void RemoveButton();
};

#endif
