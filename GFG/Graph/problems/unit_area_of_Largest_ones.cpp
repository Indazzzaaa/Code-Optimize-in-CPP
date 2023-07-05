#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int &islandLength, pair<int, int> cell)
{
    visited[cell.first][cell.second] = true;
    islandLength++;
    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    // clockwise direction
    // first half is for just direction and second half is for diagonal 4-4
    int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
    int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};

    for (int i = 0; i < 8; i++)
    {
        pair<int, int> tempCell = {cell.first + dx[i],
                                   cell.second + dy[i]};
        if (tempCell.first > -1 && tempCell.first < rowCount && tempCell.second > -1 && tempCell.second < colCount)
        {
            if (visited[tempCell.first][tempCell.second] == false && grid[tempCell.first][tempCell.second] == 1)
            {
                dfs(grid, visited, islandLength, tempCell);
            }
        }
    }
}

int findMaxArea(vector<vector<int>> &grid)
{

    const int rowCount = grid.size();
    const int colCount = grid[0].size();
    vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
    int islandLength = 0;
    int result = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (visited[i][j] == false && grid[i][j] == 1)
            {
                dfs(grid, visited, islandLength, {i, j});
                result = max(result, islandLength);
                islandLength = 0;
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};
    cout << "Max area is : " << findMaxArea(grid);
    return 0;
}
