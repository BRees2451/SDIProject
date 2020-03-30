#ifndef SHARECLASS_H
#define SHARECLASS_H
#include <QtCore>

class shareClass
{
public:
    shareClass();

    struct fileData{
        QString name;
        QDateTime dateModified;
    };
};

#endif // SHARECLASS_H
