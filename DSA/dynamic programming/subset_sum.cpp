#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int subset_sum_rec(const vector<int> &v, int sum, int n)
{

    if (n == 0)
    {
        return sum == 0 ? 1 : 0;
    }
    //  no need to explore those nodes already having the sum 0;
    if (sum < 0)
        return 0;

    return subset_sum_rec(v, sum - v[n - 1], n - 1) +
           subset_sum_rec(v, sum, n - 1);
}

// ! That is np hard problem , which can't be solved in polynomial time complexity
int subset_sum_dp(const vector<int> &v, int sum, int n)
{

    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            //  ! handling the -ve sum situation
            if ((j - v[i - 1]) >= 0)
            {
                dp[i][j] += dp[i - 1][j - v[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]" << endl;
    cout << "Total subsets are rec : " << subset_sum_rec({1, 8, 15, 6, 16, 3, 5, 7}, 15, 8) << endl;
    cout << "Total subsets are dp : " << subset_sum_dp({1, 8, 15, 6, 16, 3, 5, 7}, 15, 8);
    cout << "\n\n[Process Ended]";

    return 0;
}
