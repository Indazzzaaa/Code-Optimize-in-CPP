#include <iostream>
using namespace std;

struct test
{
    test()
    {
        cout << "Ctor called" << endl;
    }

    test(test &obj)
    {
        cout << "copy called" << endl;
    }

    test &operator=(test &obj)
    {
        cout << "Assignment called " << endl;
        return *this;
    }

    void operator()()
    {
        cout << "Brackets are called " << endl;
    }
};

void fun(test obj)
{

    return;
}

test &fun2()
{
    test obj;
    return obj;
}

int main(int argc, char const *argv[])
{
    system("cls");
    test obj;
    test obj2 = obj;
    fun(obj2);
    auto obj3(fun2());
    obj = obj2;
    obj();

    return 0;
}
