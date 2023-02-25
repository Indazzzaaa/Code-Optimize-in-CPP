#include <iostream>
#include <stdlib.h>
using namespace std;

int test()
{
    cout << "hello world " << endl;
}

int main(int argc, char const *argv[])
{
    cout << test() << endl;
    const int a = 10;
    int const b = 20;
    const int *ptr1;
    // int *const ptr2; this will throw error think why

    cout << a << endl;

    return 0;
}
