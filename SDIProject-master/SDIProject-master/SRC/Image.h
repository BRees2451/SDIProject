#ifndef IMAGE_H
#define IMAGE_H
#include "mainwindow.h"
#include "Annotations.h"
#include "shareclass.h"
#include <vector>
#include <ctime>

/**
 * @brief The Image class handles all the processes related to sorting the image list.
 * As welll as searching the list.
 */
class Image {

    friend class MainWindow;
private:
    /**
     * @brief annotationsVector is a list of all the
     */
    std::vector<Annotations> annotationsVector;

public:

    /**
     * @brief SortAscendingName is called to sort through the image list, by name, in to ascending order.
     *
     * @return nameVector as the sorted list of names.
     */
    QVector<shareClass::fileData> SortAscendingName(QVector<shareClass::fileData>);

    /**
     * @brief SortDescendingName is called to sort through the image list, by name, in to descending order.
     *
     * @return nameVector as the sorted list of names.
     */
    QVector<shareClass::fileData> SortDescendingName(QVector<shareClass::fileData>);

    /**
     * @brief SortAscendingDate is called to sort through the image list, by date, in to ascending order.
     *
     * @return dateVector as the sorted list of dates.
     */
    QVector<shareClass::fileData> SortAscendingDate(QVector<shareClass::fileData>);

    /**
     * @brief SortDescendingDate is called to sort through the image list, by date, in to descending order.
     *
     * @return dateVector as the sorted list of dates.
     */
    QVector<shareClass::fileData> SortDescendingDate(QVector<shareClass::fileData>);

    /**
     * @brief searchImageName is the method called to search throught the nameVector list for a specific image.
     *
     * @return
     */
    int searchImageName(QVector<shareClass::fileData>,QString);

};

#endif
