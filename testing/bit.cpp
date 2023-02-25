#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = -10;
    b = b << 31;
    a >>= 10;
    char c = -12;
    cout << bitset<32>(a) << endl;
    cout << bitset<32>(b) << endl;
    cout << c << endl;
    return 0;
}
