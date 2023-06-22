#include <iostream>
#include <stdlib.h>
using namespace std;

bool binarySearch(int *_start, int *_end, int key)
{

    int size = _end - _start;
    int start = 0, end = size - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (_start[mid] == key)
        {
            return true;
        }
        else if (_start[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return false;
}
int find_last_occurance(int *_start, int *_end, int key)
{

    int size = _end - _start;
    int start = 0, end = size - 1;
    int foundPos = -1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (_start[mid] == key)
        {
            foundPos = mid;
            start = mid + 1;
        }
        else if (_start[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if (foundPos != -1)
    {
        return foundPos;
    }
    return size;
}

int find_only_repeated_element(int *arr, int n)
{

    int slow = 0, fast = 0;
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

void binaryTest()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 6};
    int size = sizeof(arr) / sizeof(int);
    cout << "Is element exist : " << binarySearch(arr, arr + size, 0) << endl;
    cout << " elment last occurance : " << find_last_occurance(arr, arr + size, 5) << endl;
    int arr2[] = {1, 2, 7, 4, 6, 5, 6, 7, 3};
    int size2 = sizeof(arr2) / sizeof(int);
    cout << "Found repeating element is : " << find_only_repeated_element(arr2, size2) << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    binaryTest();
    cout << "\n\n[Process Ended]" << endl;
    return 0;
}
