#include <iostream>
using namespace std;

class Test
{

    int age = 10;
    string name = "sumant";
    void printAnyThing();

public:
    void printVar();
};

void Test::printVar()
{
    cout << this->age << " " << this->name << endl;
    printAnyThing();
}

void Test::printAnyThing()
{
    cout << "Anything is printed" << endl;
}

int main(int argc, char const *argv[])
{
    Test s1;
    s1.printVar();
    return 0;
}
