#include <iostream>
#include <stdlib.h>
using namespace std;

struct test
{
    test()
    {
        cout << "constructor is called " << endl;
    }

    ~test()
    {
        cout << "Destructor is called : " << endl;
    }

    test(const test &obj)
    {
        cout << "copy constructor is called : " << endl;
    }
};

test fun()
{
    test obj;
    cout << "address in fun is : " << &obj << endl;
    return obj;
}

/* int &fun2()
{
    int a;
    cout << "address of a is : " << &a << endl;
    return a;
} */

/* int *fun3()
{
    int a;
    return &a;
} */

struct vector
{
    int a, b, c;
    vector()
    {
        cout << "hellow world" << endl;
    }
};

int main(int argc, char const *argv[])
{
    // system("cls");
    cout << "Process started \n\n";
    test obj2 = fun();
    cout << "address in main is : " << &obj2 << endl;

    pair<int, int> p{1, 2};
    cout << p.first << p.second << endl;

    vector v{1, 2, 3};
    cout << v.a << v.b << v.c << endl;

    cout << "\n\nprocess ended \n ";
    cin.get();
    return 0;
}
