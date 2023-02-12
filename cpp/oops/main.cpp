#include <iostream>
#include <stdlib.h>
#include "inheritance.cpp"
using namespace std;

void singleTonTest()
{
    singleton *obj = singleton::getSingletonObject();
    singleton *obj1 = singleton::getSingletonObject();
    singleton *obj2 = singleton::getSingletonObject();
    singleton *obj3 = singleton::getSingletonObject();
    singleton *obj4 = singleton::getSingletonObject();
}

int main()
{
    system("cls");

    singleTonTest();

    cout << "Process completed !!" << endl;

    cin.get();
    return 0;
}