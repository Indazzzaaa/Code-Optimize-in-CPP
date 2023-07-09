
// !this algo detect wheter given edge is bridge or not but we can modify it for finding all the bridges in the graph
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int node, int &parent, int &timer, vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<int> adj[], int &c, int &d, bool &isFound)

{
    visited[node] = true;
    low[node] = disc[node] = timer++;
    for (auto nbr : adj[node])
    {
        if (parent == nbr)
        {
            continue;
        }

        if (!visited[nbr])
        {
            dfs(nbr, node, timer, low, disc, visited, adj, c, d, isFound);
            if (isFound)
                return;
            low[node] = min(low[node], low[nbr]);

            if (disc[node] < low[nbr])
            {
                // ! this is important , we have to consider both possibilty edge from b---c or c---b in both cases anyone can occur first while doing our calculation.
                if ((node == c || node == d) && nbr == (c + d - node))
                    isFound = true;
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<bool> visited(V, false);
    vector<int> low(V, -1);
    vector<int> disc(V, -1);
    int timer = 0;
    bool isFound = false;
    int parent = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, low, disc, visited, adj, c, d, isFound);
        }
    }

    return isFound;
}

int main(int argc, char const *argv[])
{
    vector<int> adj1[] = {
        {1},
        {0, 2, 3},
        {1, 4, 5},
        {1},
        {2},
        {2}};

    vector<int> adj[] = {
        {1},
        {0},
        {3},
        {2, 4},
        {3},
        {6},
        {5}};

    int v = 7;
    cout << "Is it the bridge : " << isBridge(v, adj, 5, 6);
    return 0;
}
