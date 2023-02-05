// bubble sort, selection sort, insertion sort
#include <vector>
#include <stdlib.h>
#include "newOverrite.cpp"
#include "printFun.cpp"

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool swaped = false;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swaped = true;
            }
        }

        if (!swaped)
        {
            cout << "Array found sorted in middle : " << endl;
            return;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = i;
        while (curr > 0 && arr[curr - 1] > arr[curr])
        {
            swap(arr[curr - 1], arr[curr]);
            curr--;
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallElementIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallElementIndex] > arr[j])
            {
                smallElementIndex = j;
            }
        }
        swap(arr[smallElementIndex], arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    // insertionSort(arr, size);
    // selectionSort(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);
    cin.get();
    return 0;
}
