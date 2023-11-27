#include <iostream>
using namespace std;

/*
 TODO : Print all the permutation which do not have the 'ab' as subscript

 */

int count = 0;

bool isSafe(string &s, int i, int l, int r)
{
    if (l != 0 && (s[l - 1] == 'a' && s[i] == 'b'))
        return false;

    return true;
}

void permutation(string &s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
        count++;
        return;
    }

    for (int i = l; i < r; i++)
    {
        if (!isSafe(s, i, l, r))
            continue;
        swap(s[l], s[i]);
        permutation(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main(int argc, char const *argv[])
{
    string s = "abcdab";
    permutation(s, 0, s.length());
    cout << "Total eligible permutations : " << count << endl;

    return 0;
}
