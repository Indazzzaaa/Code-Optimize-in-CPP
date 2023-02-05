// 1. Testing of cpp sort function
// 2. Testing of passing custom sort fuction
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void *operator new(size_t size)
{

    cout << "Allocation required : " << size << endl
         << endl;
    return malloc(size);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printVector(vector<int> &v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

bool myComp(int a, int b)
{
    return b > a;
}

int main(int argc, char const *argv[])
{

    system("cls");

    // * vector<int> *v1 = new vector<int>{10, 12, 8, 7, 13, 18};  This will allocate extra 12 bytes on for managing internal size, v1.begin(),v1.end()

    int arr[] = {10, 12, 8, 7, 13};
    vector<int> v1 = {10, 12, 8, 7, 13, 18};
    sort(arr, arr + (sizeof(arr) / sizeof(arr[0])), myComp);
    sort(v1.begin(), v1.end());

    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    printVector(v1);

        cin.get();

    return 0;
}
