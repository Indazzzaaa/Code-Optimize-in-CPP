#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Hero
{
};

class Zero
{

public:
    static int age;

    Zero()
    {
        cout << "This is zero default constructor but private " << endl;
    }
};

int Zero::age = 10;

class Naam
{

public:
    char firstName[100];
    char *LastName;
    Naam(char *const first, char *const last)
    {
        strcpy(this->firstName, first);
        strcpy(this->LastName, last);
    }
};