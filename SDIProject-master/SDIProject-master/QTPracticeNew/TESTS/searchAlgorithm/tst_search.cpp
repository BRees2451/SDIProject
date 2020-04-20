#include <QtTest>
#include <iostream>

//using namespace std;

// add necessary includes here

class search : public QObject
{
    Q_OBJECT

public:
    search();
    ~search();

private slots:
    void test_case1();

};

search::search()
{

}

search::~search()
{

}

void search::test_case1() // binary search
{
    std::vector<std::string> searchList = { "apple", "blackberry", "orange", "raisin" };
        std::string x = "blackberry";
        int len = searchList.size();
        //std::cout<<len;
        int l = 0;
        int r = len - 1;
        int m;
        while (l <= r)
        {
            m = l + (r - l) / 2;

            int res;
            if (x == (searchList[m])) {
                res = 0;


                // Check if x is present at mid
                //if (res == 0)
                //return m;
                break;
            }

            // If x greater, ignore left half
            if (x > (searchList[m])){
                l = m + 1;}

            // If x is smaller, ignore right half
            else{
                r = m - 1;}
        }

        //return -1;
        //break;


    int testIndex = 1;
    QVERIFY(true);
    QCOMPARE(m,testIndex);
}

QTEST_APPLESS_MAIN(search)

#include "tst_search.moc"
