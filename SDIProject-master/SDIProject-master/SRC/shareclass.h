#ifndef SHARECLASS_H
#define SHARECLASS_H
#include <QtCore>
#include <iostream>
using namespace std;

/**
 * @brief The shareClass class
 */

class shareClass : public QThread {
public:

    /**
     * @brief shareClass is a constructor of the class.
     */
    shareClass();

    /**
     * @brief The fileData struct stores the name and the date modified of each file.
     */

    struct fileData{
        QString name;
        QDateTime dateModified;
    };
};
#endif // SHARECLASS_H
