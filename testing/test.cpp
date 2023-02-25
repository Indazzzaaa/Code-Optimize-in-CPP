#include <iostream>
#include <stdlib.h>
using namespace std;

const int &fun(const int &b, const int &c)
{
    cout << "Address of b is : " << &b << endl;
    cout << "Address of c is : " << &c << endl;
    return b;
}

int &fun2(int n)
{
    cout << &n;
    return n;
}

int main()
{

    // system("CLS");
    const int &c = fun(19, 20);

    cout << &c << endl;

    return 0;
}
