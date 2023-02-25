#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
extern void printSubset_test();
extern void countWayTest();

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]\n\n";
    countWayTest();
    cout << "\n\n[Process Ended ] \n\n";

    cin.get();

    return 0;
}

void printSubset(const vector<int> &arr, vector<int> &res, int l)
{

    if (l == arr.size())
    {
        if (res.size() == 0)
        {
            cout << "{}" << endl;
            return;
        }

        for_each(res.begin(), res.end(), [](int element)
                 { cout << element << " "; });
        cout << endl;
        return;
    }
    printSubset(arr, res, l + 1);
    res.push_back(arr[l]);
    printSubset(arr, res, l + 1);
    res.pop_back();
}

int countWays(const vector<int> &arr, int sum, int n)
{

    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (n == 0)
        return 0;

    return countWays(arr, sum - arr[n - 1], n) + countWays(arr, sum, n - 1);
}

int countWaysDp(const vector<int> arr, int sum)
{

    int dp[arr.size() + 1][sum + 1];
    dp[0][0] = 1;
    const int &size = arr.size() + 1;
    for (int i = 1; i < size; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; i++)
    {
        dp[1][i] = 0;
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            dp[i][j] = dp[i - 1][j]; // case where the ith coin is not included
            if (arr[i - 1] <= j)
            {
                // ! no way to handle negative value , so we'll include only when value is not negative , so that we won't go to negative index.
                dp[i][j] += dp[i][j - arr[i - 1]];
            }
        }
    }

    return dp[size][sum + 1];
}

void printSubset_test()
{
    vector<int> arr = {1, 2, 3};
    vector<int> res;
    printSubset(arr, res, 0);
}

void countWayTest()
{
    vector<int> arr = {2, 5, 3, 6};
    // cout << "Total ways are : " << countWays(arr, 10, arr.size()) << endl;
    cout << "Total ways are : " << countWaysDp(arr, 10) << endl;
}
