#include <iostream>
#include <stdlib.h>
using namespace std;

struct s
{
    int age = 10, c = 20;
    /* int getAge()
    {
        cout << "non const one called " << endl;
    } */

      int getAge() const
    {
        cout << "const one is called  " << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    const s obj;
    obj.getAge();

    return 0;
}
