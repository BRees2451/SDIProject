#ifndef SHARECLASS_H
#define SHARECLASS_H
#include <QtCore>
#include <iostream>
using namespace std;

/**
 * @brief The shareClass class is responsible for giving all
 * classes the information they may need.
 */
class shareClass : public QThread {
public:
    /**
     * @brief This is the constructor for this class.
     */
    shareClass();
#
    /**
     * @brief The fileData struct is a package that will
     * hold the data for the file data.
     */
    struct fileData{
        QString name;
        QDateTime dateModified;
    };
};
#endif // SHARECLASS_H
