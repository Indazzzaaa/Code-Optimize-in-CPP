#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    pair<int, pair<int, int>> p = {1, {2, 3}};
    cout << p.first << endl;
    cout << p.second.first << endl;
    cout << p.second.second << endl;
    return 0;
}
