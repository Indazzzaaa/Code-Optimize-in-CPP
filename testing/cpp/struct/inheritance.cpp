#include <iostream>
#include <stdlib.h>
using namespace std;

struct point1d
{
    int x;
    point1d()
    {
        cout << "Point1d called : " << endl;
    }

    ~point1d()
    {
        cout << "Point1d destructor is called : " << endl;
    }
};

struct point2d : point1d
{
    int x, y;
    point2d()
    {
        cout << "Point2d is called : " << endl;
    }

    ~point2d()
    {
        cout << "Point2d destructor is called : " << endl;
    }
};

struct point3d : point2d
{
    int x, y, z;
    point3d()
    {
        cout << "Point3d is called : " << endl;
    }

    ~point3d()
    {
        cout << "Point3d destructor is called : " << endl;
    }
};

// first inheritance, left to right , then variables
struct multilevel : point3d, point1d
{

    point2d p2d;

    multilevel()
    {
        cout << "multilevel is called  : " << endl;
    }

    ~multilevel()
    {
        cout << "multilevel destructor : " << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    multilevel p1;
    cin.get();
    return 0;
}
