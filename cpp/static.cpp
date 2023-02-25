#include <iostream>
#include <stdlib.h>
using namespace std;

class a
{
    static int age;
    static string name;

public:
    static int val;
    static const int val2 = 30;

    static void printMsg()
    {
        cout << "hello world" << endl;
    }

    static void initialize()
    {
        name = "Sumant";
        cout << "Initialized name is " << name << endl;
    }

    static void initialzie2();

    static void printAge();
};

int a::val = 10;
int a::age = 200;
string a::name = "Patel";

void a::initialzie2()
{
    cout << "working fine" << endl;
}

void a::printAge()
{
    cout << "my age is : " << age << endl;
}

void fun()
{
    static int count = 0;
    cout << "Now count is : " << ++count << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << a::val2 << endl;
    a::initialzie2();
    fun();
    fun();
    fun();
    fun();
    cout << a::val << endl;
    a::printMsg();
    a::printAge();
    a::initialize();
    return 0;
}
