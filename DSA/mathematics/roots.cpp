#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;

vector<int> rootsOfQuadri(int, int, int);

int main(int argc, char const *argv[])
{
    system("cls");
    vector<int> check;

    vector<int> result = rootsOfQuadri(1, -7, 12);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    cin.get();
    

    return 0;
}

// finding sqroots of the quadratic equation
vector<int> rootsOfQuadri(int a, int b, int c)
{

    // code here

    int d = (b * b) - (4 * a * c);

    vector<int> v;

    if (d < 0)

    {

        v.push_back(-1);

        return v;
    }

    int k = sqrt(d);

    int r1, r2;

    r1 = (-b + k) / (2 * a);

    r2 = (-b - k) / (2 * a);

    v.push_back(max(r1, r2));

    v.push_back(min(r1, r2));

    return v;
}