#include <iostream>
using namespace std;

int x = 32; // this  can be written "extern int x =32"
extern int y = 24;
int c;

void staticTest()
{
    static int calls = 0;
    calls++;
    cout << "I called : " << calls << endl;
}

int main(int argc, char const *argv[])
{
    // this is static variable test
    for (int i = 0; i < 5; i++)
    {
        staticTest();
    }
    // this is extern test(or we can say global variable test)
    cout << ++x << endl;
    cout << ++y << endl;
    cout << c;

    return 0;
}
