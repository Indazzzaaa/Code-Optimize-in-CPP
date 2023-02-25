#include <iostream>
#include <stdlib.h>
using namespace std;

extern void printHello();
extern int age = 10;

int main(int argc, char const *argv[])
{
    // printHello();
    system("cls");
    cout << age << endl;

    return 0;
}
