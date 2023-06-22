#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <limits.h>

using namespace std;

// to clone the graph
vector<vector<int>> printGraph(int V, vector<int> adj[])
{

    vector<vector<int>> graph;
    for (int i = 0; i < V; i++)
    {
        vector<int> vertexEdges;
        vertexEdges.push_back(i);
        for (auto j : adj[i])
        {
            vertexEdges.push_back(j);
        }
        graph.push_back(vertexEdges);
    }

    return graph;
}

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> result;
    if (V == 0)
        return result;
    bool visited[] = {false};
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int vertex = q.front();
        result.push_back(vertex);
        q.pop();
        for (auto edge : adj[vertex])
        {
            if (!visited[edge])
            {
                q.push(edge);
                visited[edge] = true;
            }
        }
    }

    return result;
}

// Function to find distance of nearest 1 in the grid for each cell.
// * mutlisource BFS

struct triplet
{
    int row;
    int col;
    int distance;
};

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    vector<vector<int>> result(rowCount, vector<int>(colCount));
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount));
    queue<triplet> q;

    // traverse through given matrix and find all cells having value 1 and put it in the queue
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            if (grid[row][col] == 1)
            {
                q.push({row, col, 0}); // 0 indicating distance to nearest 1 since it's already 1 then it's distance will 0
                visited[row][col] = true;
                result[row][col] = 0;
            }
        }
    }

    // now go through the each cells in queue and do movement in all 4 directions until queue is empty
    // *nxm time
    while (!q.empty())
    {
        triplet temp = q.front();
        q.pop();

        // check for left
        if (temp.col - 1 >= 0 && visited[temp.row][temp.col - 1] == false)
        {
            result[temp.row][temp.col - 1] = temp.distance + 1;
            visited[temp.row][temp.col - 1] = true;
            q.push({temp.row, temp.col - 1, temp.distance + 1});
        }

        // check for right
        if (temp.col + 1 < colCount && visited[temp.row][temp.col + 1] == false)
        {
            result[temp.row][temp.col + 1] = temp.distance + 1;
            visited[temp.row][temp.col + 1] = true;
            q.push({temp.row, temp.col + 1, temp.distance + 1});
        }

        // check for top

        if (temp.row - 1 >= 0 && visited[temp.row - 1][temp.col] == false)
        {
            result[temp.row - 1][temp.col] = temp.distance + 1;
            visited[temp.row - 1][temp.col] = true;
            q.push({temp.row - 1, temp.col, temp.distance + 1});
        }

        // check for bottom
        if (temp.row + 1 < rowCount && visited[temp.row + 1][temp.col] == false)
        {
            result[temp.row + 1][temp.col] = temp.distance + 1;
            visited[temp.row + 1][temp.col] = true;
            q.push({temp.row + 1, temp.col, temp.distance + 1});
        }
    }

    return result;
}

// Function to find minimum time required to rot all oranges.
int orangesRotting(vector<vector<int>> &grid)
{
    int rowCount = grid.size();
    int colCount = grid[0].size();
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount));
    queue<triplet> q;
    int minTime = 0;
    int freshOranges = 0;

    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            if (grid[row][col] == 1)
            {
                freshOranges += 1;
            }
            else if (grid[row][col] == 2)
            {
                // distance or rotten with itself will be 0
                visited[row][col] = true;
                q.push({row, col, 0});
            }
        }
    }

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        // check for fresh oranges top, bottom,left,right
        if (temp.row - 1 >= 0 && visited[temp.row - 1][temp.col] == false && grid[temp.row - 1][temp.col] == 1)
        {

            q.push({temp.row - 1, temp.col, temp.distance + 1});
            visited[temp.row - 1][temp.col] = true;
            minTime = max(minTime, temp.distance + 1);
            freshOranges -= 1;
        }

        if (temp.row + 1 < rowCount && visited[temp.row + 1][temp.col] == false && grid[temp.row + 1][temp.col] == 1)
        {

            q.push({temp.row + 1, temp.col, temp.distance + 1});
            visited[temp.row + 1][temp.col] = true;
            minTime = max(minTime, temp.distance + 1);
            freshOranges -= 1;
        }

        if (temp.col - 1 >= 0 && visited[temp.row][temp.col - 1] == false && grid[temp.row][temp.col - 1] == 1)
        {

            q.push({temp.row, temp.col - 1, temp.distance + 1});
            visited[temp.row][temp.col - 1] = true;
            minTime = max(minTime, temp.distance + 1);
            freshOranges -= 1;
        }

        if (temp.col + 1 < colCount && visited[temp.row][temp.col + 1] == false && grid[temp.row][temp.col + 1] == 1)
        {

            q.push({temp.row, temp.col + 1, temp.distance + 1});
            visited[temp.row][temp.col + 1] = true;
            minTime = max(minTime, temp.distance + 1);
            freshOranges -= 1;
        }
    }

    if (freshOranges == 0)
        return minTime;

    return -1;
}

