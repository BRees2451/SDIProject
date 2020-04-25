#include "Image.h"

/**
 * @brief A function that will look at the first letters of the names of the Images that have been edited.
 * It will sort this list, using the bubble sort at this stage, and then move onto the next letter and repeat the process.
 */
QVector<shareClass::fileData> Image::SortAscendingName(QVector<shareClass::fileData> nameVector) {

    bool swapped = false;
    for (int i = 0; i < nameVector.size() - 1; ++i) {
        for (int j = 0; j < nameVector.size() - 1 - i; ++j) {

            if (nameVector[j].name.toLower() > nameVector[j + 1].name.toLower()) {
                shareClass::fileData temp = nameVector[j];
                nameVector[j] = nameVector[j + 1];
                nameVector[j + 1] = temp;
                swapped = true;
            }
       }
        if (!swapped) {
            break;
        }
        swapped = false;
    }
    return nameVector;

}


QVector<shareClass::fileData> Image::SortDescendingName(QVector<shareClass::fileData> nameVector) {

    bool swapped = false;


    for (int i = 0; i < nameVector.size() - 1; ++i) {
        for (int j = 0; j < nameVector.size() - 1 - i; ++j) {

            if (nameVector[j].name.toLower() < nameVector[j + 1].name.toLower()) {
                shareClass::fileData temp = nameVector[j];
                nameVector[j] = nameVector[j + 1];
                nameVector[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
    }
    return nameVector;
}

QVector<shareClass::fileData> Image::SortAscendingDate(QVector<shareClass::fileData> dateVector) {

    bool swapped = false;


    for (int i = 0; i < dateVector.size() - 1; ++i) {
        for (int j = 0; j < dateVector.size() - 1 - i; ++j) {

            if (dateVector[j].dateModified > dateVector[j + 1].dateModified) {
                shareClass::fileData temp = dateVector[j];
                dateVector[j] = dateVector[j + 1];
                dateVector[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
   }
   return dateVector;

}

QVector<shareClass::fileData> Image::SortDescendingDate(QVector<shareClass::fileData> dateVector) {
    bool swapped = false;


    for (int i = 0; i < dateVector.size() - 1; ++i) {
        for (int j = 0; j < dateVector.size() - 1 - i; ++j) {

            if (dateVector[j].dateModified < dateVector[j + 1].dateModified) {
                shareClass::fileData temp = dateVector[j];
                dateVector[j] = dateVector[j + 1];
                dateVector[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
    }
    return dateVector;

}

int Image::searchImageName(QVector<shareClass::fileData> nameVector, QString searchName)
{
    nameVector = SortAscendingName(nameVector);
    int len = nameVector.size();
    int l = 0; // left
    int r = len - 1; // right
    while (l <= r)
    {

        int m = l + (r - l) / 2; // middle

        QStringList split = nameVector[m].name.split("."); // strip extension

        if (searchName == (split[0].toLower())) {
            return m;
        }

        // If x greater, ignore left half
        if (searchName > (nameVector[m].name.toLower()))
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return -1;

}
