// A program with virtual destructor
#include <iostream>

using namespace std;

class base
{
public:
    base()
    {
        cout << "Constructing base\n";
    }
    virtual ~base()
    {
        cout << "Destructing base\n";
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "Constructing derived\n";
    }
    // ! it will work without virtual but when someone drives this one will cause the problem
    virtual ~derived()
    {
        cout << "Destructing derived\n";
    }
};

class derived2 : public derived
{
public:
    derived2()
    {
        cout << "Constructing derived2\n";
    }
    // ! it will work without virtual but when someone drives this one will cause the problem
   virtual ~derived2()
    {
        cout << "Destructing derived2\n";
    }
};

int main()
{
    derived2 *d = new derived2();
    base *b = d;
    delete b;
    getchar();
    return 0;
}
