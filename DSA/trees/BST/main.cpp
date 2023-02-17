#include <iostream>
#include <stdlib.h>
#include <vector>
#include "bst.cpp"
#include <set>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;

pair<bst, node *> initializeTree()
{
    bst t;
    string s = "10,20,30,5,15,#,#";

    node *root = t.deserialize(s);
    t.levelTraversal(root);
    cout << endl;

    pair<bst, node *> p;
    p.first = t;
    p.second = root;
    return p;
}

void print_bottom_view()
{
    auto p = initializeTree();
    node *root = p.second;
    bst t = p.first;
    map<int, int> m;
    cout << "size of map before traversal : " << m.size() << endl;
    t.bottomView(root, m);
    cout << "size of map after traversal : " << m.size() << endl;
    for_each(m.begin(), m.end(), [&](auto element)
             { cout << "Key : " << element.first << "  value : " << element.second << endl; });
}

int main(int argc, char const *argv[])
{
    system("cls");

    cout << "[Process Started]\n\n";
    print_bottom_view();
    cout << "\n[Process completed] " << endl;
    cin.get();
    return 0;
}
