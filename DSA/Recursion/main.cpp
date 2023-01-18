#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
void decimalToBinary(int);
bool isPallindrome(string str, int l, int r);
int ropeCut(int n, int a, int b, int c);
void towerOfHanoi(int n, char a = 'a', char b = 'b', char c = 'c')
{

    if (n == 1)
    {
        cout << "Moving disc from " << a << " to " << c << endl;
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    cout << "Moving disc from " << a << " to " << c << endl;
    towerOfHanoi(n - 1, b, a, c);
}

int main(int argc, char const *argv[])
{
    system("cls");
    // cout << ropeCut(5, 5, 2, 3) << endl;
    towerOfHanoi(100);
    cin.get();

    return 0;
}

int ropeCut(int n, int a, int b, int c)
{

    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    int res = max(ropeCut(n - a, a, b, c), max(ropeCut(n - b, a, b, c), ropeCut(n - c, a, b, c)));
    if (res < 0)
        return -1;

    return res + 1;
}

bool isPallindrome(string str, int l, int r)
{

    if (l >= r)
        return true;

    return (str[l] == str[r]) && isPallindrome(str, ++l, --r);
}

void decimalToBinary(int n)
{

    if (n == 0)
    {
        cout << n;
        return;
    }

    decimalToBinary(n / 2);
    cout << n % 2;
}
