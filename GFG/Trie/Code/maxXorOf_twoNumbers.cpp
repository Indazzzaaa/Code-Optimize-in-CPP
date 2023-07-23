#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode *children[2];
    TrieNode()
    {
        children[0] = NULL;
        children[1] = NULL;
    }
};

void buildTree(TrieNode *root, vector<int> &numbers)
{

    for (int i = 0; i < numbers.size(); i++)
    {
        TrieNode *curr = root;
        int number = numbers[i];
        // We are starting from MSB and construction tree in that way
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (number >> i) & 1;
            if (curr->children[bit] == NULL)
            {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    cout << "Tree has been created !!" << endl;
}

int findXOR(TrieNode *root, vector<int> &numbers)
{
    int res = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int number = numbers[i];
        int curr_res = 0;
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            // if that bit is 1 then we'll go for 0 , then only we can have xor max
            int bit = (number >> i & 1);
            if (curr->children[bit ? 0 : 1] != NULL)
            {
                curr_res <<= 1;
                curr_res = curr_res | 1;
                curr = curr->children[bit ? 0 : 1];
            }
            else
            {
                curr_res <<= 1;
                curr = curr->children[bit];
            }
        }

        res = max(res, curr_res);
    }

    return res;
}

// * Time complexity : O(N) where N is size of array
// * Memory complexity : O(N)

int main(int argc, char const *argv[])
{

    TrieNode *root = new TrieNode();
    vector<int> numbers = {10, 3, 5, 4};
    buildTree(root, numbers);
    int result = findXOR(root, numbers);
    cout << "Max Xor of two numbers are : " << result;

    return 0;
}
