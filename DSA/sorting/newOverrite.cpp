#include <iostream>
using namespace std;

void *operator new(size_t size)
{

    cout << "New allocation required of size : " << size << endl
         << endl;
    return malloc(size);
}