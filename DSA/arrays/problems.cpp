#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

// or we can say left rotate
void rotateByDAntiClock(int arr[], int n, int d);
void majorityElement(int arr[], int n);
int removeDupInSortd(int arr[], int n);
void moveSpecificElementToEnd(int arr[], int n, int element);
void maxJI(int arr[], int n);
void maxSumSubArray(int arr[], int n);

int main(int argc, char const *argv[])
{
    // system("cls");
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    // maxJI(arr, 4);
    int size = sizeof(arr) / sizeof(arr[0]);
    maxSumSubArray(arr, size);
    return 0;
}

// This solution is o(n) and only works if we are sure there is majority element and we have to find it.
void majorityElement(int arr[], int n)
{

    int resIndex = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (resIndex < 0)
        {
            resIndex = i;
            count++;
        }
        else if (arr[resIndex] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
                resIndex = -1;
        }
    }

    if (resIndex < 0)
    {
        cout << "No majority exist";
    }
    else
    {
        cout << "Majority found is " << arr[resIndex];
    }
}

void rotateByDAntiClock(int arr[], int n, int d)
{
    cout << "Rotation started " << endl;
    int curr = 0;
    int temp = arr[0];
    int tempN = n;
    while (n-- > 0)
    {
        // for getting the location where this element is going to go
        curr = (curr - d + tempN) % tempN;
        swap(temp, arr[curr]);
    }

    // printing rotated array
    for (int i = 0; i < tempN; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "Rotation end  " << endl;
}

int removeDupInSortd(int arr[], int n)
{

    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res++] = arr[i];
        }
    }

    return res;
}

void moveSpecificElementToEnd(int arr[], int n, int d)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != d)
        {
            swap(arr[i], arr[count++]);
        }
    }
}

void maxJI(int arr[], int n)
{
    // max arr[j] - arr[i] such that j> i , only possible when larges - smallest;
    int res = arr[1] - arr[0];
    int smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - smallest);
        smallest = min(smallest, arr[i]);
    }

    cout << "Largest difference is : " << res << endl;
}

void maxSumSubArray(int arr[], int n)
{
    int res = 0;
    int currLargest = 0;
    for (int i = 0; i < n; i++)
    {
        currLargest = max(currLargest + arr[i], arr[i]);
        res = max(res, currLargest);
    }

    cout << "Maximum sum is  : " << res << endl;
}