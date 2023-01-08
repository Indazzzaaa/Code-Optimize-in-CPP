#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{

    system("cls");
    int a = 10;
    int *b = &a;
    int **c = &b;

    cout << **c;

    return 0;
}
