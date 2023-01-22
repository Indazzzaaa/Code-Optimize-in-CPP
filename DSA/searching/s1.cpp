#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{

    system("cls");
    vector<int> v1{1, 2, 3, 4, 5};
    int arr[]{1, 2, 3, 4, 5};
    // bool s1 = binary_search(v1.begin(), v1.end(), 6);
    // vector<int>::iterator it1;
    // it1 = upper_bound(v1.begin(), v1.end(), 5);
    // cout << "Found at position : " << it1 - v.begin();

    cout << *(v1.end() - 1) << endl;

    // vector<int>::iterator lower;
    // lower = lower_bound(v1.begin(), v1.end(), 100);
    // cout << "Found at positon : " << lower - v1.begin();

    return 0;
}
