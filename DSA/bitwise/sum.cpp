#include <iostream>
#include <limits.h>
using namespace std;

int getSum(int a, int b)
{

    while (b != 0)
    {
        int temp = (a & b) << 1;
        a = a ^ b;
        b = temp;
    }

    return a;
}
int reverse(int x)
{
    int max = INT_MAX;
    int min = INT_MIN;
    cout << max << endl;
    cout << min << endl;
    int res = 0;
    while (x != 0)
    {
        int d = x % 10;
        if (res > max / 10 || res < min / 10)
        {
            return 0;
        }
        else if (res == max)
        {
            if (d > max % 10)
                return 0;
        }
        else if (res == min)
        {
            if (d < max % 10)
                return 0;
        }

        res = res * 10 + d;
        x /= 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // cout << getSum(-1, 1) << endl;
    // cout << (-1 % 10) << endl;

    cout << reverse(-123);
    return 0;
}
