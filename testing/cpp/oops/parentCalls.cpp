#include <iostream>
#include <stdlib.h>
using namespace std;

class p1
{
public:
    p1()
    {
        cout << "P1 non parameter called" << endl;
    }
    p1(int age)
    {
        cout << "p1 parameter is called " << endl;
    }

    void show() { cout << "show from p1" << endl; }
};

class p2 : public p1
{
public:
    p2()
    {
        cout << "P2 non parameter called " << endl;
    }

    p2(int age)
    {
        cout << "P2 parameter called" << endl;
    }

    void show()
    {
        cout << "show from the p2 class" << endl;
    }
};

class p3 : public p2
{
public:
    p3()
    {
        cout << "p3 normal constructor : " << endl;
    }

    p3(int age) : p2(age)
    {

        cout << "p3 parameter constructor is  called" << endl;
        p3();
    }

    p3(p3 &obj, int age)
    {
        cout << "copy constructor is called " << endl;
    }

    void show()
    {
        cout << "show from the p3 class" << endl;
        p2::show();
    }
};

class p4 : public p3
{
public:
    p4()
    {
        cout << "p4 constructor is called : " << endl;
    }
};

class p5
{
public:
    p5(int age)
    {
        cout << "p5 called " << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    p3 obj(10);

    return 0;
}
