#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int node, int &parent, int &timer, vector<int> &low, vector<int> &disc, vector<bool> &vis, vector<int> adj[], set<int> &ans)

{

    vis[node] = true;

    low[node] = disc[node] = timer++;

    int Child = 0;

    for (auto nbr : adj[node]) //* nbr = neighbour

    {

        //* don't do anything if it's parent
        if (nbr == parent)

        {

            continue;
        }

        if (!vis[nbr])

        {

            dfs(nbr, node, timer, low, disc, vis, adj, ans);

            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= disc[node] && parent != -1)

            {

                ans.insert(node);
            }

            Child++;
        }

        else

        {

            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && Child > 1)

    {

        ans.insert(0);
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{

    // Code here

    vector<bool> vis(V, false);

    vector<int> low(V, -1);

    vector<int> disc(V, -1);

    set<int> ans;

    int parent = -1;

    int timer = 0;

    for (int i = 0; i < V; i++)

    {

        if (!vis[i])

        {

            dfs(i, parent, timer, low, disc, vis, adj, ans);
        }
    }

    vector<int> res;

    if (ans.size() == 0)

    {

        res.push_back(-1);
    }

    for (auto ele : ans)

    {

        res.push_back(ele);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> adj1[] = {
        {1, 3},
        {0, 2, 4},
        {1, 3},
        {2, 0},
        {1, 5, 6},
        {4, 6},
        {4, 5}};

    vector<int> adj[] = {
        {1},
        {4},
        {3, 4},
        {2, 4},
        {1, 2, 3}};
    int v = 5;
    articulationPoints(v, adj);

    return 0;
}

