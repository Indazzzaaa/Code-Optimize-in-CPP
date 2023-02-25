#include <iostream>
using namespace std;

int fun(const int &a)
{
    cout << "function shows " << a << endl;
    return a;
}

int main(int argc, char const *argv[])
{
    int b = 10;
    cout << "function caller : " << fun(10) << endl;

    return 0;
}
