#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    pair<int, int> p = {0, 0};
    pair<int, int> q;
    q = p;
    q.first = 1;
    cout << q.first << " " << p.first << endl;
    return 0;
}
