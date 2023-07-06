#include <iostream>
using namespace std;

void doSomething(int &parent)
{
    if (parent == 10)
        return;

    parent = ++parent;
    doSomething(parent);
    cout << " Parent value and parent address : "
         << "( " << parent << ", " << &parent << ")" << endl;
}

int main(int argc, char const *argv[])
{
    int parent = 1;
    doSomething(parent);

    return 0;
}
