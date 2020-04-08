#ifndef UERSHAPEOPPERATIONS_H
#define UERSHAPEOPPERATIONS_H
#include <QtCore>

class UserShapeOperation {
private:
    int height;
    int width;
    QString shapeType;

public:
    void USize();

	void Move();

	void Delete();

	void DisplayName();

    UserShapeOperation(QString sType)
    {
        this->shapeType = sType;
        this->height= 500;
        this->width= 500;
    }

    ~UserShapeOperation()
    {
        //For Deleting?
    }
};

#endif
