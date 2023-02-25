#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 1 << 31;
    cout << bitset<32>(a) << endl;

    return 0;
}
