#include <iostream>
#include <stdlib.h>
using namespace std;

struct test
{

    void assignMethod(auto &methodName)
    {
        methodName = show;
    }

private:
    void show()
    {
        cout << "Showing the private method in cpp " << endl;
    }
};

void show2()
{
    cout << "This is show 2 of the method " << endl;
}

int main(int argc, char const *argv[])
{
    test obj;

    void (*m)();
    m = show2;
    m();
    void (*d)();
    obj.assignMethod(d);
    d();

    return 0;
}
