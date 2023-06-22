#include <iostream>
using namespace std;

void fun(int *arr)
{
    cout << arr << endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3};
    cout << arr << endl;
    fun(&arr[0]);
    int d = 10;
    int *prt = &d;
    int *&ptr = prt;
    cout << ptr << endl;

    return 0;
}
