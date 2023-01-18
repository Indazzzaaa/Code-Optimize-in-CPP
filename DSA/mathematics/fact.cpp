#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define print(x) cout << x << endl;
void fact(int);
void loopTest();
void digits(int);

int main(int argc, char const *argv[])
{
    system("cls");
    // digits(42);
    fact(42);

    cin.get();
    return 0;
}

void fact(int n)
{
    long long result = n;
    while (--n > 0)
    {
        result *= n;
    }

    cout << "Factorial is : " << result << endl;
}

void loopTest()
{
    int n(10);
    while (n-- > 0)
    {
        cout << n << endl;
    }
}

void digits(int n)
{
    long long result = n;
    while (--n > 0)
    {
        result *= n;
    }
    print(result);
    print(log10(result) + 1);
}