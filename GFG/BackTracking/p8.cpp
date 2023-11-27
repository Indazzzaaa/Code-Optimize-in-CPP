// sudoku solution
#include <iostream>
using namespace std;
const int N = 9;
bool isSafeChoice(int grid[N][N], int value, int row, int col)
{
    // check the colm
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == 0)
            continue;
        if (grid[row][i] == value)
            return false;
    }

    // check the row
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == 0)
            continue;
        if (grid[i][col] == value)
            return false;
    }

    // checking the 3x3 box , in which our cell falls into
    int s = sqrt(N);
    int rs = row - row % s;
    int cs = col - col % s;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (grid[i + rs][j + cs] == value)
                return false;
        }
    }

    return true;
}

bool SolveSudoku(int grid[N][N])
{
    int row = -1, col = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i, col = j;
            }
        }
    }

    if (row == -1 || col == -1)
    {
        return true;
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (isSafeChoice(grid, i, row, col))
            {
                grid[row][col] = i;
                if (SolveSudoku(grid))
                    return true;
                else
                    grid[row][col] = 0;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{

    return 0;
}
