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
    std::vector<std::string> names = {"lion","tiger","cheetah"};
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
        QStringList sortedList;
            for(unsigned i=0; i < names.size(); i++) {
                QString item = QString::fromStdString(names[i]);
                sortedList.append(item);
            }

    QStringList list2 = {"cheetah","lion","tiger"};
    QVERIFY(true);
    QCOMPARE(sortedList,list2);
}

void sort::test_case2() // Sort Descending
{
    bool swapped = false;
    std::vector<std::string> names = {"lion","tiger","cheetah"};
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
        QStringList sortedList;
            for(unsigned i=0; i < names.size(); i++) {
                QString item = QString::fromStdString(names[i]);
                sortedList.append(item);
            }
    QStringList list2 = {"tiger","lion","cheetah"};
    QVERIFY(true);
    QCOMPARE(sortedList,list2);
}

QTEST_APPLESS_MAIN(sort)

#include "tst_sortasc.moc"
