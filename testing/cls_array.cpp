#include <iostream>
#include <stdlib.h>
using namespace std;

struct test
{
    int a;
    test()
    {
        cout << "constructor ran" << endl;
    }
    ~test()
    {
        cout << "destructor ran " << endl;
    }
};

struct test_test
{
    int a;
    test_test(int temp)
    {
        cout << "constructor is called : " << endl;
    }

    // Overloaded [] operator to access the elements of the vector
    test_test operator[](int index)
    {
        cout << "operator is called : " << endl;
    }
};

struct test4
{
    int a, b, c;
    // test4(int tempa, int tempb, int tempc) : a(tempa), b(tempb)
    // {
    //     cout << "constructor is called : " << endl;
    // }
};

void test1()
{
    cout << "Process started\n\n";
    // test obj = test();
    test *obj = new test[10];
    delete[] obj;
    cout << " \n\nTEST 2 STARTS\n\n";
    test obj2[5];
    int c = 10;
}

int main(int argc, char const *argv[])
{
    // system("cls");
    cout << "PROCESS started : " << endl;
    test4 obj{1, 2, 3};
    cout << obj.a << endl
         << obj.b << endl
         << obj.c << endl;

    cout
        << "\n\nprocess ended \n\n";

    return 0;
}
