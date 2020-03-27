#ifndef UERSHAPEOPPERATIONS_H
#define UERSHAPEOPPERATIONS_H

class UserShapeOperation {
private:
    int height;
    int width;

public:
    void USize();

	void Move();

	void Delete();

	void DisplayName();

    UserShapeOperation()
    {
        this->height= 500;
        this->width= 500;
    }

    ~UserShapeOperation()
    {
        //For Deleting?
    }
};

#endif
