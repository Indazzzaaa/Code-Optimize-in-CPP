#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void printMatrix(vector<vector<int>> m)
{
    for_each(m.begin(), m.end(), [](vector<int> v)
             {
                 for_each(v.begin(), v.end(), [](int element)
                          { cout << element << " "; });

                 cout << endl; });
}

void printLCS(string &s1, string &s2, vector<vector<int>> &map)
{
    int row = s1.length(), col = s2.length();
    vector<char> result(map[row][col]);
    while (row > 0 && col > 0)
    {

        if (s1[row - 1] == s2[col - 1])
        {
            // result.insert(result.begin(), s1[row - 1]);
            result.push_back(s1[row - 1]);
            row--;
            col--;
        }
        else
        {

            if (map[row - 1][col] > map[row][col - 1])
            {
                row--;
            }
            else
            {
                col--;
            }
        }
    }

    // printing the sequence
    for_each(result.rbegin(), result.rend(), [](auto element)
             { cout << element << " "; });
    cout << endl;
}
// ! biggest problem is we cannot take out the subsequence
int lcsRecursion(string &s1, string &s2, int n1, int n2)
{

    if (n1 == 0 || n2 == 0)
    {
        return 0;
    }

    if (s1[n1 - 1] == s2[n2 - 1])
    {
        return 1 + lcsRecursion(s1, s2, n1 - 1, n2 - 1);
    }

    return max(lcsRecursion(s1, s2, n1, n2 - 1), lcsRecursion(s1, s2, n1 - 1, n2));
}

int lcsMemoization(string &s1, string &s2, int n1, int n2, vector<vector<int>> m)
{

    if (n1 == 0 || n2 == 0)
    {
        m[n1][n2] = 0;
        return m[n1][n2];
    }

    if (m[n1 - 1][n2 - 1] == -1)
    {
        if (s1[n1 - 1] == s2[n2 - 1])
        {
            m[n1 - 1][n2 - 1] = 1 + lcsMemoization(s1, s2, n1 - 1, n2 - 1, m);
        }
        else
        {
            m[n1 - 1][n2 - 1] = max(lcsMemoization(s1, s2, n1, n2 - 1, m), lcsMemoization(s1, s2, n1 - 1, n2, m));
        }
    }

    return m[n1 - 1][n2 - 1];
}

void lcsTabulation(string &s1, string &s2, int n1, int n2)
{

    vector<vector<int>> map(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    // fill the row with 0
    for (int i = 0; i <= n2; i++)
    {
        map[0][i] = 0;
    }
    // fill the colm with 0
    for (int i = 0; i <= n1; i++)
    {
        map[i][0] = 0;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                map[i][j] = 1 + map[i - 1][j - 1];
            }
            else
            {
                map[i][j] = max(map[i - 1][j], map[i][j - 1]);
            }
        }
    }

    printMatrix(map);
    printLCS(s1, s2, map);
    cout << "LCS : " << map[n1][n2] << endl;
}

void lcsTabulationMemoryOptimization(string &s1, string &s2, int n1, int n2)
{

    vector<vector<int>> map(2, vector<int>(s2.length() + 1, -1));
    // fill the row with 0
    for (int i = 0; i <= n2; i++)
    {
        map[0][i] = 0;
    }
    map[0][0] = 0;
    map[1][0] = 0;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                map[1][j] = 1 + map[0][j - 1];
            }
            else
            {
                map[1][j] = max(map[0][j], map[1][j - 1]);
            }
        }

        // copying the 1st row value to last row
        for (int t = 0; t <= n2; t++)
        {
            map[0][t] = map[1][t];
        }
    }

    printMatrix(map);
    // printLCS(s1, s2, map);
    cout << "LCS : " << map[1][n2] << endl;
}

void recursionTest()
{

    string s1 = "abcdgh";
    string s2 = "aedfhr";
    cout << "Lcs is : " << lcsRecursion(s1, s2, s1.length(), s2.length()) << endl;
}

void memoizationTest()
{
    string s1 = "aggtab";
    string s2 = "gxtxayb";
    vector<vector<int>> m(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    // printMatrix(m);
    int result = lcsMemoization(s1, s2, s1.length(), s2.length(), m);
    cout << "LCS is : " << result << endl;
}

void tabulationTest()
{
    string s1 = "aggtab";
    string s2 = "gxtxayb";
    lcsTabulation(s1, s2, s1.length(), s2.length());
}

void longestPallindromicSubSeq()
{

    string s1 = "geeksforgeeks";
    string s2 = string(s1.rbegin(), s1.rend());
    lcsTabulationMemoryOptimization(s1, s2, s1.length(), s2.length());
}

void longestRepeatingSubSequence(string &s1, string &s2, int n1, int n2)
{

    //  !same as lcs just one change
    vector<vector<int>> map(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    // fill the row with 0
    for (int i = 0; i <= n2; i++)
    {
        map[0][i] = 0;
    }
    // fill the colm with 0
    for (int i = 0; i <= n1; i++)
    {
        map[i][0] = 0;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            // ! this is the change both character should not be at same location
            if (s1[i - 1] == s2[j - 1] && i != j)
            {
                map[i][j] = 1 + map[i - 1][j - 1];
            }
            else
            {
                map[i][j] = max(map[i - 1][j], map[i][j - 1]);
            }
        }
    }

    printMatrix(map);
    printLCS(s1, s2, map);
    cout << "LCS : " << map[n1][n2] << endl;
}

void longestRepeatingSubSequenceTest()
{
    string s1 = "aabb";
    longestRepeatingSubSequence(s1, s1, s1.length(), s1.length());
}

int main(int argc, char const *argv[])
{
    system("cls");
    // recursionTest();
    // memoizationTest();
    // tabulationTest();
    // longestPallindromicSubSeq();
    longestRepeatingSubSequenceTest();

    cin.get();

    return 0;
}
