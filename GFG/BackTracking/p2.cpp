// Todo: Implement solution for RAT-IN_MAZE problem
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

    vector<vector<int>> maze;
    vector<vector<int>> solnMaze;
    int size;

    bool isSafe(int row, int col)
    {

        return (row < size && col < size) && (maze[row][col] == 1);
    }

public:
    Solution(vector<vector<int>> &tempMaze, int n)
    {
        maze = tempMaze;

        size = n;
        for (int i = 0; i < size; i++)
        {
            vector<int> temp(size, 0);
            solnMaze.push_back(temp);
        }

        // first cell will be always 1
        solnMaze[0][0] = 1;
    }

    bool solve(int row = 0, int col = 0)
    {
        // I choose to go first bottom and then check for right cell if bottom does not lead to valid solution

        if (row == (size - 1) && col == (size - 1))
            return true;

        // * check bottom cell
        // this second will only fill the cell while in retrun time
        if (isSafe(row + 1, col) && solve(row + 1, col))
        {

            solnMaze[row + 1][col] = 1;
            return true;
        }

        if (isSafe(row, col + 1) && solve(row, col + 1))
        {
            solnMaze[row][col + 1] = 1;
            return true;
        }

        return false;
    }

    void showMaze()
    {

        cout << "[Input]" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << maze[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void showSolutionMaze()
    {
        cout << "[Solution]" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << solnMaze[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 1, 1},
                                {1, 1, 1, 1}};

    Solution sln = Solution(maze, maze.size());
    sln.showMaze();
    if (sln.solve())
        sln.showSolutionMaze();
    else
    {
        cout << "Not able to reach the destination ." << endl;
    }
    return 0;
}
