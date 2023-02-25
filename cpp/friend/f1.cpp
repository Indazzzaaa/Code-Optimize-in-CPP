#include <iostream>
using namespace std;

struct test2
{
private:
    void fun2()
    {
        cout << "fun from test 2";
    }

    friend void show(test &);
};

struct test
{
private:
    test2 obj2;
    void fun()
    {
        cout << "test fun" << endl;
    }
    friend void show(test &obj);
};

void show(test &obj)
{
    obj.fun();
    obj.obj2.fun2();
}

int main(int argc, char const *argv[])
{
    test obj;
    show(obj);
    return 0;
}
