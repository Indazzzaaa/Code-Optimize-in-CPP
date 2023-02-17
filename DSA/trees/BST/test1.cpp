#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    vector<int> v = {2, 4, 6, 8, 10};
    cout << "upper bound of 6 is " << *upper_bound(v.begin(), v.end(), 6) << endl;
    cout << "lower bound of 6 is " << *lower_bound(v.begin(), v.end(), 6) << endl;
    
    set<int> s = {2, 4, 6, 8, 10, 10};
    cout << "upper bound of 6 is " << *s.upper_bound(6) << endl;
    cout << "lower bound of 7 is " << *s.lower_bound(7) << endl;

    cout << "printing the content of set : " << endl;
    for (auto i : s)
    {
        cout << i << " ";
    }

    cout << endl;

    map<int, int> m;
    m[10] = 20;
    m[10] = 300;
    m.insert({10, 400});
    cout << m[10] << "  " << m[200] << " " << m[10] << endl;
    cin.get();
    return 0;
}
