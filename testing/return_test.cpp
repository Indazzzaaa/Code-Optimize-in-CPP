#include <iostream>
#include <stdlib.h>
using namespace std;

struct vec
{
    int a, b;
};

vec fun()
{
    vec obj{10, 20};

    return obj;
}

int main(int argc, char const *argv[])
{
    vec b = fun();
    cout << b.a << " " << b.b << endl;

    return 0;
}
