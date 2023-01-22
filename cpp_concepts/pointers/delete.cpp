#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int *arr = new int[10]{60, 75};
    cout << arr[0] << endl
         << sizeof(arr) << endl;

    delete arr; // actually we don't have to put delete[] arr to deleted , this also working
    cout << arr[1] << endl
         << sizeof(arr) << endl;

    return 0;
}
