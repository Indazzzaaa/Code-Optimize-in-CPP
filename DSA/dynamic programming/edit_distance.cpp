#include <iostream>
#include <stdlib.h>
using namespace std;

int editDistance(const string s1, const string s2, int n1, int n2)
{

    if (n1 == 0)
    {
        return n2;
    }
    if (n2 == 0)
    {
        return n1;
    }

    if (s1[n1 - 1] == s2[n2 - 1])
    {
        return editDistance(s1, s2, n1 - 1, n2 - 1);
    }
    else
    {

        return 1 + min(min(editDistance(s1, s2, n1, n2 - 1), editDistance(s1, s2, n1 - 1, n2)), editDistance(s1, s2, n1 - 1, n2 - 1));
    }
}

//  ! as we can see that we only require the two rows for processing at a time so we can further optimize it
//  in terms of memory used
int editDistanceDP(const string s1, const string s2, int n1, int n2)
{

    int dp[n1 + 1][n2 + 1];
    dp[0][0] = 0;
    const int callCount = n1 + 1;
    const int callCount2 = n2 + 1;
    for (int i = 1; i < callCount; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j < callCount2; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i < callCount; i++)
    {
        for (int j = 1; j < callCount2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
    }

    return dp[n1][n2];
}

int main(int argc, char const *argv[])
{

    system("cls");
    cout << "[Process Started]\n\n";
    cout << "Edit distance recursive is " << editDistance("sunday", "saturday", 6, 8) << endl;
    cout << "Edit distance DP is " << editDistanceDP("sunday", "saturday", 6, 8) << endl;
    cout << "\n\n[Process Ended]";
    return 0;
}
