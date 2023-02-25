#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 1;
    int t = ++a + ++a + ++a + ++a;
    cout << endl
         << t;

    return 0;
}
