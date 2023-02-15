#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tree.cpp"
using namespace std;

// ! method tested goes here
void findLCA_rec_Test()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    node *lcaNode = t.find_lca_rec(root, 60, 40);
    cout << "Lca found at : " << lcaNode->data << endl;
}
void findLCA_path_based_Test()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    t.findLCA_Path_Based_soln(root, 60, 70);
}
void spiralTraversalTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    t.spiralTraversal(root);
}
void tree_from_in_post_test()
{
    vector<int> in = {20, 10, 40, 30, 60, 50};
    vector<int> post = {20, 40, 60, 50, 30, 10};
    tree t;
    int currIndex = post.size() - 1;
    node *root = t.construct_tree_from_in_post_traversal(in, post, 0, in.size() - 1, currIndex);
    t.levelTraversal(root);
}
void tree_from_in_level_test()
{
    vector<int> in = {20, 10, 40, 30, 60, 50};
    vector<int> level = {10, 20, 30, 40, 50, 60};
    tree t;
    int currIndex = 0;
    node *root = t.construct_tree_from_in_level_traversal(in, level, 0, in.size() - 1, currIndex);
    t.levelTraversal(root);
}
void tree_from_in_pre_test()
{
    vector<int> in = {40, 20, 50, 10, 30, 80, 70, 90};
    vector<int> pre = {10, 20, 40, 50, 30, 70, 80, 90};
    tree t;
    int currIndex = 0;
    node *root = t.contruct_tree_from_in_pre(in, pre, 0, in.size() - 1, currIndex);
    t.levelTraversal(root);
}

void treeTODLLTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    node *prev = NULL;
    node *head = t.treeTODLL(root, prev);
    cout << "Printing converted LL ";
    t.traverseDLL(head);
    cout << endl;
}
void maxWidthTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    cout << "Width of tree is : " << t.maxWidth(root) << endl;
}
void treeBalancedCheckTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    cout << "tree is balanced " << t.checkBalanceCall(root) << endl;
}
void printViewTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    t.printLeftView(root);
    t.printRightView(root);
}
void sizeOfTreeTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    cout << "Size of tree rec : " << t.sizeOfTreeRec(root) << endl;
    cout << "Size of tree  iterative : " << t.sizeOfTreeIterative(root) << endl;
}
void nodeAtKTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    cout << "Recursive result : ";
    t.printKRec(root, 2);
    cout << endl;
    cout << "Iterative result : ";
    t.printkIter(root, 2);
    cout << "Printing in reverse order: ";
    t.printKRecReverse(root, 2);
}
void heightTest()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;

    cout << "Height of tree rec : " << t.heightRec(root) << endl;
    cout << "Height of tree iterative : " << t.heightIterative(root) << endl;
}
void preTest()
{
    vector<int> v = {10, 20, -1, -1, 30, 40, -1, -1, -1};
    tree t;
    int index = 0;
    node *root = t.PreOrderdeserialize(v, index);
    t.preTraversal(root);
}

void levlTest()
{
    vector<int> v = {10, 20, 30, -1, -1, -1, 50, -1, -1};
    tree t;
    node *root = t.LevelOrderDeserialize(v);
    t.preTraversal(root);
    cout << endl;
}
void postTest()
{
    vector<int> v = {-1, -1, 20, -1, -1, 40, -1, 30, 10};
    tree t;
    node *root = t.PostOrderDeserialize(v);
    t.preTraversal(root);
    cout << endl;
}

void testSerialize()
{

    vector<int> v = {10, 20, 30, -1, -1, -1, -1};
    tree t;
    node *root = t.LevelOrderDeserialize(v);
    t.preTraversal(root);

    cout << endl;
    cout << "Serialize data is " << t.serialize(root) << endl;
}

void testDeserialize()
{
    tree t;
    string s = "10,20,30,40,50,60,70,#,#,#,#";
    node *root = t.deserialize(s);
    t.preTraversal(root);
    cout << endl;
}