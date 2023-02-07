#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>> m)
{
    for_each(m.begin(), m.end(), [](vector<int> v)
             {
                 for_each(v.begin(), v.end(), [](int element)
                          { cout << element << " "; });

                 cout << endl; });
}

void printSubstring(string &s1, string &s2, auto map, int row, int col)
{
    vector<char> result(map[row][col] - 1);
    do
    {
        // cout << s1[row - 1] << " ";
        result.push_back(s1[row - 1]);
        row--, col--;
    } while (row > 0 && col > 0);
    for_each(result.rbegin(), result.rend(), [](auto element)
             { cout << element << " "; });
    cout
        << endl;
}

int lc_subStringRecursive(string &s1, string &s2, int n1, int n2, int result)
{

    if (n1 == 0 || n2 == 0)
        return result;
    if (s1[n1 - 1] == s2[n2 - 1])
    {
        result = lc_subStringRecursive(s1, s2, n1 - 1, n2 - 1, result + 1);
    }
    result = max(result, max(lc_subStringRecursive(s1, s2, n1, n2 - 1, 0), lc_subStringRecursive(s1, s2, n1 - 1, n2, 0)));

    return result;
}

void lc_subStringTabulation(string &s1, string &s2)
{

    // ! to keep track of our result and place where that found
    int result = 0, row = 0, col = 0;
    vector<vector<int>> map(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                map[i][j] = 1 + map[i - 1][j - 1];
                if (map[i][j] > result)
                {
                    row = i, col = j;
                    result = map[i][j];
                }
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }

    printMatrix(map);
    printSubstring(s1, s2, map, row, col);
    cout << "Length of common substring is : " << result
         << endl;
}

void lc_subStringTabulation_MemoryOptimization(string &s1, string &s2)
{

    // ! to keep track of our result and place where that found
    int result = 0, row = 0, col = 0;
    vector<vector<int>> map(2, vector<int>(s2.length() + 1));
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                map[1][j] = 1 + map[0][j - 1];
                if (map[1][j] > result)
                {
                    row = i, col = j;
                    result = map[1][j];
                }
            }
            else
            {
                map[1][j] = 0;
            }
        }
        // copying the 1st index row to 0th
        for (int t = 0; t <= s2.length(); t++)
        {
            map[0][t] = map[1][t];
        }
    }

    printMatrix(map);
    cout << "Length of common substring is : " << result
         << endl;
}

void testRecursive()
{

    string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";

    cout << "Length of longest substring is : " << lc_subStringRecursive(s1, s2, s1.length(), s2.length(), 0) << endl;
}

void testTabulation()
{

    string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";
    lc_subStringTabulation(s1, s2);
}

void testTabulationMemoryOptimization()
{
    string s1 = "zxabcdezy";
    string s2 = "yzabcdezx";
    lc_subStringTabulation_MemoryOptimization(s1, s2);
}

int main(int argc, char const *argv[])
{

    testRecursive();
    // testTabulation();
    // testTabulationMemoryOptimization();

    return 0;
}
