#include <iostream>
#include <stdlib.h>
using namespace std;
void fun(long i)
{
    cout << "long one " << endl;
}
void fun(int i)
{
    cout << "Int one " << endl;
}

void fun(float i)
{
    cout << "Float one " << endl;
}

int main(int argc, char const *argv[])
{
    fun(10l);
    return 0;
}
