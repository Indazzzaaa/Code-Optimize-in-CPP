#include <iostream>
using namespace std;

class LCS
{
public:
    static int rec(string s1, string s2, int n1, int n2)
    {
        if (n1 == 0 || n2 == 0)
            return 0;

        if (s1[n1 - 1] == s2[n2 - 1])
            return 1 + rec(s1, s2, n1 - 1, n2 - 1);

        return max(rec(s1, s2, n1, n2 - 1), rec(s1, s2, n1 - 1, n2));
    }

    static int dp_tabulation(string s1, string s2, int n1, int n2)
    {
        const int row = n1 + 1;
        const int col = n2 + 1;
        int dp[row][col] = {0};
        for (int j = 0; j < col; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 0; i < row; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n1][n2];
    }

    static int space_optimize(string s1, string s2, int n1, int n2)
    {
        const int row = n1 + 1;
        const int col = n2 + 1;
        int dp[2][col] = {0};
        for (int j = 0; j < col; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 0; i < 2; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[1][j] = 1 + dp[0][j - 1];
                else
                    dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            }
            // once row is finished shift row-1 data to row-0
            for (int i = 0; i < col; i++)
            {
                dp[0][i] = dp[1][i];
            }
        }

        return dp[1][n2];
    }
};
