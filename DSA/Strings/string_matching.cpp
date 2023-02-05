#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

void rabinKarb(string &s1, string &s2)
{

    const int mod = 101;
    const int d = 256;
    int h = 1;
    int pat = 0;
    int txt = 0;
    for (int i = 1; i < s2.length(); i++)
    {
        h = (h * d) % mod;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        pat = (pat * d + s2[i]) % mod;
        txt = (txt * d + s1[i]) % mod;
    }

    for (int i = 0; i < s1.length() - s2.length() + 1; i++)
    {
        if (pat == txt)
        {
            // check whether they are exactly the same or not
            bool isFound = true;
            for (int j = 0; j < s2.length(); j++)
            {
                if (s1[i + j] != s2[j])
                    isFound = false;
            }
            if (isFound)
            {
                cout << "Pattern found at : " << i << endl;
            }
        }

        if (i < s1.length() - s2.length())
        {
            txt = (d * (txt - h * s1[i]) + s1[i + s2.length()]) % mod;
            if (txt <= 0)
                txt = mod + txt;
        }
    }
}

void buildLPS(string &s1, vector<int> &lps)
{

    int len = 0;
    lps[0] = 0; // since first character will always be zero
    int i = 1;
    while (i < s1.length())
    {

        if (s1[len] == s1[i])
        {
            lps[i] = ++len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }

    cout << "For string : " << s1 << endl;
    cout << "Our LPS is : " << endl;
    for_each(lps.begin(), lps.end(), [](int element)
             { cout << element << "  "; });
    cout << endl;
}

void kmp(string &s1, string &s2)
{

    vector<int> lps(s2.length(), 0);
    buildLPS(s2, lps);
    int i = 0, j = 0;
    while (i < s1.length())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }

        if (j == s2.length())
        {
            cout << "Pattern found at : " << i - s2.length() << endl;
            j = lps[j - 1];
        }
        else if (i < s1.length() && s1[i] != s2[j])
        {
            if (j == 0)
                i++;
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

void anagramSearch(string &s1, string &s2)
{

    int m = s2.length();
    int n = s1.length();
    for (int i = 0; i < n - m + 1; i++)
    {

        vector<short> map(256, 0);
        for (int j = 0; j < m; j++)
        {
            map[s1[i + j]]++;
            map[s2[j]]--;
        }
        for (int t = 0; t < map.size(); i++)
        {
            if (map[t] != 0)
            {
                break;
            }
        }

        cout << "Found at : " << i << endl;
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    string s1 = "ababcabababa";
    string s2 = "ababa";
    // rabinKarb(s1, s2);
    kmp(s1, s2);

    cin.get();
    return 0;
}
