#include <iostream>
#include <vector>

using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Dictionary
{
public:
    TrieNode *root;
    Dictionary()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (curr->children[index] == NULL)
            {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    void showDictionary(TrieNode *node, string word = "")
    {
        if (node == NULL)
            return;

        if (node->isEndOfWord == true)
        {
            cout << word << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                word.push_back((char)(i + 'a'));
                showDictionary(node->children[i], word);
                word.pop_back();
            }
        }
    }

    bool search(TrieNode *root, string word)
    {
        if (root == NULL)
            return false;
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++)
        {

            int index = word[i] - 'a';
            if (curr->children[index] == NULL)
            {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    void prefixSearchPrint(TrieNode *root, string prefix, int index = 0, string result = "")
    {
        if (root == NULL)
            return;

        TrieNode *curr = root;

        for (; index < prefix.length(); index++)
        {
            int pos = prefix[index] - 'a';
            if (curr->children[pos] == NULL)
                return;

            result.push_back(prefix[index]);
            curr = curr->children[pos];
        }
        // first time also helps in checking whether prefix itself a word.
        // and forward all the words having prefix
        if (curr->isEndOfWord)
        {
            cout << result << endl;
        }

        if (index == prefix.length())
        {
            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] == NULL)
                    continue;
                result.push_back((char)(i + 'a'));
                prefixSearchPrint(curr->children[i], prefix, index, result);
                result.pop_back();
            }
        }
    }

    TrieNode *deleteWord(TrieNode *root, string word, int index = 0)
    {
        if (root == NULL)
            return NULL;

        if (index == word.length())
        {
            root->isEndOfWord = false;
            if (isThereNoOthers(root))
            {
                delete root;
                root = NULL;
            }
            return root;
        }

        int pos = word[index] - 'a';

        root->children[pos] = deleteWord(root->children[pos], word, ++index);
        if (isThereNoOthers(root) && root->isEndOfWord == false)
        {
            // we are tying to save the root node so there is atleast one point to insert again
            if (index == 0)
            {
                root->children[pos] = NULL;
                return root;
            }
            delete root;
            root = NULL;
        }
        return root;
    }

private:
    bool isThereNoOthers(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Dictionary d;
    d.insert("hello");
    d.insert("world");
    d.insert("how");
    d.insert("are");
    d.insert("you");
    d.insert("your");
    d.insert("yours");
    d.showDictionary(d.root);
    cout << "is Bat there : " << d.search(d.root, "bat") << endl;
    d.deleteWord(d.root, "ho");
    cout << "is how there : " << d.search(d.root, "how") << endl;
    cout << "is you there : " << d.search(d.root, "you") << endl;
    cout << "is hows there : " << d.search(d.root, "hows") << endl;
    cout << "==========================================" << endl;
    // d.showDictionary(d.root);
    cout << "Prefix search Result " << endl;
    d.prefixSearchPrint(d.root, "your");
    cout << "Program Finished !" << endl;

    return 0;
}
