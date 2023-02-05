//  meger sort, quick sort
#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge(int arr[], int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + j + 1];
    }

    int i1 = 0, i2 = 0;
    int index = l;
    while (i1 < n1 && i2 < n2)
    {
        if (left[i1] < right[i2])
        {
            arr[index] = left[i1];
            i1++;
        }
        else
        {
            arr[index] = right[i2];
            i2++;
        }

        index++;
    }

    while (i1 < n1)
        arr[index++] = left[i1++];
    while (i2 < n2)
        arr[index++] = right[i2++];
}

void mergeSort(int arr[], int l, int r)
{

    if (r > l)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void unionOfArrays(int arr1[], int n1, int arr2[], int n2)
{
    int i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (i1 != 0 && arr1[i1 - 1] == arr1[i1])
        {
            i1++;
        }
        if (i2 != 0 && arr2[i2 - 1] == arr2[i2])
        {
            i2++;
        }
        else if (arr1[i1] > arr2[i2])
        {
            if (i2 == 0 || arr2[i2 - 1] != arr2[i2])
            {
                cout << arr2[i2] << " ";
                i2++;
            }
        }
        else if (arr2[i2] > arr1[i1])
        {
            if (i1 == 0 || arr1[i1 - 1] != arr1[i1])
            {
                cout << arr1[i1] << " ";
                i1++;
            }
        }
        else
        {
            cout << arr1[i1] << " ";
            i1++;
            i2++;
        }
    }

    while (i1 < n1)
    {
        if (i1 == 0 || arr1[i1 - 1] != arr1[i1])
            cout << arr1[i1++] << " ";
    }

    while (i2 < n2)
    {
        if (i2 == 0 || arr1[i2 - 1] != arr1[i2])
            cout << arr2[i2++] << " ";
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    int arr1[] = {2, 4, 6, 8, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    unionOfArrays(arr1, size1, arr2, size2);
    cin.get();

    return 0;
}
