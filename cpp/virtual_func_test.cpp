#include <iostream>
#include <stdlib.h>
using namespace std;

struct a
{
    a()
    {
        cout << "A ctor called" << endl;
    }

    virtual void show()
    {
        cout << "A" << endl;
    }
};

struct B : a
{
    B()
    {
        cout << "B ctor called" << endl;
    }

    void show()
    {
        cout << "B" << endl;
    }
};

struct C : B
{
    void show()
    {
        cout << "C" << endl;
    }
};

int main(int argc, char const *argv[])
{
    // a *obj = new C();
    // obj->show();
    int c = 10;
    int arr[]{1, 2};
    int *ptr = &c;
    int *&d = ptr;
    cout << *d << endl;
    d = arr;
    cout << d[1] << endl;

    return 0;
}
