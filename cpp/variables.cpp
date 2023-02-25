#include <iostream>
#include <stdlib.h>
using namespace std;
/*
bool -> char -> short int -> int ->

unsigned int -> long -> unsigned ->

long long -> float -> double -> long double

 */
int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process started]\n\n";
    int a = 10;
    long long l = 10;
    float b = 20.0f;
    a = b;
    a = l;
    cout << a << endl;

    cout << "\n\n[Process Ended]\n\n";

    return 0;
}
