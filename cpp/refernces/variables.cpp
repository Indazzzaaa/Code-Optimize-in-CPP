#include <iostream>
#include <stdlib.h>
using namespace std;

void fun_test(const int &c)
{
    cout << &c << endl;
}

const int &fun_test2(const int &c)
{
    return c;
}

int &fun_test3()
{
    int a = 10;
    int &c = a;
    cout << &c << endl;
    return c;
}

int fun_test4(const int a)
{
    return a;
}

int main(int argc, char const *argv[])
{
    system("cls");
    const int c;

    return 0;
}

void interestingTest()
{
    const int &c = 10;
    cout << c << endl;
    cout << &c << endl;
    const int &d = 20;
    cout << d << endl;
    cout << &d << endl;
    // * This is interesting
    int *p = (int *)&d;
    *p = 300;
    cout << *p << endl;
    cout << d << endl;
}

void pointerRef()
{
    int a = 10;
    int *p = &a;
    int *&p2 = p;
    cout << &p << endl;
    cout << &p2 << endl;
}

void var()
{
    int a = 10;
    int b = 20;
    int &c = a;
    cout << c << endl;
    c = b;
    cout << c << endl;
}
