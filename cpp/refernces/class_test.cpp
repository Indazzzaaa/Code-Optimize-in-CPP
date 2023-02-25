#include <iostream>
#include <stdalign.h>
using namespace std;
class test
{

    int age;
    const int see;
    mutable int show;

public:
    test() : see(20)
    {
        this->age = 10;
        // this->see = 20;
    }

    void printFun()
    {
        cout << "Hey this is fun " << endl;
    }

    void printFun() const
    {
        cout << "Hey this is fun const " << endl;
    }
    void showFun() const
    {
        show = 300;
        // age = 400;
        this->printFun();
        cout << "Showing the fun : " << endl;
    }
};

int main(int argc, char const *argv[])
{
    test obj;
    obj.printFun();
    obj.showFun();

    cout << "____________ANOTHER TEST__________________________" << endl;
    const test obj2;
    obj2.printFun();

    return 0;
}
