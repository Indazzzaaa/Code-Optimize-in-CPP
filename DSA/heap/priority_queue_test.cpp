#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct myComp
{
    bool operator()(const pair<int, int> &p, const pair<int, int> &q) const
    {
        return q.second < p.second;
    }
};

void customTest()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
    pq.push({10, 1000});
    pq.push({5, 500});
    pq.push({8, 800});
    pq.push({3, 300});
    while (!pq.empty())
    {
        cout << pq.top().first << "  " << pq.top().second << endl;
        pq.pop();
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process started]\n\n";
    customTest();
    cout << "\n\n[Process ended ]";

    return 0;
}

void simpleTest3()
{
    priority_queue<pair<int, int>> pq;
    pq.push({10, 1000});
    pq.push({5, 500});
    pq.push({8, 800});
    pq.push({3, 300});
    while (!pq.empty())
    {
        cout << pq.top().first << "  " << pq.top().second << endl;
        pq.pop();
    }
}

void simpleTest2()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(12);
    pq.push(2);
    pq.push(5);
    pq.push(10);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

void simpleTest()
{
    priority_queue<int> pq;
    pq.push(12);
    pq.push(2);
    pq.push(5);
    pq.push(10);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
