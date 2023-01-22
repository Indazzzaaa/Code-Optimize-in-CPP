#include <iostream>
#include <stdlib.h>
using namespace std;

class A
{
public:
    void display()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    void display()
    {
        cout << "B" << endl;
    }
};
class C : public B
{
};

int main(int argc, char const *argv[])
{
    system("cls");
    A *aptr;
    A obj = B();
    C obj2 = C();
    aptr = &obj;
    obj.display();
    obj.display();
    aptr->display();
    obj2.display();
    return 0;
}
