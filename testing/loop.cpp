#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int i = 0,

        j = 10;
    while (j-- > i++)
    {
        cout << "i,j : " << i << "," << j << endl;
    }
    return 0;
}
