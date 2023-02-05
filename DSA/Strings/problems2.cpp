#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void smallestwindow(string &txt, string &pat)
{
    short map[256] = {0};
    int charCount = 0;
    for (auto i : pat)
    {
        if (map[i] == 0)
        {
            charCount++;
        }
        map[i]++;
    }

    int startWindow = 0, endWindow = 0;
    int minStart = -1;
    int res = INT_MAX;
    while (endWindow < txt.length())
    {

        if (charCount == 0)
        {
            if (res > endWindow - startWindow + 1)
            {
                res = endWindow - startWindow + 1;
                minStart = startWindow;
            }
            map[txt[startWindow]]++;
            if (map[txt[startWindow]] > 0)
                charCount++;
            startWindow++;
        }
        else
        {
            endWindow++;
            map[txt[endWindow]]--;
            if (map[txt[endWindow]] == 0)
            {
                charCount--;
            }
        }
    }
    cout << "Length is : " << res << endl;
    cout << "Starting at position : " << minStart << endl;
    cout << "The substring is  : " << txt.substr(minStart + 1, minStart + res) << endl;
}

int main(int argc, char const *argv[])
{
    string txt = "zoomlazapzo";
    string pat = "oza";
    smallestwindow(txt, pat);
    return 0;
}
