#include <iostream>
#include <stdlib.h>
using namespace std;

void test1()
{
    int a = 10;
    int &b = a;
    cout << &b << "\t" << &a << endl;
}

void test2()
{
    int *ptr = new int(0);

    int *&b = ptr;
    cout << &ptr << "\t" << &b << endl;
}

int main(int argc, char const *argv[])
{

    return 0;
}
