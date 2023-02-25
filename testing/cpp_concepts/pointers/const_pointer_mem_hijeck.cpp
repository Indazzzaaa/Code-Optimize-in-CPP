#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    const int a = 2 + 8;
    int c = (int)(&a);
    int *p = (int *)c;
    (*p)++;
    cout << c << endl;
    cout << (int)&a << endl;
    cout << (int)p << endl;
    cout << *p << endl;
    cout << a << endl;
    cout << *p << endl;

    return 0;
}
