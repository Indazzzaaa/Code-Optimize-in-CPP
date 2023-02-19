#include <iostream>
#include <queue>
#include <stdlib.h>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct myComp
{
    bool operator()(const pair<int, int> &p, const pair<int, int> &q) const
    {
        if (p.second == q.second)
        {
            return q.first < p.first;
        }
        else
        {
            return q.second > p.second;
        }
    }
};

void topKFreq()
{
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6};
    int size = sizeof(arr) / sizeof(int);
    unordered_map<int, int> map;
    for_each(
        arr, arr + size, [&](int element)
        { map[element]++; });
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq(map.begin(), map.end());
    int k = 3;
    cout << "Printing the top k element " << endl;
    while (k-- > 0)
    {
        cout << "Element : " << pq.top().first << " Freq : " << pq.top().second << endl;
        pq.pop();
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    // kLargestElement();
    cout << "[Process started]\n\n\n ";
    topKFreq();
    cout << "\n\n[Process Ended]";
    cin.get();
    return 0;
}

void KClosestElement(int key)
{

    int arr[5] = {10, 2, 30, 15, 8};
    int k = 2;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 5; i++)
    {
        const int &diff = arr[i] - key;
        if (pq.size() < k)
        {
            pq.push({diff, i});
        }
        else
        {
            if (pq.top().first > diff)
            {
                pq.pop();
                pq.push({diff, i});
            }
        }
    }

    cout << "Top 2 closest are : ";
    while (!pq.empty())
    {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
    cout << endl;
}