#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    int a = 10;
    int &b = a;
    cout << &a << endl
         << &b << endl;

    return 0;
}
