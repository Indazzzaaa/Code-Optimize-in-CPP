#include <iostream>
#include <stdlib.h>
#include "node.cpp"
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

struct tree
{

    void preTraversal(node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << "  ";
        preTraversal(root->left);
        preTraversal(root->right);
    }
    void levelTraversal(node *root)
    {
        if (root == NULL)
            return;
        cout << "Level order traversal : ";
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            auto curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << endl;
    }

    node *PreOrderdeserialize(vector<int> &v, int &index)
    {
        if (v[index] == -1)
        {
            return NULL;
        }
        node *root = new node(v[index]);
        root->left = PreOrderdeserialize(v, ++index);
        root->right = PreOrderdeserialize(v, ++index);
        return root;
    }

    node *LevelOrderDeserialize(vector<int> &v)
    {
        stack<node *> s;
        int index = 0;
        node *root = new node(v[0]);
        s.push(root);

        while (!s.empty())
        {
            node *curr = s.top();
            s.pop();
            node *left = (v[++index] != -1) ? new node(v[index]) : NULL;
            node *right = (v[++index] != -1) ? new node(v[index]) : NULL;
            if (right != NULL)
            {
                curr->right = right;
                s.push(right);
            }
            if (left != NULL)
            {
                curr->left = left;
                s.push(left);
            }
        }

        return root;
    }

    node *PostOrderDeserialize(vector<int> &v)
    {

        //  left,root,right;
        //  put first two in the stack
        // now third will be root
        // and if -1 encounters put null in the stack and only pop from stack when we encounter number other then -1
        stack<node *> s;
        int index = 0;
        for (int i = 0; i < 2; i++)
        {
            if (v[i] == -1)
            {
                s.push(NULL);
                index++;
            }
            else
            {
                s.push(new node(v[i]));
                index++;
            }
        }

        while (index < v.size())
        {
            if (v[index] == -1)
            {
                s.push(NULL);
            }
            else
            {
                node *root = new node(v[index]);
                index++;
                root->right = s.top();
                s.pop();
                root->left = s.top();
                s.pop();
                s.push(root);
            }
        }

        return s.top();
    }

    // * level order serialize and deserialize using string only
    string serialize(node *root)
    {
        stringstream res;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {

            node *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                res << "#"
                    << ",";

                // res.putback(s.str());
                continue;
            }
            res << curr->data << ",";
            // res.putback(s.str());
            q.push(curr->left);
            q.push(curr->right);
        }

