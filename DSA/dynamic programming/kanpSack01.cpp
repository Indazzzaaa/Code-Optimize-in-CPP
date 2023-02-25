#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int knapsack_rec(const vector<int> &v1, const vector<int> &wt, int w, int n)
{
    //  * if there is no weight then we won't be able to select anything
    if (w == 0)
    {
        return 0;
    }

    // * if n also become 0 then we won't have any weight as such so ultimately 0
    if (n == 0)
    {
        return 0;
    }

    // ! if current weight is greater then no point of selecting it
    if (wt[n - 1] > w)
    {
        return knapsack_rec(v1, wt, w, n - 1);
    }
    else
    {

        // * every selectable weight have two choices whether it would be selected or not
        //  * 1. not selected, 2, selected
        return max(knapsack_rec(v1, wt, w, n - 1), knapsack_rec(v1, wt, w - wt[n - 1], n - 1) + v1[n - 1]);
    }
}

int knapsack_dp(const vector<int> &v1, const vector<int> &wt, int w, int n)
{

    int dp[n + 1][w + 1];
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[j][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j - wt[i - 1] < 0)
            {
                dp[i][j] = dp[i - i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + v1[i - 1]);
            }
        }
    }

    return dp[n][w];
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]\n\n";
    cout << "Max gathered value rec : " << knapsack_rec({10, 40, 30, 50}, {5, 4, 6, 3}, 10, 4) << endl;
    cout << "Max gathered value rec : " << knapsack_dp({10, 40, 30, 50}, {5, 4, 6, 3}, 10, 4) << endl;
    cout << "Max gathered value rec : " << knapsack_rec({60, 100, 120}, {10, 20, 30}, 50, 3) << endl;
    cout << "Max gathered value dp : " << knapsack_dp({60, 100, 120}, {10, 20, 30}, 50, 3) << endl;
    cout << "\n\n[Process Ended]";

    return 0;
}
