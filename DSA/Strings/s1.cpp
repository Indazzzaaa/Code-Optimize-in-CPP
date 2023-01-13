#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define print(x) cout << x << endl

// this way will create copy of char array on heap
void stringPass(string passed)
{
    print(&passed);
}

// this is much better way
void stringPass2(string &passed)
{
    print(&passed);
}

int main(int argc, char const *argv[])
{

    system("cls");
    // if not used new keyword means don't use deleted and created on  stack and every string is ended with null character ='\0' or 0
    char *c = "Sumant";
    char n[6] = {'S', 'u', 'm', 'a', 'n', 't'}; // in this since not terminated by null character if we try to end this then it will print some garbage as well

    string name = "Sumant"; // no new so still on stack , and use string headerfiles to able to print this
    print(name);

    // ! one more passing string just like that will create copy char array on heap
    // * In the end how to use const before and after the pointer will create , whether we are able to touch the context of string or not.

    return 0;
}
