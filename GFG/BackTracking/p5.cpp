/*
Rat in maze- with some twist
1. mat[i][j] will define the how much max jump can be make for i and j
2. in case of multiple choose the nearest hop
3. if multiple nearest hop then choose the right one first
 ! 0 : block , non-zero means that many jumps.

 */

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int &N, vector<int> maze[], pair<int, int> nextPos)
{
    if (nextPos.first >= N || nextPos.second >= N)
        return false;

    return maze[nextPos.first][nextPos.second] != 0;
}

bool recJump(int N, vector<int> maze[], vector<int> solMatrix[], pair<int, int> pos = {0, 0})
{

    int jumpCount = maze[pos.first][pos.second];
    solMatrix[pos.first][pos.second] = 1;
    if (pos.first == (N - 1) && pos.second == (N - 1))
        return true;
    for (int jump = 1; jump <= jumpCount; jump++)
    {
        // first priority is go right then go down

        if (isSafe(N, maze, {pos.first + jump, pos.second}) && recJump(N, maze, solMatrix, {pos.first + jump, pos.second}))
        {
            return true;
        }

        if (isSafe(N, maze, {pos.first, pos.second + jump}) && recJump(N, maze, solMatrix, {pos.first, pos.second + jump}))
        {
            return true;
        }
    }
    solMatrix[pos.first][pos.second] = 0;
    return false;
}

void showSolution(int N, vector<int> solMatrix[])
{
    cout << "Printing the Solution matrix..." << endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cout << solMatrix[row][col] << " ";
        }
        cout << endl;
    }
}

// we have to print maze if exist otherwise have to print -1.
void solve(int N, vector<int> maze[])
{
    vector<int> solMatrix[N];
    for (int i = 0; i < N; i++)
    {

        solMatrix[i].resize(N);
    }

    if (recJump(N, maze, solMatrix))
    {
        showSolution(N, solMatrix);
        cout << "We are able to reach the destination" << endl;
    }
    else
    {
        cout << "Not reached " << -1;
    }
}

int main(int argc, char const *argv[])
{
    int N = 4;
    vector<int> maze[N] = {
        {2, 1, 0, 0},
        {2, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 1}};

    solve(N, maze);

    return 0;
}
