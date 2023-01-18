// * 1D : pass to function, and return from func
// ! 2D : pass to function , and return from func
// ! vector : pass to function and return from func
//! http://www.eskimo.com/~scs/cclass/int/sx9a.html
#include <iostream>
#include <stdlib.h>
using namespace std;

#define print(x) cout << x << endl
#define log(x) cout << x

void oneDTest(int *arr, int n);
int *oneDReturn();

int main(int argc, char const *argv[])
{
    // system("cls");
    // oneDTest(arr, sizeof(arr) / sizeof(arr[0]));

    int(*a)[] = new int[3];

    cin.get();
    return 0;
}

int *oneDReturn()
{
    // ! this will throw error
    //*int arr[3] = {1}; // by initializing this way all will be '0' except first
    int *arr = new int[3]{1};
    return arr;
}

void oneDTest(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        print(arr[i]);
}
