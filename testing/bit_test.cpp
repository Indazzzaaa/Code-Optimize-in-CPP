#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <limits.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = INT_MIN;
    cout << "Before manipulation " << bitset<32>(a) << endl;
    a -= 1;
    cout << "After manipulation : " << bitset<32>(a) << endl;

    return 0;
}
