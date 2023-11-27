#include <iostream>
#include <vector>
using namespace std;

class CoinChange
{
public:
    static int solveRec(vector<int> arr, int sum, int i)
    {
        if (sum == 0)
            return 1;
        if (i == 0 || sum < 0)
            return 0;

        return solveRec(arr, sum, i - 1) + solveRec(arr, sum - arr[i - 1], i);
    }

    static int dpSolve(vector<int> arr, int sum)
    {
        int rowCount = arr.size();
        int colCount = sum;
        int dp[rowCount + 1][colCount + 1];

        // base cases fill the dp
        for (int col = 1; col <= colCount; col++)
        {
            dp[0][col] = 0;
        }

        for (int row = 0; row <= rowCount; row++)
        {
            dp[row][0] = 1;
        }

        // building the our dp array

        for (int row = 1; row <= rowCount; row++)
        {
            for (int col = 1; col <= colCount; col++)
            {
                dp[row][col] = dp[row - 1][col];
                if (arr[row - 1] <= col)
                {
                    dp[row][col] += dp[row][col - arr[row - 1]];
                }
            }
        }

        return dp[rowCount][colCount];
    }
};