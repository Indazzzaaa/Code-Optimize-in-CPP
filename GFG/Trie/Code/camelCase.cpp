/*

[Giving Error]
8
Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
H

 */

#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode *smallCase[26];
    TrieNode *bigCase[26];
    bool isEOW;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            smallCase[i] = NULL;
            bigCase[i] = NULL;
        }
        isEOW = false;
    }
};

void insert(TrieNode *root, string &s)
{

    TrieNode *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        // is the letter is capital letter
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            char pos = s[i] - 'A';
            if (curr->bigCase[pos] == NULL)
                curr->bigCase[pos] = new TrieNode();
            curr = curr->bigCase[pos];
        }
        else
        {
            char pos = s[i] - 'a';
            if (curr->smallCase[pos] == NULL)
                curr->smallCase[pos] = new TrieNode();
            curr = curr->smallCase[pos];
        }
    }

    curr->isEOW = true;
}

void search(TrieNode *node, string &pattern, string result, bool &isResultFound, int patIndex = 0)
{
    if (node == NULL)
        return;
    // base case
    if (patIndex == pattern.length() && node->isEOW)
    {
        isResultFound = true;
        cout << result << " ";
    }

    // first Iterate through capital case then small case

    for (int i = 0; i < 26; i++)
    {
        if (node->bigCase[i] != NULL)
        {
            char alphabet = 'A' + i;
            if (patIndex >= pattern.length())
            {
                result.push_back(alphabet);
                search(node->bigCase[i], pattern, result, isResultFound, patIndex);
                result.pop_back();
            }
            else if (alphabet == pattern[patIndex])
            {

                ++patIndex;
                result.push_back(alphabet);
                search(node->bigCase[i], pattern, result, isResultFound, patIndex);
                result.pop_back();
            }
        }
    }

    // iterate through the smallcase
    for (int i = 0; i < 26; i++)
    {
        if (node->smallCase[i] != NULL)
        {
            result.push_back('a' + i);
            search(node->smallCase[i], pattern, result, isResultFound, patIndex);
            result.pop_back();
        }
    }
}

void findAllWords(vector<string> dict, string pattern)
{
    TrieNode *root = new TrieNode();
    for (int i = 0; i < dict.size(); i++)
    {
        insert(root, dict[i]);
    }
    string result = "";
    bool isResultFound = false;
    search(root, pattern, result, isResultFound);

    if (!isResultFound)
    {
        cout << "No match found";
    }
}

int main(int argc, char const *argv[])
{
    vector<string> dic1 = {"WelcomeGeek",
                           "WelcomeToGeeksForGeeks"
                           "GeeksForGeeks"};
    vector<string> dic = {"BaaTe", "BaTe"};
    findAllWords(dic, "BTW");
    cout << endl
         << "Program finishe !";
    return 0;
}
