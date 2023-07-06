#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void dfs(int node, int &parent, int &timer, vector<int> &low, vector<int> &disc, vector<bool> &vis, vector<int> adj[], set<int> &ans)

{

    vis[node] = true;

    // * we took the timer to start from 0 instead of 1
    low[node] = disc[node] = timer++;
    // cout << "For vertex : " << node << " timer is : " << disc[node] << endl;

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

        ans.insert(node);
    }
}

void log(vector<int> &dis, vector<int> &low, vector<int> &ap)
{

    cout << "V\tD\tL" << endl;
    for (int i = 0; i < dis.size(); i++)
    {
        cout << i << "\t" << dis[i] << "\t" << low[i] << endl;
    }

    cout << "Articulation points are ! " << endl;
    for (auto points : ap)
        cout << points << " ";
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

    // log(disc, low, res);

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
        {10},
        {},
        {11},
        {8, 12},
        {18, 24},
        {18},
        {15, 23},
        {14},
        {3, 9},
        {8},
        {0},
        {2, 16},
        {3},
        {23},
        {7},
        {6},
        {11},
        {},
        {4, 5, 19},
        {18, 22},
        {},
        {},
        {19},
        {6, 13},
        {4},
        {},
    };
    int v = 26;
    articulationPoints(v, adj);

    return 0;
}

/*
does not worked for
26 15
0 10
2 11
3 8
3 12
4 18
4 24
5 18
6 15
6 23
7 14
8 9
11 16
13 23
18 19
19 22
nodes are : 0 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 18 19 22 23 24


our output: 0 8 11 18 19 23
correct output: 3 4 6 8 11 18 19 23



 */
