#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
{
    vector<bool> fixed(v, false);
    vector<int> dis(v, INT_MAX);
    dis[s] = 0;
    for (int count = 0; count < v; count++)
    {

        // 1. choose the smallest of all distances
        int tempVertex = -1;
        for (int i = 0; i < v; i++)
        {
            if (fixed[i] == false)
            {
                if (tempVertex == -1)
                {
                    tempVertex = i;
                }
                else if (dis[i] < dis[tempVertex])
                {
                    tempVertex = i;
                }
            }
        }
        // 2. fixed the smallest distance vertex using greedy choice
        fixed[tempVertex] = true;
        // 3. fill all the reachable nodes that are not fixed.
        for (auto edge : adj[tempVertex])
        {
            int tempDis = dis[tempVertex] + edge[1];
            if (fixed[edge[0]] == false && tempDis < dis[edge[0]])
            {
                dis[edge[0]] = tempDis;
            }
        }
    }

    return dis;
}

int main(int argc, char const *argv[])
{

    return 0;
}
