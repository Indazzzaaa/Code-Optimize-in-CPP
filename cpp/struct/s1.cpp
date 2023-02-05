#include <iostream>
#include <stdlib.h>
using namespace std;

struct point
{
    int x = 0, y = 0;
    int buffer[5] = {1, 2, 3, 4, 5};
    point(int xTemp, int yTemp)
    {
        this->x = xTemp;
        this->y = yTemp;
        cout << "Point constructor called " << endl;
    }

    ~point()
    {
        cout << "Destructor is callecd  " << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    point p1(10, 20);
    point p2 = p1; // copying the variable of  p1 to p2
    p2.x = 100;
    p2.buffer[0] = 200;
    cout << p1.x << "  " << p1.y << "  " << p1.buffer[0] << endl;
    cout << p2.x << "  " << p2.y << "  " << p2.buffer[0] << endl;
    cin.get();

    return 0;
}
