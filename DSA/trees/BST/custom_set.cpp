#include <iostream>
#include <set>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct custom

{
    int age;
    int money;
    bool operator<(const custom &t) const
    {
        return t.age > age;
    }
};

int funTest(const int &c)
{
    cout << "your passed value is : " << c << endl;
    return c;
}

int main(int argc, char const *argv[])
{
    system("cls");
    set<custom> s;
    s.insert({10, 100});
    s.insert({20, 200});
    s.insert({50, 500});
    s.insert({40, 400});
    for_each(s.cbegin(), s.cend(), [](auto element)
             { cout << element.age
                    << " "; });
    cout << endl;
    cout << "your returned value is  : " << funTest(10);
    cin.get();

    return 0;
}
