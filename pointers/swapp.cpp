#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
    system("cls");
    int a = 10;
    int b = 20;
    int *aptr, *bptr;
    aptr = &a;
    bptr = &b;
    *aptr = *aptr ^ *bptr ^ (*bptr = *aptr);
    cout << "a is : " << a;
    cout << "\tb is :  " << b << endl;
    cout << "aptr : " << aptr << endl;
    return 0;
}
