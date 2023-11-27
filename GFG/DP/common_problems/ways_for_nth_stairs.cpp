// person can go either 1 stair or 2
// count total  possible ways he can go up the stairs.

#include <iostream>
using namespace std;

const int MOD = 1000000007;

int countWaysRec(int n);
int countWaysDP(int n);

int main(int argc, char const *argv[])
{
    // cout << "Result is : " << countWaysRec(10) << endl;
    cout << "Result is : " << countWaysDP(84) << endl;
    cout << "MOD : " << MOD;
    return 0;
}

int countWaysRec(int n)
{

    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    return countWaysRec(n - 1) + countWaysRec(n - 2);
}

int countWaysDP(int n)
{

    // dp[i] tells number of way to go till ith stair

    int dp[n + 1];
    // base case
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}