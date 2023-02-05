#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isPalindrome(string &s)
{

    int begin = 0, end = s.length() - 1;
    while (end > begin)
    {
        if (s[begin] != s[end])
            return false;
        begin++, end--;
    }

    return true;
}

bool isSubSeq(string &s1, string &s2)
{
    if (s2.length() > s1.length())
        return false;

    int j = 0;
    for (int i = 0; i < s1.length() && j < s2.length(); i++)
    {

        if (s1[i] == s2[j])
            j++;
    }

    return j == s2.length();
}

bool isAnagram(string &s1, string &s2)
{
    vector<char> map(256, 0);
    cout << "Size of vector is : " << map.size() << endl;

    if (s1.length() != s2.length())
        return false;
    for (int i = 0; i < s1.length(); i++)
    {
        map[s1[i]]++;
        map[s2[i]]--;
    }

    for (auto element : map)
    {
        if (element != 0)
            return false;
    }

    return true;
}

void reverse(string &s, int start, int end)
{
    while (end > start)
    {
        s[start] = s[end] ^ s[start] ^ (s[end] = s[start]);
        start++;
        end--;
    }
}

void reverseWordOfString(string &s1)
{
    int startMarker = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == ' ')
        {
            reverse(s1, startMarker, i - 1);
            startMarker = i + 1;
        }
    }

    //  reverse the last word byself
    reverse(s1, startMarker, s1.length() - 1);

    reverse(s1, 0, s1.length() - 1);
}

void longestSubstringWithDistincELement(string &s)
{

    unordered_map<char, short> map;
    int res = 0, start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (map.count(s[i]) != 0)
        {
            res = max(res, i - start);
        }
        else
        {
            start = map[s[i]] + 1;
            res = max(res, i - start);
        }
        map[s[i]] = i;
    }

    cout << "Maximum length is : " << res << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");

    /*  string s1 = "mama";
     string s2 = "cam";
     cout << isPalindrome(s1) << endl;
     cout << isSubSeq(s1, s2) << endl; */

    /*   string s1 = "abc";
      string s2 = "zba";
      cout << isAnagram(s1, s2) << endl; */

    /*     string s1 = "Welcome to this world";
        reverseWordOfString(s1);
        cout << s1 << endl; */

    string s = "abcdab";
    longestSubstringWithDistincELement(s);

    return 0;
}
