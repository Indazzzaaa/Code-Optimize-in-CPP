#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to find the level of node X.
int nodeLevel(int V, vector<int> adj[], int X)
{
    vector<bool> visited(V);
    queue<pair<int, int>> q;
    // check for 0th vertex node
    if (X == 0)
    {
        return 0;
    }
    // first : vertex,second:level
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty())
    {
        auto vertex = q.front();
        q.pop();
        for (auto edgeVertex : adj[vertex.first])
        {
            if (visited[edgeVertex] == false)
            {
                if (edgeVertex == X)
                {
                    return vertex.second + 1;
                }

                q.push({edgeVertex, vertex.second + 1});
                visited[edgeVertex] = true;
            }
        }
    }

    return -1;
}

// Function to count paths between two vertices in a directed graph.
//  ! Remember : source can also be destination
int countPaths(int V, vector<int> adj[], int source, int destination)
{
    queue<int> q;
    q.push(source);
    int pathCount = 0;
    if (source == destination)
    {
        pathCount++;
    }
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (auto edgeVertex : adj[vertex])
        {
            if (edgeVertex == destination)
            {
                pathCount++;
                continue;
            }

            q.push(edgeVertex);
        }
    }

    return pathCount;
}

// Function to find the number of 'X' total shapes.

void solve(pair<int, int> cell, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    // top , right,bottom,left
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    q.push({cell.first, cell.second});
    visited[cell.first][cell.second] = true;
    while (!q.empty())
    {
        auto cell = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = cell.first + dx[i];
            int newY = cell.second + dy[i];
            if (newX >= 0 && newY >= 0 && newX < rowCount && newY < colCount && grid[newX][newY] == 'X' && visited[newX][newY] == false)
            {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}

int xShape(vector<vector<char>> &grid)
{
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    int xShapeCount = 0;
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount));
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            if (grid[row][col] == 'X' && visited[row][col] == false)
            {
                xShapeCount++;
                solve({row, col}, grid, visited);
            }
        }
    }

    return xShapeCount;
}

// Function to detect cycle in an undirected graph.
// Todo: logic if node is not child and already been visited  then it's cycle

bool dfs(int vertex, int vertexCount, vector<int> adj[], vector<bool> &visited, int parent)
{
    visited[vertex] = true;

    for (auto edge : adj[vertex])
    {
        if (visited[edge] == true && edge != parent)
        {
            return true;
        }
        else if (edge != parent && dfs(edge, vertexCount, adj, visited, vertex))
        {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V);
    for (int vertex = 0; vertex < V; vertex++)
    {
        for (auto vertexEdge : adj[vertex])
        {
            if (visited[vertexEdge] == false && dfs(vertexEdge, V, adj, visited, -1))
            {
                return true;
            }
        }
    }

    return false;
}

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indeg(V, 0);
    vector<int> result;
    queue<int> q;

    // calculate the indegree of all vertex
    for (int vertex = 0; vertex < V; vertex++)
    {
        for (auto edge : adj[vertex])
        {
            indeg[edge]++;
        }
    }

    //  find the indegree with 0 vertex
    for (int vertex = 0; vertex < V; vertex++)
    {
        if (indeg[vertex] == 0)
        {
            q.push(vertex);
        }
    }

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);
        // reducing indegree of adjacents of this vertex
        for (auto edge : adj[vertex])
        {
            indeg[edge]--;
            if (indeg[edge] == 0)
                q.push(edge);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int arr[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
