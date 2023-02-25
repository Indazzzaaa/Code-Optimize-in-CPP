#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int longestIncreasingSub(const vector<int> &v)
{

    const int &size = v.size();
    int arr[size];

    arr[0] = 1;
    int maxFound = 1;
    for (int i = 1; i < v.size(); i++)
    {
        arr[i] = 1; // it will atleast have the value 1
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                arr[i] = max(arr[i], arr[j] + 1);
                maxFound = max(maxFound, arr[i]);
            }
        }
    }

    return maxFound;
}

int max_sum_increasing_subArray(const vector<int> &v)
{

    const int &size = v.size();
    int arr[size];
    arr[0] = v[0];
    int maxSum = INT_MIN;
    for (int i = 1; i < size; i++)
    {
        arr[i] = v[i];
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                arr[i] = max(arr[i], arr[j] + v[i]);
                maxSum = max(maxSum, arr[i]);
            }
        }
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process started]\n\n";
    cout << "Max found is : " << longestIncreasingSub({4, 10, 6, 5, 8, 11, 2, 20}) << endl;
    cout << "Max Sum found is : " << max_sum_increasing_subArray({3, 20, 4, 6, 7, 30}) << endl;
    cout << "\n\n[Process Ended]";

    return 0;
}
