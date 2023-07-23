/*
Logic is simple just maintian the prefixXOR array(we did using trie in last)
1. for current element first find it's prefixXOR ,and store it
2. Then search for the maximum prefix we can get with that prefixXOR . From that we will get value after xoring which will give us the max
Time : O(n)

 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct TrieNode
{
    int value;
    TrieNode *children[2];
    TrieNode()
    {
        value = 0;
        children[0] = NULL;
        children[1] = NULL;
    }
};

void insert(TrieNode *root, int prefixXOR)
{

    TrieNode *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        bool bitVal = (prefixXOR >> i) & 1;
        if (curr->children[bitVal] == NULL)
        {
            curr->children[bitVal] = new TrieNode();
        }
        curr = curr->children[bitVal];
    }

    curr->value = prefixXOR;
}

int query(TrieNode *root, int prefixXOR)
{
    TrieNode *curr = root;
    for (int i = 31; i >= 0; i--)
    {
        bool bitVal = (prefixXOR >> i) & 1;
        if (curr->children[1 - bitVal] != NULL)
        {
            curr = curr->children[1 - bitVal];
        }
        else
        {
            curr = curr->children[bitVal];
        }
    }

    return prefixXOR ^ curr->value;
}

int maxSubarrayXOR(int n, int a[])
{
    TrieNode *root = new TrieNode();

    int ans = INT_MIN, px = 0;
    for (int i = 0; i < n; i++)
    {
        px = a[i] ^ px;
        insert(root, px); // O(1)
        ans = max(ans, query(root, px)); // O(1)
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max sum is : " << maxSubarrayXOR(n, arr) << endl;

    return 0;
}
