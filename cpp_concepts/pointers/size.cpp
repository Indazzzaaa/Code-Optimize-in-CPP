#include <iostream>
#include <stdlib.h>
using namespace std;

void fun(int arr[])
{

    cout << "size of array is : " << sizeof(arr) << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    int arr[] = {1, 2, 3};
    cout << "size of array in main : " << sizeof(arr) << endl;
    fun(arr);

    return 0;
}
