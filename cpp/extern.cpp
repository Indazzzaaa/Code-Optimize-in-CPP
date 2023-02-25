#include <iostream>
#include <iostream>
using namespace std;

// only declares it do not assign the value or allocates the memory
extern int a;
// now the memory has been allocated.
int a = 10;
int c;

int main(int argc, char const *argv[])
{

    register int b = 20;
    cout << &b << endl;
    cout << a << endl;
    cout << c << endl;

    return 0;
}
