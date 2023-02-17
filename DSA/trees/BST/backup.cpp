#include <iostream>
#include <stdlib.h>
#include <vector>
#include "bst.cpp"
#include <set>
#include <algorithm>
using namespace std;

pair<bst, node *> initializeTree()
{
    bst t;
    string s = "10,5,15,#,#,12,18,#,#,#,#";

    node *root = t.deserialize(s);
    t.levelTraversal(root);
    cout << endl;

    pair<bst, node *> p;
    p.first = t;
    p.second = root;
    return p;
}
// ! copy here
void print_top_view()
{

    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    map<int, int> m;
    cout << "size of map before traversal : " << m.size() << endl;
    t.topView(root, m);
    cout << "size of map after traversal : " << m.size() << endl;
    for_each(m.begin(), m.end(), [&](auto element)
             { cout << "Key : " << element.first << "  value : " << element.second << endl; });
}
void verticalTraversal_test()
{

    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    map<int, vector<int>> m;
    cout << "size of map before traversal : " << m.size() << endl;
    t.verticalTraversal(root, m);
    cout << "size of map after traversal : " << m.size() << endl;
    for_each(m.begin(), m.end(), [&](auto element)
             {
                 cout << "Key : " << element.first << endl;
                 ;
                 cout << "value : ";
                 for_each(m[element.first].begin(), m[element.first].end(), [](auto num)
                          { cout << num << " "; });
                 cout << endl; });
}
void verticalSum_test()
{
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    map<int, int> m;
    t.verticalSum(root, m, 0);
    for_each(m.cbegin(), m.cend(), [](pair<int, int> element)
             { cout << "key : " << element.first << "  sum : " << element.second << endl; });
}
void balanceBST_test()
{
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    int pre = INT_MIN;
    //  ! if this return < 0 then it is not balanced bst
    if (t.isbalancedBST(root, pre) < 0)
    {
        cout << "Your binary tree is not balanced :  " << endl;
    }
    else
    {

        cout << "your binary tree is balanced " << endl;
    }
}
void setTest()
{
    set<int, greater<int>> s = {1, 2, 3, 4, 6, 7};
    s.insert(100);
    cout << "lower bound test : " << *(s.lower_bound(5)) << endl;
    cout << "upper bound test : " << *(s.upper_bound(5)) << endl;
    /*  for_each(s.cbegin(), s.cend(), [](int element)
              { cout << element << " "; });
     cout << endl;
     cout << "Size of set is : " << s.size() << endl; */
}
void ceil_test()
{
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    cout << "Ceil of 12 is : " << t.ceil(root, 12) << endl;
    cout << "floor of 12 is : " << t.floor(root, 12) << endl;
}

void ceil_floor_test()
{
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    cout << "Ceil of 12 is : " << t.ceil(root, 12) << endl;
    cout << "floor of 12 is : " << t.floor(root, 12) << endl;
}

void insert_delete_Test()
{
    cout << "Tree before insertion : " << endl;
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    cout << "Tree after insertion : " << endl;
    root = t.insertIterative(root, 20);
    root = t.insertRec(root, 2);
    t.levelTraversal(root);
    cout << "Tree after deleion : " << endl;
    root = t.delete_in_BST(root, 10);
    t.levelTraversal(root);
}

void searchTest()
{
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    cout << "Recursive sreach : " << t.searchRec(root, 13) << endl;
    cout << "iterative sreach : " << t.searchRec(root, 13) << endl;
}
