#include <iostream>
#include <stdlib.h>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

#define show(msg, x) cout << msg << x << endl;

void print(auto container)
{

    for_each(container.begin(), container.end(), [](auto element)
             { cout << element << " "; });
    cout << endl;
}

void vectorTest()
{

    vector<int> v(10);
    v.reserve(10);
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    print(v);
    show("Size : ", v.capacity());

    for (int i = 0; i < 10; i++)
    {
        v.pop_back();
        show("Size at " + i, v.capacity());
    }
}

void stackTest()
{

    stack<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }
    // print(s);
    show("Size : ", s.size());
    // * only way to iterate over the stack container is
    while (s.size() > 0)
    {
        show("value : ", s.top());
        s.pop();
    }
    show("Size : ", s.size());
    show("Empty Test : ", s.empty());
}

void testList()
{

    list<int> l;
    auto lambda1 = [&](int element)
    { l.push_back(element); };
    // auto lambda2 = [l](int element)
    // { l.push_back(element); };

    for (int i = 0; i < 10; i++)
    {
        lambda1(rand() % 10);
    }
    print(l);
    l.sort();
    print(l);
    show("Size of list : ", l.size());
}

int main(int argc, char const *argv[])
{
    system("cls");
    // vectorTest();
    // stackTest();
    // testList();

    cin.get();
    return 0;
}
