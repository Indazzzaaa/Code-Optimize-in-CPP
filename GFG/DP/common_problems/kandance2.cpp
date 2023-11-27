#include <iostream>
#include <vector>
using namespace std;

long long maximumSum(int[], int);
long long maximumSum_spaceOptimized(int[], int);

int main(int argc, char const *argv[])
{
    // int v[] = {6, 4, 7, 8, 4, 7, 1, 7, 3, 6};
    int v[] = {-366, 50, 677, -13, -33, -923, 495, -851};
    int size = sizeof(v) / sizeof(v[0]);
    // cout << "Result is : " << maximumSum(v, size) << endl;
    cout << "Result is : " << maximumSum_spaceOptimized(v, size) << endl;

    return 0;
}

long long maximumSum(int arr[], int sizeOfArray)
{
    if (sizeOfArray == 1)
        return arr[0];
    if (sizeOfArray == 2)
        return max(arr[0], arr[1]);

    long long dp[sizeOfArray];

    dp[0] = arr[0];
    dp[1] = arr[1];

    for (int i = 2; i < sizeOfArray; i++)
    {
        if ((i - 3) >= 0)
        {
            long long temp1 = max(dp[i - 2], dp[i - 3]);
            long long temp2 = max<long long>(temp1 + arr[i], arr[i]);
            dp[i] = max(temp1, temp2);
        }
        else
        {
            dp[i] = max<long long>(max<long long>(dp[i - 2] + arr[i], dp[i - 2]), arr[i]);
        }
    }

    return max(dp[sizeOfArray - 1], dp[sizeOfArray - 2]);
}

void rotateArray(long long (&arr)[3], long long insert)
{
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = insert;
}

long long maximumSum_spaceOptimized(int arr[], int sizeOfArray)
{
    if (sizeOfArray == 1)
        return arr[0];
    if (sizeOfArray == 2)
        return max(arr[0], arr[1]);

    long long dp[3];

    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = max<long long>(max<long long>(dp[0] + arr[2], dp[0]), arr[2]);

    for (int i = 3; i < sizeOfArray; i++)
    {

        long long temp1 = max(dp[1], dp[0]);
        long long temp2 = max<long long>(temp1 + arr[i], arr[i]);
        long long temp3 = max(temp1, temp2);
        rotateArray(dp, temp3);
    }

    return max(dp[1], dp[2]);
}
