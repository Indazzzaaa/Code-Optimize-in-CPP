#include <iostream>
#include <algorithm>
using namespace std;
struct vector3
{
    int x, y, z;
    vector3(int x, int y, int z) : x(x), y(y), z(z)
    {
        cout << "ctor called " << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector3 arr[] = {{1, 2, 3}, {2, 3, 4}};
    vector3 v3{10, 20, 30};
    vector3 v4(10, 20, 30.12);
    vector3 v5 = {10, 20, 30};
    // vector3 v6 = {10, 20, 30.12};
    int size = sizeof(arr) / sizeof(vector3);
    cout << arr[0].x << " " << arr[0].y << " " << arr[0].z << endl;
    cout << "size of arr is  : " << size << endl;
    cout << "Everything is fine " << endl;

    return 0;
}
