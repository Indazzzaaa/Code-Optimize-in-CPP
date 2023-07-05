// mother vertex is vertex from where each vertex is reachable
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int &count, int V, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    count++;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, count, V, adj, vis);
        }
    }
}
int findMotherVertex(int V, vector<int> adj[])
{
    // Code here

    vector<int> ans;
    int count = 0;

    for (int i = 0; i < V; i++)
    {
        vector<int> vis(V, 0);
        dfs(i, count, V, adj, vis);
        if (count == V)
        {
            return i;
        }
        count = 0;
    }

    return -1;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
