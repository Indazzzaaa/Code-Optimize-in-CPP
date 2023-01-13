#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    // creating 8 bytes of memory on heap
    char *buffer = new char[8];
    // use to fill the pointer with the data we have given
    memset(buffer, 0, 8);

    // this is how we create pointer to pointer
    char **ptr = &buffer;

    cin.get(); // waiting for key to press

    delete[] buffer;

    return 0;
}
