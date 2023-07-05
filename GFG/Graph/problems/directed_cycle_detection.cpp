bool dfs(vector<int> adj[], int s, vector<int> &visited, vector<int> &pathVisited)
{
    visited[s] = true;
    pathVisited[s] = true;
    for (auto x : adj[s])
    {
        if (visited[x] && pathVisited[x])
        {
            return true;
        }
        if (visited[x] == false)
        {
            if (dfs(adj, x, visited, pathVisited))
                return true;
        }
    }
    pathVisited[s] = false;

    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(adj, i, visited, pathVisited))
                return true;
        }
    }

    return false;
}