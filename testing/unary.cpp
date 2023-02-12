#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    int a = 1;
    int t = ++a + a++ + ++a + a++;
    cout << t << endl;
    cin.get();

    return 0;
}
