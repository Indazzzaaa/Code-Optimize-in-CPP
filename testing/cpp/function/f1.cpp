#include <iostream>
#include <stdlib.h>
using namespace std;

void lambda1()
{
    int (*sq)(int) = [](int a)
    {
        return a * a;
    };
    cout << sq(5) << endl;
}

void confuse(int a, int b = 10)
{
    cout << "Only confusing" << endl;
}

void confuse(int a)
{
    cout << "Only confusing" << endl;
}

void confuse(float a)
{
    cout << "Only confusing float" << endl;
}

void confuse(double a)
{
    cout << "Only confusing double" << endl;
}
void confuse(long double a)
{
    cout << "Only confusing long double" << endl;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    float b = 20.0;
    // confuse(a);
    confuse(b);
    confuse(12.0);
    confuse(12.0f);
    confuse(12.0l);

    return 0;
}
