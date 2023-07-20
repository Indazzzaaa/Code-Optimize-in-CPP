#include <iostream>
using namespace std;

// Back-end complete function template for C++

class trie_element
{
public:
    trie_element *nxt[26];
    int count;
    int first_appearance;

    trie_element()
    {
        this->count = 0;
        for (int i = 0; i < 26; i++)
            this->nxt[i] = NULL;
    }
};

class Solution
{
public:
    // Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n)
    {
        string ret = "";
        int max_count = 0;
        int ret_first_appearance;

        trie_element *trie = new trie_element();

        for (int i = 0; i < n; i++)
        {
            trie_element *temp = trie;

            for (int j = 0; j < arr[i].size(); j++)
            {
                int index = arr[i][j] - 'a';
                if (temp->nxt[index] == NULL)
                    temp->nxt[index] = new trie_element();
                temp = temp->nxt[index];
            }

            // storing the count and first appearance of current word.
            temp->count++;
            if (temp->count == 1)
                temp->first_appearance = i;

            // updating the maximum count if required and if they have
            // same frequency, then storing the word whose first
            // occurrence occurs last in the array.
            if (temp->count > max_count || (temp->count == max_count &&
                                            temp->first_appearance > ret_first_appearance))
            {
                ret = arr[i];
                max_count = temp->count;
                ret_first_appearance = temp->first_appearance;
            }
        }
        // returning the most frequent word.
        return ret;
    }
};