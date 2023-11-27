#include <iostream>
using namespace std;
const int SIZE = 5;

bool isSafe(bool graph[SIZE][SIZE], int colorMap[SIZE], int vertex, int color)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (i == vertex)
            continue;
        if (graph[vertex][i] == true && colorMap[i] == color)
            return false;
    }
    return true;
}

bool colorized(bool graph[SIZE][SIZE], int colorMap[SIZE], int &vertex, int &colorSize)
{
    for (int i = 1; i <= colorSize; i++)
    {
        if (isSafe(graph, colorMap, vertex, i))
        {
            colorMap[vertex] = i;
            return true;
        }
    }

    cout << "Not able to color the vertex " << vertex << endl;

    return false;
}

bool graphColoring(bool graph[SIZE][SIZE], int m, int n)
{
    int colorMap[SIZE] = {0};

    for (int i = 0; i < SIZE; i++)
    {

        if (!colorized(graph, colorMap, i, m))
            return false;
    }

    cout << "Printing the vertex colors" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << colorMap[i] << endl;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    bool graph[SIZE][SIZE] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}};

    cout << "Were we able to color all : " << graphColoring(graph, 3, 4);

    return 0;
}
