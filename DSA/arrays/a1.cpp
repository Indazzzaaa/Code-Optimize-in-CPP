#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // when you allocate memory on stack it has to be compile time known constant
    const int exampleSize = 5;
    int arrStack[exampleSize];
    system("cls");
    int *arr = new int[5];
    cout << &arr << endl
         << &(arr[0]) << endl;
    cin.get();
    return 0;
}
