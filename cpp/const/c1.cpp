#include <iostream>
using namespace std;

class test
{
public:
    int z;
    void fun() const
    {
        int a = 10;
        a = 12;
        // z = 12; can not do anything with outer variables
        cout << "Having too much fun" << endl;
    }
};

int fun()
{
    const int a = 10;
    return a;
}

int main(int argc, char const *argv[])
{
    int c = fun();
    test().fun();
    return 0;
}
