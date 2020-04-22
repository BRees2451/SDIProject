#ifndef SIDEPANE_H
#define SIDEPANE_H
#include "Gui.h"
#include "Image.h"


class SidePane : Gui {

private:
	int Size;
    //Flexible storage of images which can be called.
    std::vector<Image> imageList;

public:
    void DisplayObjects();

    void addToVector();

};

#endif
