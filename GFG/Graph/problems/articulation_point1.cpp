#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// ! there is something new to learn while passing parent as &parent, Just rember at every call stack it just refer to memory location
// ! and changing the memory it points to will change it's value at every call stack . (Very powerfull to see full result go to debug mode and see how the parent value reset to last point varialbe after call ends)
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

    vector<int> adj2[] = {
        {1},
        {4},
        {3, 4},
        {2, 4},
        {1, 2, 3}};

    vector<int> adj[] = {
        {1, 2},
        {0},
        {0}};
    int v = 3;
    auto res = articulationPoints(v, adj);
    cout << "Printing the result : ";
    for (auto i : res)
        cout << i << " ";

    return 0;
}
