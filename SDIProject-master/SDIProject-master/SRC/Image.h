#ifndef IMAGE_H
#define IMAGE_H
#include "mainwindow.h"
#include "shareclass.h"
#include <vector>
#include <ctime>

/**
 * @brief The Image class is responsible for sorting all
 * of the images and classes into their respective sorted
 * lists. It is also responsible for the search function
 * we use in this project.
 */
class Image {

    friend class MainWindow;

public:
    /**
     * @brief SortAscendingName
     * Sorts files by name into ascending order.
     * @return Vector of the files in order.
     */
    QVector<shareClass::fileData> SortAscendingName(QVector<shareClass::fileData>);

    /**
     * @brief SortDescendingName
     * Sorts files by name into descending order.
     * @return Vector of the files in order.
     */
    QVector<shareClass::fileData> SortDescendingName(QVector<shareClass::fileData>);

    /**
     * @brief SortAscendingDate
     * Sorts files by date into ascending order.
     * @return Vector of the files in order.
     */
    QVector<shareClass::fileData> SortAscendingDate(QVector<shareClass::fileData>);

    /**
     * @brief SortDescendingDate
     * Sorts files by date into descending order.
     * @return Vector of the files in order.
     */
    QVector<shareClass::fileData> SortDescendingDate(QVector<shareClass::fileData>);

    /**
     * @brief searchImageName
     * Searches for an image with the specified name.
     * @return if the image has been found.
     */
    int searchImageName(QVector<shareClass::fileData>,QString);

};

#endif
