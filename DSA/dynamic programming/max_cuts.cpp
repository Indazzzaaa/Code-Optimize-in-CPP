#include <iostream>
#include <stdlib.h>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    int cutMax = max(maxCuts(n - a, a, b, c), max(maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)));
    if (cutMax == -1)
        return -1;

    return cutMax + 1;
}

int maxCutsDP(int n, int a, int b, int c)
{

    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);
        if (i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }
        if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1)
            dp[i] += 1;
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]\n\n";
    cout << "Max cut rec : " << maxCuts(5, 1, 2, 3) << endl;
    cout << "Max cut dp : " << maxCutsDP(23, 12, 11, 13) << endl;
    cout << "Max cut dp : " << maxCutsDP(5, 2, 4, 2) << endl;
    cout << "\n\n[Process Ended]";

    return 0;
}