// Function to find the number of islands.

int dfs(pair<int, int> cell, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    queue<pair<int, int>> q;
    q.push({cell.first, cell.second});
    while (!q.empty())
    {
        auto tempCell = q.front();
        q.pop();
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; i++)
        {
            int newX = tempCell.first + dx[i];
            int newY = tempCell.second + dy[i];
            if (newX >= 0 && newY >= 0 && newX < rowCount && newY < colCount && grid[newX][newY] == '1' && visited[newX][newY] == false)
            {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    int islandCount = 0;
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            if (grid[row][col] == '1' && visited[row][col] == false)
            {
                islandCount++;
                dfs({row, col}, grid, visited);
            }
        }
    }
    return islandCount;
}

// Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // convert to 0-based indexing
    KnightPos[0] = KnightPos[0] - 1;
    KnightPos[1] = KnightPos[1] - 1;
    TargetPos[0] = TargetPos[0] - 1;
    TargetPos[1] = TargetPos[1] - 1;
    int rowCount = N;
    int colCount = N;
    int minStep = INT_MAX;
    queue<triplet> q;
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount));

    // this is designed on the basis of knight kept at 0,0 and all possible positions it can go
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
    q.push({KnightPos[0], KnightPos[1], 0});
    if (KnightPos == TargetPos)
    {
        return 0;
    }

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int newRow = temp.row + dx[i];
            int newCol = temp.col + dy[i];
            if (newRow >= 0 && newCol >= 0 && newRow < rowCount && newCol < colCount && visited[newRow][newCol] == false)
            {
                // cout << "Row : " << newRow << ", col : " << newCol << ", Distance : " << temp.distance << endl;
                visited[newRow][newCol] = true;
                q.push({newRow, newCol, temp.distance + 1});
                if (newRow == TargetPos[0] && newCol == TargetPos[1])
                {
                    minStep = min(minStep, temp.distance + 1);
                }
            }
        }
    }
    return minStep;
}

// Function to find whether a path exists from the source to destination.
bool is_Possible(vector<vector<int>> &grid)
{
    const int SOURCE = 1;
    const int TARGET = 2;
    const int BLANK_CELL = 3;
    const int WALL = 0;
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    pair<int, int> targetPos;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            if (grid[row][col] == SOURCE)
            {
                q.push({row, col});
                visited[row][col] = true;
            }
            else if (grid[row][col] == TARGET)
            {
                targetPos.first = row;
                targetPos.second = col;
            }
            //  we can't go to wall to make them already visited.
            else if (grid[row][col] == WALL)
            {
                visited[row][col] = true;
            }
        }
    }

    cout << "Source Position : " << q.front().first << " " << q.front().second << endl;
    cout << "Destination position : " << targetPos.first << " " << targetPos.second << endl;

    while (!q.empty())
    {
        auto source = q.front();
        q.pop();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = source.first + dx[i];
            int newCol = source.second + dy[i];
            if (newRow >= 0 && newCol >= 0 && newRow < rowCount && newCol < colCount && visited[newRow][newCol] == false)
            {
                if (newRow == targetPos.first && newCol == targetPos.second)
                {
                    return 1;
                }
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{3, 3, 3, 3, 0, 0, 3, 0}, {1, 3, 3, 3, 3, 3, 3, 2}, {3, 3, 0, 3, 0, 3, 3, 3}, {3, 3, 3, 0, 0, 3, 3, 0}, {0, 3, 3, 3, 3, 3, 3, 3}, {0, 0, 0, 3, 3, 0, 3, 3}, {0, 3, 0, 3, 3, 3, 3, 0}, {3, 3, 3, 0, 3, 3, 3, 3}};

    cout
        << "is Path possible  : " << is_Possible(grid) << endl; // suppose to return ans : 1

    return 0;
}
