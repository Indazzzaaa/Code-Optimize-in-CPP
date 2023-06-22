#include <iostream>
using namespace std;

void fun()
{
    cout << "This is fun 1" << endl;
}

void fun()
{
    cout << "This is fun 2" << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Process completed" << endl;

    return 0;
}
