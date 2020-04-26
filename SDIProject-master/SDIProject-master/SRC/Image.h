#ifndef IMAGE_H
#define IMAGE_H
#include "mainwindow.h"
#include "Annotations.h"
#include "shareclass.h"
#include <vector>
#include <ctime>

/**
 * @brief The Image class
 */
class Image {

    friend class MainWindow;
private:
    /**
     * @brief annotationsVector
     * A vector of annotations for an image.
     */
    std::vector<Annotations> annotationsVector;

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