        string s = res.str();
        s.pop_back();
        return s;
    }

    node *deserialize(string s)
    {
        if (s == "")
            return NULL;

        stringstream ss(s);
        string val;
        queue<node *> q;
        getline(ss, val, ',');
        node *root = new node(stoi(val));
        q.push(root);
        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();
            getline(ss, val, ',');
            if (val == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new node(stoi(val));
                q.push(curr->left);
            }

            getline(ss, val, ',');
            if (val == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new node(stoi(val));
                q.push(curr->right);
            }
        }

        return root;
    }

    int heightRec(node *root)
    {
        // ! if want to do iterative , think from level order traversal
        if (root == NULL)
        {
            return 0;
        }
        return max(heightRec(root->left), heightRec(root->right)) + 1;
    }

    int heightIterative(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        queue<node *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            res++;
        }

        return res;
    }

    void printKRec(node *root, int k)
    {
        if (root == NULL)
            return;
        if (k == 0)
        {
            cout << root->data << " ";
            return;
        }

        printKRec(root->left, k - 1);
        printKRec(root->right, k - 1);
    }

    void printkIter(node *root, int k)
    {
        if (root == NULL)
            return;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();

                if (k == 0)
                {
                    cout << curr->data << " ";
                }
                q.pop();
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            k--;
        }
        cout << endl;
    }

    void printKRecReverse(node *root, int k)
    {
        if (root == NULL)
            return;
        if (k == 0)
        {
            cout << root->data << " ";
            return;
        }
        printKRec(root->right, k - 1);
        printKRec(root->left, k - 1);
    }

    int sizeOfTreeRec(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + sizeOfTreeRec(root->left) + sizeOfTreeRec(root->right);
    }

    int sizeOfTreeIterative(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        queue<node *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            res++;
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }

        return res;
    }

    void printLeftView(node *root)
    {
        if (root == NULL)
            return;
        queue<node *> q;

        q.push(root);
        cout << "Printing Left view : ";
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                if (i == 0)
                {
                    cout << curr->data << " ";
                }
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }

        cout << endl;
    }

    void printRightView(node *root)
    {
        if (root == NULL)
            return;
        queue<node *> q;

        q.push(root);
        cout << "Printing Right view : ";
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                if (i == size - 1)
                {
                    cout << curr->data << " ";
                }
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }

        cout << endl;
    }

    bool checkBalanceCall(node *root)
    {
        return !(checkForBalanced(root) == -1);
    }

    int maxWidth(node *root)
    {
        if (root == NULL)
            return 0;
        queue<node *> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            res = max(res, size);
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }

                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return res;
    }

    node *treeTODLL(node *root, node *&prev)
    {
        if (root == NULL)
        {
            return root;
        }
        node *head = treeTODLL(root->left, prev);
        if (prev == NULL)
        {
            head = root;
            head->left = prev;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        treeTODLL(root->right, prev);
        return head;
    }

    void traverseDLL(node *root)
    {
        while (root != NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
    }

    int diameter(node *root, int &dia)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = diameter(root->left, dia);
        int rh = diameter(root->right, dia);
        dia = max(dia, (lh + rh + 1));
        return max(lh, rh) + 1;
    }

    // !we can optimize searching using hash
    node *contruct_tree_from_in_pre(vector<int> &in, vector<int> &pre, int start, int end, int &preIndex)
    {
        if (start > end)
        {
            return NULL;
        }
        node *root = new node(pre[preIndex++]);
        int index = 0;
        for (int i = start; i <= end; i++)
        {
            if (root->data == in[i])
            {
                index = i;
                break;
            }
        }
        root->left = contruct_tree_from_in_pre(in, pre, start, index - 1, preIndex);
        root->right = contruct_tree_from_in_pre(in, pre, index + 1, end, preIndex);
        return root;
    }

    // ! just do the same as preorder just in reverse order
    node *construct_tree_from_in_post_traversal(vector<int> &in, vector<int> &post, int start, int end, int &postIndex)
    {
        if (start > end)
        {
            return NULL;
        }
        node *root = new node(post[postIndex--]);
        int foundIndex = 0;
        for (int i = start; i <= end; i++)
        {
            if (root->data == in[i])
            {
                foundIndex = i;
                break;
            }
        }

        // ! just this will change first do for right then left
        root->right = construct_tree_from_in_post_traversal(in, post, foundIndex + 1, end, postIndex);
        root->left = construct_tree_from_in_post_traversal(in, post, start, foundIndex - 1, postIndex);
        return root;
    }

    void spiralTraversal(node *root)
    {
        if (root == NULL)
        {
            cout << "Your tree was empty  ";
            return;
        }
        stack<node *> s1, s2;
        s1.push(root);
        cout << "Spiral Traversal : ";
        while (!s1.empty() || !s2.empty())
        {
            while (!s1.empty())
            {
                node *curr = s1.top();
                s1.pop();
                cout << curr->data << "  ";
                if (curr->left != NULL)
                    s2.push(curr->left);
                if (curr->right != NULL)
                    s2.push(curr->right);
            }

            while (!s2.empty())
            {
                node *curr = s2.top();
                s2.pop();
                cout << curr->data << "  ";
                if (curr->right != NULL)
                    s1.push(curr->right);
                if (curr->left != NULL)
                    s1.push(curr->left);
            }
        }
        cout << endl;
    }

    // Lowest common ancestor

    void findLCA_Path_Based_soln(node *root, int n1, int n2)
    {
        // if any of n1 | n2 does not exist then there path array size will 0
        vector<int> p1;
        vector<int> p2;
        if (!findPath(root, n1, p1) || !findPath(root, n2, p2))
        {
            cout << "No path exist any one of them so returning : " << endl;
            return;
        }
        cout << "printing the path of " << n1 << " :  ";
        for_each(p1.begin(), p1.end(), [](int element)
                 { cout << element << " "; });
        cout << endl;

        cout << "printing the path of " << n2 << " :  ";
        for_each(p2.begin(), p2.end(), [](int element)
                 { cout << element << " "; });
        cout << endl;

        int i = 0;
        int j = 0;
        int pastCommonIndex = -1;
        while (i < p1.size() && j < p2.size())
        {
            if (p1[i] != p2[j])
            {
                break;
            }
            pastCommonIndex = i;
            i++;
            j++;
        }
        if (i == -1)
        {
            cout << "No lowest common ancestor found : " << endl;
        }
        else
        {
            cout << "Lowest common ancestor found is  : " << p1[pastCommonIndex] << endl;
        }
    }

    // ! only works if we are sure that both the nodes lies inside the tree
    node *find_lca_rec(node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        // ! out current node itset is data and lca as well
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        auto lca1 = find_lca_rec(root->left, n1, n2);
        auto lca2 = find_lca_rec(root->right, n1, n2);
        if (lca1 != NULL && lca2 != NULL)
        {
            // * this is the case one on left and other on right
            return root;
        }
        if (lca1 != NULL)
        {
            return lca1;
        }
        else
        {
            return lca2;
        }
    }

    //  iterative traversals
    void iterative_inorder(node *root)
    {
        if (root == NULL)
            return;

        cout << "Iterative inorder traversal is : ";
        stack<node *> st;
        node *curr = root;
        while (!st.empty() || curr != NULL)
        {

            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void iterative_preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        stack<node *> st;
        node *curr = root;
        cout << "Iterative preorder traversal : ";
        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                cout << curr->data << " ";
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
    }

    void iterative_postOrder(node *root)
    {

        // go left left and put in stack
        //  if null found go right and then left left
        //  if null found start popping
        if (root == NULL)
        {
            return;
        }
        stack<node *> st;
        node *curr = root;

        cout << "Iterative post order traversal ";
        while (!st.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                node *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                    while (!st.empty() && st.top()->right == temp)
                    {
                        temp = st.top();
                        cout << temp->data << " ";
                        st.pop();
                        temp = st.top();
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
    }

    

private:
    bool findPath(node *root, int n, vector<int> &path)
    {
        if (root == NULL)
            return false;
        path.push_back(root->data);
        if (root->data == n)
        {
            return true;
        }
        // * I like this optimizaiton think why(hint: shortcircuit operator)
        if (findPath(root->left, n, path) || findPath(root->right, n, path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    int checkForBalanced(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = checkForBalanced(root->left);
        // using -1 as an symbol of not balanced found at bottom
        if (lh == -1)
            return -1;

        int rh = checkForBalanced(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
        {
            return -1;
        }

        return max(lh, rh) + 1;
    }
};
