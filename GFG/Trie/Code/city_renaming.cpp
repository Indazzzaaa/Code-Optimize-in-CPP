#include <iostream>
#include <vector>
using namespace std;

struct trieNode
{

    trieNode *children[26];
    bool isEOW;
    int count;
    trieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isEOW = false;
        count = 0;
    }
};

void solve(string &s, trieNode *root)
{
    string result = "";
    bool resFound = false;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (root->children[index] == NULL)
        {
            root->children[index] = new trieNode();
            root = root->children[index];
            if (!resFound)
            {
                result.push_back(s[i]);
                resFound = true;
            }
        }
        else
        {
            result.push_back(s[i]);
            root = root->children[index];
        }
    }

    root->count = root->count + 1;
    // this for the word which is just seems to prefix of another word
    if (!resFound && !root->isEOW)
    {
        cout << s << endl;
        res->isEOW = true;
        return;
    }

    root->isEOW = true;

    // if reached end of the word and resFound is still false means we are not able to find the prefix , that means it's repeated word
    if (!resFound)
    {
        result.push_back(' ');

        result.push_back('0' + root->count);
        cout << result << endl;
        return;
    }

    cout << result << endl;
}

void check(string *arr, int n)
{
    cout << "Number of string  given : " << n << endl;
    trieNode *root = new trieNode();
    for (int i = 0; i < n; i++)
    {
        solve(arr[i], root);
    }

    cout << "Program Finished!";
}

int main(int argc, char const *argv[])
{
    string arr[] = {"xhadafdsaf", "x"};
    int size = sizeof(arr) / sizeof(arr[0]);
    check(arr, size);
    return 0;
}
