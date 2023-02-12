#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void queueTest()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void generateNumber()
{
    int n = 10;
    queue<string> q;
    vector<int> v = {2, 3, 4};

    for (int i = 0; i < v.size(); i++)
    {
        stringstream ss;
        ss << "" << v[i];
        q.push(ss.str());
    }

    while (n > 0)
    {
        string data = q.front();
        q.pop();
        cout << data << endl;
        n--;
        for (int i = 0; i < v.size(); i++)
        {
            stringstream ss;
            ss << data << v[i];

            q.push(ss.str());
        }
    }
}

int main(int argc, char const *argv[])
{
    generateNumber();
    return 0;
}
