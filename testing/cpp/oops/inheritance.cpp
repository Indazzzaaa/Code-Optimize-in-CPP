#include <iostream>
#include <stdlib.h>
using namespace std;

class singleton
{

private:
    singleton()
    {

        cout << "Private singleton constructor called " << endl;
    }

public:
    static singleton *thisObj;
    static singleton *getSingletonObject()
    {
        if (thisObj == NULL)
        {
            cout << "No single instance there so creating new one : " << endl;
            thisObj = new singleton();
        }
        else
        {
            cout << "Singleton object already exist so reuse it : " << endl;
        }

        return thisObj;
    }
};

singleton *singleton::thisObj = NULL;

class parent1
{

private:
    int age;

public:
    parent1()
    {
        cout << "parent1 ctor " << endl;
    }
    parent1(int newAge)
    {
        this->age = newAge;
        cout << "parent1 ctor " << endl;
    }

    ~parent1()
    {
        cout << "parent1 destructor : " << endl;
    }

    void showObjAge(parent1 obj)
    {
        cout << "My Age : " << this->age << endl;
        cout << "Obj age : " << obj.age << endl;
    }
};

class parent2
{
public:
    parent2()
    {
        cout << "parent2 ctor " << endl;
    }

    ~parent2()
    {
        cout << "parent2 destructor : " << endl;
    }
};

class child : parent1, parent2
{
public:
    child()
    {
        cout << "child constructor " << endl;
    }

    ~child()
    {
        cout << "child destructor " << endl;
    }
};

void constructorAndDestructorTest()
{
    child c;
}

void privateTest()
{
    parent1 p1(10);
    parent1 p2(30);
    p1.showObjAge(p2);
}
