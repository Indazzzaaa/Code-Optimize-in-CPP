
/*
Largets number in k swaps
given:
        k-number of max swaps
        str: string which has to be swapped
 */
#include <iostream>
using namespace std;

void solve(string str, int k, int index, string &ans)
{
    int n = str.length();
    if (n == index or k == 0)
    {
        ans = max(ans, str);
        return;
    }
    solve(str, k, index + 1, ans);
    for (int i = index + 1; i < n; i++)
    {
        if (str[index] < str[i])
        {
            swap(str[i], str[index]);
            solve(str, k - 1, index + 1, ans);
            swap(str[i], str[index]);
        }
    }
}

string findMaximumNum(string str, int k)
{
    string ans = "";
    int index = 0;
    solve(str, k, index, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    string str = "61892795431";
    int k = 4;
    cout << findMaximumNum(str, k);
    return 0;
}
