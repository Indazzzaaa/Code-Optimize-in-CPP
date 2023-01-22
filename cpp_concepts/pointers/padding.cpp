#include <iostream>
#include <stdlib.h>
using namespace std;

struct a
{

    int x;
    char y;
    char z;
};

struct b
{
    char x;
    int y;
    char z;
};

int main(int argc, char const *argv[])
{
    system("cls");
    a apad;
    b bpad;
    cout << sizeof(apad) << "\t" << sizeof(bpad) << endl;
    return 0;
}
