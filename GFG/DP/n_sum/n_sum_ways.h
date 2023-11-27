#include <iostream>
#include <vector>
#include <cmath>

constexpr int MOD = static_cast<int>(std::pow(10, 9)) + 7;
using namespace std;

class N_Sum
{

private:
    static int solveRec(int sum, int num)
    {
        if (sum == 0)
            return 1;

        if (num == 0)
            return 0;

        if (sum < 0)
            return 0;

        return (solveRec(sum, num - 1) % MOD + solveRec(sum - num, num) % MOD) % MOD;
    }

public:
    static int rec(int sum)
    {
        return N_Sum::solveRec(sum, sum - 1);
    }

    static int dp_tabulation(int sum)
    {
        int size = sum + 1;
        vector<int> dp(size, 0);
        dp[0] = 1;
        for (int i = 1; i < sum; i++)
        {
            for (int j = i; j < size; j++)
            {
                dp[j] += dp[j - i];
            }
        }

        return dp[size - 1];
    }
};
