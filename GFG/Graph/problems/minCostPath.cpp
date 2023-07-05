#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minimumCostPath(vector<vector<int>> &grid)
{
    int cost = 0;
    const int rowCount = grid.size();
    const int colCount = grid[0].size();

    int i = 0, j = 0;
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    while (i < rowCount - 1 && j < colCount - 1)
    {
        cost += grid[i][j];
        int tempCost = INT_MAX;
        int tempOperation = 0;
        for (int w = 0; w < 4; w++)
        {
            if (i + dx[w] > -1 && i + dx[w] < rowCount && j + dy[w] > -1 && j + dy[w] < colCount)
            {
                if (cost + grid[dx[w]][dy[w]] < tempCost)
                {
                    tempCost = cost + grid[dx[w]][dy[w]];
                    tempOperation = w;
                }
            }
        }

        i += dx[tempOperation];
        j += dy[tempOperation];

        // dealing with edge cases
        if ((i == rowCount - 2 && j == colCount - 1) || (i == rowCount - 1 && j == colCount - 2))
        {
            cost += grid[rowCount - 1][colCount - 1];
            return cost;
        }

        // choose which cell to fix
        // move to next cell
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};

    cout << "Min cost : " << minimumCostPath(grid);

    return 0;
}
