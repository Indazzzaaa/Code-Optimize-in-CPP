#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    system("CLS");
    int age;
    cout << "Enter your age : ";
    cin >> age;
    switch (age)
    {
    case 10:
        cout << "We know ur age is 10";
    case 20:
        cout << "we know ur age is 20";
        break;
    case 30:
        cout << "We know ur age is 30";

    default:
        break;
    }
    return 0;
}
