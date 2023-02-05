#include <iostream>
using namespace std;

int *arrayPass()
{
    int *arr = new int[2]{1, 2};
    return arr;
}

int main(int argc, char const *argv[])
{

    int *a = arrayPass();
    cout << a[0] << endl;
    return 0;
}
