#include <iostream>
#include <stdlib.h>
using namespace std;

struct test
{
    void fun2()
    {
        cout << "Fun 2 calling " << endl;
    }
};

void fun1()
{
    cout << "Fun 1 calling" << endl;
}

typedef void (*rec)();

rec fun2()
{
    cout << "return function called " << endl;
    return fun1;
}

int main(int argc, char const *argv[])
{
    system("cls");
    void (*funPtr1)() = fun1;

    funPtr1();
    void (test::*funPtr2)() = &test::fun2;
    test obj;

    (obj.*funPtr2)();

    auto ret = fun2();
    ret();

    void (*funPtr3)() = &fun1;
    funPtr3();
    auto &funPtr4 = fun1;
    funPtr4();
    int a = 20;
    int &b = a;
    cout << b << endl;

    return 0;
}
