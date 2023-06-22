#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
void printVector(string msg, vector<int> v)
{
    cout << msg << endl;
    for_each(v.begin(), v.end(), [](auto element)
             { cout << element << " "; });
    cout << endl;
}

void next_permutaion()
{
    // note if array is reverse sorted then next permutaion will be array in increaing order
    vector<int> v = {1, 2, 3, 6, 5, 4};
    printVector("Initially array", v);
    // so next permutation will be element just greater then that
    // just greater number will be from right side
    int first_inversion = -1;
    for (int i = v.size() - 2; i > -1; i--)
    {
        if (v[i] < v[i + 1])
        {
            first_inversion = i;
            break;
        }
    }
    if (first_inversion == -1)
    {
        cout << "Array is already reverse sorted  " << endl;
        sort(v.begin(), v.end());
        printVector("Next permutation", v);

        return; // no point of checking anything further
    }
    int just_greater = -1;
    // now just greater number on right of found and swap between those
    for (int i = v.size() - 1; i > first_inversion; i--)
    {
        if (v[first_inversion] < v[i])
        {
            if (just_greater > -1)
            {
                just_greater = v[just_greater] < v[i] ? just_greater : i;
            }
            else
            {
                just_greater = i;
            }
        }
    }

    // swap (first inversion,just_greater) , sort after first inversion
    swap(v[first_inversion], v[just_greater]);
    sort(v.begin() + first_inversion + 1, v.end());

    printVector("Next permutation", v);
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]\n\n";
    next_permutaion();

    cout << "\n\n[Process Ended]";

    return 0;
}

int max_normal_sum(int *arr, int n)
{

    int sum = 0;
    int maxEnding = 0;
    for (int i = 0; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        sum = max(sum, maxEnding);
    }

    return sum;
}

int circular_sub_array()
{

    int arr[] = {3, -4, 5, 6, -8, 7};
    int size = sizeof(arr) / sizeof(int);
    int normal_sum = max_normal_sum(arr, size);
    int arr_sum = 0;
    for (int i = 0; i < size; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int circular_sum = arr_sum + max_normal_sum(arr, size);
    return max(normal_sum, circular_sum);
}

void rotateArray()
{

    int arr[] = {1, 2, 3, 4, 5};
    int k = 3;
    int size = sizeof(arr) / sizeof(int);
    int index = 0, element = arr[0];
    int elementCount = size;
    while (elementCount > 0)
    {
        int newIndex = index - k;
        newIndex = newIndex > -1 ? newIndex : newIndex + size;
        swap(arr[newIndex], element);
        index = newIndex;
        elementCount--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//  only works with the increasing order array
void check_sorted_rotated()
{
    int arr[] = {3, 2, 1, 5, 4};
    int size = sizeof(arr) / sizeof(int);
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }
    if (arr[size - 1] > arr[0])
    {
        count++;
    }
    // <=1 is for case when all elments are 1
    if (count <= 1)
    {
        cout << "array is sorted and rotated" << endl;
    }
    else
    {
        cout << "your array is not sorted" << endl;
    }
}
