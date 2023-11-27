// graph coloring problem
#include <iostream>
using namespace std;
const int SIZE = 101;

bool isSafe(bool graph[SIZE][SIZE], int colorMap[SIZE], int vertex, int color)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (graph[vertex][i] == true && colorMap[i] == color)
            return false;
    }
    return true;
}

bool colorize(bool graph[SIZE][SIZE], int colorMap[SIZE], int vertex, int colorCount)
{
}

bool graphColoring(bool graph[SIZE][SIZE], int m, int n)
{

    int colorMap[SIZE] = {};
    // find the vertex
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (colorMap[i][j] != 0)
                break; // go for checking the next vertex
            if (graph[i][j])
            {
                if (!colorize(graph, colorMap, i, m))
                    return false;
            }
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    SIZE = 5;
    bool graph[SIZE][SIZE] = {{0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};
    return 0;
}
