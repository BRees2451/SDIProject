#include <QtTest>

// add necessary includes here

class sort : public QObject
{
    Q_OBJECT

public:
    sort();
    ~sort();

private slots:
    void test_case1();
    void test_case2();

};

sort::sort()
{

}

sort::~sort()
{

}

void sort::test_case1() // Sort Ascending
{
    bool swapped = false;
    std::vector<std::string> names = {"dog","mouse","cat"};
        for (unsigned int i = 0; i < names.size() - 1; ++i) {
            for (unsigned int j = 0; j < names.size() - 1 - i; ++j) {

                if (names[j] > names[j + 1]) {
                    std::string temp = names[j];
                    names[j] = names[j + 1];
                    names[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
        }
        QStringList returnList;
            for(unsigned i=0; i < names.size(); i++) {
                QString item = QString::fromStdString(names[i]);
                returnList.append(item);
            }

    QStringList list2 = {"cat","dog","mouse"};
    QVERIFY(true);
    QCOMPARE(returnList,list2);
}

void sort::test_case2() // Sort Descending
{
    bool swapped = false;
    std::vector<std::string> names = {"dog","mouse","cat"};
        for (unsigned int i = 0; i < names.size() - 1; ++i) {
            for (unsigned int j = 0; j < names.size() - 1 - i; ++j) {

                if (names[j] < names[j + 1]) {
                    std::string temp = names[j];
                    names[j] = names[j + 1];
                    names[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
            swapped = false;
        }
        QStringList returnList;
            for(unsigned i=0; i < names.size(); i++) {
                QString item = QString::fromStdString(names[i]);
                returnList.append(item);
            }

    QStringList list2 = {"mouse","dog","cat"};
    QVERIFY(true);
    QCOMPARE(returnList,list2);
}

QTEST_APPLESS_MAIN(sort)

#include "tst_sortasc.moc"
