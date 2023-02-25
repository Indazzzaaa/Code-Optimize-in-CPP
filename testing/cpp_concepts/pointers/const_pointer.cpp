#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{

    int a = 10;
    // can not modify the value of a , but can point to another variable
    const int *x; // same as ==> int const* x;
    x = new int;
    x = &a;
    // (*x)++; //! error

    // can not reference to another variable but can change the value of a
    int *const y = &a;
    (*y)++;
    // y = &x; //! error

    // can not reference to another variable and can not change the value of a as well
    const int *const z = &a;
    // (*z)++; // !error
    // z = &x; //! error
    return 0;
}
