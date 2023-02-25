#include <iostream>
#include <stdlib.h>
using namespace std;

int sum(int x, int y)
{
    return x + y;
}

int main(int argc, char const *argv[])
{
    system("cls");
    int (*sumPtr)(int, int);
    sumPtr = sum;
    cout << "Address of main function is : " << main << endl;
    cout << "Address of sum function is : " << &sum << endl;
    cout << "Address of sumPtr function is : " << &sumPtr << endl;
    return 0;
}
