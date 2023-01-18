#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <limits.h>
using namespace std;

void printBit();
void checkKthBit(int, int);

int main(int argc, char const *argv[])
{
    system("cls");
    // checkKthBit(4, 0);
    // printBit();
    int a = INT_MAX;
    cout << bitset<32>(a) << endl;
    cout << bitset<32>(a << 1) << endl;
    cout << bitset<32>(a) << endl;

    cin.get();

    return 0;
}

void printBit()
{

    cout << "Bitwise operator started .. " << endl;
    int a = -1;
    cout << "Before : " << bitset<32>(~a) << endl;
    cout << "After : " << bitset<32>(a << 1) << endl;
}

void checkKthBit(int num, int k)
{

    if ((1 << (k)&num) > 0)
    {
        cout << "Yes this is on" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
