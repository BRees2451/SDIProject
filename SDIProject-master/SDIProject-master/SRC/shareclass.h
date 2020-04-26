#ifndef SHARECLASS_H
#define SHARECLASS_H
#include <QtCore>
#include <iostream>
using namespace std;

class shareClass : public QThread {
public:
    shareClass();

    struct fileData{
        QString name;
        QDateTime dateModified;
    };
};
#endif // SHARECLASS_H
