#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tree.cpp"
using namespace std;

pair<tree, node *> initializeTree()
{
    tree t;
    string s = "10,20,#,40,#,#,#";

    node *root = t.deserialize(s);
    t.levelTraversal(root);
    cout << endl;

    pair<tree, node *> p;
    p.first = t;
    p.second = root;
    return p;
}

void iterative_inorder_Test()
{
    auto p = initializeTree();
    node *root = p.second;
    tree t = p.first;
    t.iterative_inorder(root);
    cout << endl;
    t.iterative_preorder(root);
    cout << endl;
    t.iterative_postOrder(root);
    cout << endl;
}

int main(int argc, char const *argv[])
{

    system("cls");
    cout << "[Process Started]\n\n";
    iterative_inorder_Test();
    cout << "\n[Process completed] " << endl;
    cin.get();
    return 0;
}
