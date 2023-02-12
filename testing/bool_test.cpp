#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    bool arr[10];
    char c[100];
    vector<bool> v(10);
    cout << "Printing the bool array : " << endl;
    for_each(arr, arr + 10, [](bool element)
             { cout << element << " "; });
    cout << endl;
    cout << "Printing the bool vector " << endl;
    for_each(v.begin(), v.end(), [](bool element)
             { cout << element << "  "; });
    cout << endl;
    cout << "Printing the char array : " << endl;
    for_each(c, c + 100, [](bool element)
             { cout << element << " "; });

    return 0;
}
