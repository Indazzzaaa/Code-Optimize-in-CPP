// person can go either 1 stair or 2
// count total  possible ways he can go up the stairs.
// I took the approach form going from top to bottom
// that's why going to bottom(which is n==0) from n==1 require 1 step.

#include <iostream>
using namespace std;

const int MOD = 1000000007;

int countWaysRec(int n);
int countWaysDP(int n);
int countWaysDP_SpaceOptimized(int n);
int countWays_Distinct_DP_SpaceOptimized(int n);
int countWays_Distinct_DP_SuperFast(int n);

int main(int argc, char const *argv[])
{
    // cout << "Result is : " << countWaysRec(10) << endl;
    // cout << "Result is : " << countWaysDP(84) << endl;
    cout << "Result is : " << countWaysDP_SpaceOptimized(10) << endl;
    cout << "Result is : " << countWays_Distinct_DP_SpaceOptimized(10) << endl;
    cout << "Result is : " << countWays_Distinct_DP_SuperFast(10) << endl;
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

int countWaysDP_SpaceOptimized(int n)
{
    int dp[2];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = (dp[0] + dp[1]) % MOD;
        dp[0] = dp[1];
        dp[1] = temp;
    }

    return dp[1];
}

int countWays_Distinct_DP_SpaceOptimized(int n)
{
    // solve on page and papper to get this formula idea
    // dp[1]=1 , dp[2]=2 , dp[3] = 2==dp[1]+1, dp[4]=3 , dp[5]=3
    int dp[3];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        int temp = dp[1] + 1;
        dp[1] = dp[2];
        dp[2] = temp;
    }

    return dp[2];
}

int countWays_Distinct_DP_SuperFast(int n)
{
    return (int)(n / 2) + 1;
}