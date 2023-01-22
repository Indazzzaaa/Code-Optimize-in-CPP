#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int upper_bound(int arr[], int n, int x)
{
    int start = 0, end = n - 1;
    int res = n;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] > x)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return res;
}

int lower_bound(int arr[], int n, int x)
{

    int res = 0, start = 0, end = n - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < x)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return res;
}

bool searchInSortedRotated(int arr[], int n, int x)
{
    int start = 0, end = n - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (x == arr[mid])
            return true;
        if (arr[start] <= arr[mid])
        {
            // if left sorted
            if (x >= arr[start] && x < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        { // if right sorted
            if (x > arr[mid] && x <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return false;
}

bool searInDecSortedArray(int arr[], int n, int x)
{

    int start = 0, end = n - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[end] < arr[mid])
        {

            if (x < arr[mid] && x >= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            if (arr[mid] < x && x <= arr[start])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return false;
}

int medianOfTwoSortedArray(int arr1[], int arr2[], int n1, int n2)
{
}

// This will print all possible pair available
void pairWithGivenSum(int arr[], int n, int x)
{
    int start = 0, end = n - 1;
    while (end > start)
    {

        if (arr[start] + arr[end] == x)
        {
            cout << "Pair is : " << arr[start] << ", " << arr[end] << endl;
        }
        if (arr[start] + arr[end] > x)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
}

// THis will print all possible triplet available

bool isPair(int arr[], int n, int strt, int x, vector<int> &vec)
{
    int start = strt, end = n - 1;
    vec.clear(); // for clearing the data from the last output
    while (end > start)
    {

        if (arr[start] + arr[end] == x)
        {
            vec.push_back(arr[end]);
            vec.push_back(arr[start]);
            return true;
        }
        else if (arr[start] + arr[end] > x)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return false;
}
void printVector(vector<int> &v)
{
    for (auto i : v)
        cout << i << "\t";
}

void triplet_with_given_sum(int arr[], int n, int x)
{

    vector<int> result(3, 0);
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, n, i + 1, x - arr[i], result))
        {
            result.push_back(arr[i]);
            cout << "Triplet are  : ";
            printVector(result);
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    /*  int arr[] = {10, 20, 30, 40, 50, 60};
     int size = sizeof(arr) / sizeof(arr[0]);
     cout << "Upper bound found at : " << upper_bound(arr, size, -1) << endl;
     cout << "lower bound found at : " << lower_bound(arr, size, -1) << endl;

     // test for rotated sorted array
     int arr2[] = {20, 10, 50, 40, 30};
     int size2 = sizeof(arr2) / sizeof(arr2[0]);
     cout << "is Found in rotated sorted array : " << searchInSortedRotated(arr2, size2, 30) << endl;
     cout << "is Found in dec rotated sorted array : " << searInDecSortedArray(arr2, size2, 40) << endl;
  */

    int arr3[] = {10, 20, 30, 40, 50, 60};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    // pairWithGivenSum(arr3, size3, 70);
    triplet_with_given_sum(arr3, size3, 110);

    cin.get();
    return 0;
}
