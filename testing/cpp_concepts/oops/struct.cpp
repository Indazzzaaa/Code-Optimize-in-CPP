#include <iostream>
#include <stdlib.h>
using namespace std;

struct intVector3
{
    int x, y, z;
    intVector3(int x1, int y1, int z1)
    {
        cout << "Constructor is called " << endl;
        x = x1;
        y = y1;
        z = z1;
    }

    ~intVector3()
    {
        cout << "Destroying the invector3 " << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");

    intVector3 c1(10, 20, 30);
    intVector3 c2{10, 20, 30};

    return 0;
}
