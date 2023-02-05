#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void test1()
{
    // char *c = "Sumant";
    string name = "sumant";
    string name2 = name; //! this will create the seprate copy of the string
    name2[0] = 'c';
    // cout << name << endl;
    for (char c : name)
        cout << c << "\t";
    cout << endl;
    name += " Patel";
    for_each(name.begin(), name.end(), [](char c)
             { cout << c << " "; });
    cout << endl;
    name.clear();
    cout << "Length of string is : " << name.length() << endl;
    cout << "capacity of string is : " << name.capacity()
         << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    test1();

    cin.get();

    return 0;
}
