/*

//#ifndef IMAGE_H
#define IMAGE_H
#include <QtTest>
#include <vector>
//For the date sorting
#include <ctime>



class Image : public QObject
{
    Q_OBJECT

    std::string imageName;

public:
    Image(std::string name)
    {
        this->imageName = name;
    }

    void CheckCompatible();

    void SortAscendingName();

    void SortDescendingName();

    void SortAscendingDate();

    void SortDescendingDate();

    void checkImageNameLength(std::string);

private:
    //int image;  //<-- what is this for (Michael)
    //std::vector<Annotations> annotationsVector;
    unsigned int longestImageNameLength;
};

QTEST_APPLESS_MAIN(Image)

#include "tst_testcase_Image.moc"

*/
