#include "Image.h"

/**
 * @brief Image::SortAscendingName will sort the list passed in into
 * a sorted verson. It will do this via a bubble sort by checking the
 * value next to it and seeing whether it needs to swap. Once it does
 * this then it will return the sorted vector in the same format.
 *
 * @param nameVector is the vector of names that needs to be sorted.
 * @return nameVector as the sorted list of names.
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

/**
 * @brief Image::SortDescendingName will sort the elements of the input
 * vector to descending order. It does this by using a bubble sort. It
 * will loop through and check whether the adjacent elements need swapping.
 * If they do then it will swap until there are no swaps in a full
 * iteration.
 *
 * @param nameVector is the vector that will need to be sorted.
 * @return nameVector which is the same list however now sorted.
 */
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

/**
 * @brief Image::SortAscendingDate will take a vector and reorder it
 * such that it's in ascending order. It will do this by
 *
 * @param dateVector is the vector that will need to be sorted.
 * @return dateVector which is the same list however now sorted.
 */
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

/**
 * @brief Image::SortDescendingDate
 *
 * @param dateVector is the vector that will need to be sorted.
 * @return dateVector which is the same list however now sorted.
 */
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

/**
 * @brief Image::searchImageName
 * @param nameVector
 * @param searchName
 * @return
 */
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
