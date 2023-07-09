/*
*Things to remember
1. How to identify the cross edge , the edge to vertex that is not part of call recursion anymore and has been processed before
2 How the stack will the form
3. Till when we'll take out the element from the stack
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> dis;
    vector<int> low;
    stack<int> st;
    vector<bool> isPre;
    int timer = 1;
    void dfs(vector<int> adj[], vector<vector<int>> &res, int s)
    {
        st.push(s);
        isPre[s] = true;
        dis[s] = low[s] = timer;
        timer++;
        for (int u : adj[s])
        {
            // for both the cases cross edge needs to be ignored
            if (dis[u] == -1)
            {
                // means not vis till now means it's a tree node
                // and also not a cross edge
                dfs(adj, res, u);
                low[s] = min(low[s], low[u]);
            }
            else if (isPre[u])
            {
                // means it's a vis node but not a cross edge
                low[s] = min(low[s], dis[u]);
            }
        }
        // found an entry point after traversal
        // thus pushing all nodes till entry point from stack
        if (dis[s] == low[s])
        {
            vector<int> temp;
            while (!st.empty() and st.top() != s)
            {
                temp.push_back(st.top());
                isPre[st.top()] = false;
                st.pop();
            }
            temp.push_back(st.top());
            isPre[st.top()] = false;
            st.pop();
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
    }

public:
    // Function to return a list of lists of integers denoting
    //  the members of strongly connected components in graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        isPre = vector<bool>(V, false);
        // discovery time can be used to detect cross edges
        // it will be used for visited array
        dis = vector<int>(V, -1);
        low = vector<int>(V, 1e9);
        vector<vector<int>> res;
        // for disconnected components
        for (int i = 0; i < V; i++)
        {
            if (dis[i] == -1)
                dfs(adj, res, i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
