#include <iostream>
using namespace std;

struct test2
{
    test2()
    {
        cout << "test2 ran " << endl;
    }
};

struct test
{
    int a;

    test(int tem, int name)
    {
        cout << "parameter one ran" << endl;
    }
};

int main(int argc, char const *argv[])
{
    string name = "sumant";
    test arr[2](10, 20);
    return 0;
}
