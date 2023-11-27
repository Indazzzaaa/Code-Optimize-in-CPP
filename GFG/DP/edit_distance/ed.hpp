#include <iostream>
using namespace std;

// convert s1 to s2 with minimum number of operations
class EditDistance
{
public:
    static int solvRec(string s1, string s2, int l1, int l2)
    {
        if (l1 == 0)
            return l2;
        if (l2 == 0)
            return l1;

        if (s1[l1 - 1] == s2[l2 - 1])
        {
            return solvRec(s1, s2, l1 - 1, l2 - 1);
        }

        // min(delete , replace)

        int temp1 = min(solvRec(s1, s2, l1 - 1, l2), solvRec(s1, s2, l1 - 1, l2 - 1));

        // min( insert, min(delete,replace))
        int temp2 = min(temp1, solvRec(s1, s2, l1, l2 - 1));

        return 1 + temp2;
    }

    static int solveDP(string s1, string s2, int l1, int l2)
    {
        int rowCount = l1 + 1;
        int colCount = l2 + 1;
        int dp[rowCount][colCount];
        // filling up the base cases
        for (int col = 0; col < colCount; col++)
        {
            dp[0][col] = col;
        }

        for (int row = 1; row < rowCount; row++)
        {
            dp[row][0] = row;
        }

        // fill up the dp array.
        for (int row = 1; row < rowCount; row++)
        {
            for (int col = 1; col < colCount; col++)
            {
                if (s1[row - 1] == s2[col - 1])
                {
                    dp[row][col] = dp[row - 1][col - 1];
                }
                else
                {
                    // delete , replace
                    int temp1 = min(dp[row - 1][col], dp[row - 1][col - 1]);
                    // insert, (delete,replace)
                    int temp2 = min(dp[row][col - 1], temp1);

                    dp[row][col] = 1 + temp2;
                }
            }
        }

        return dp[rowCount - 1][colCount - 1];
    }
};