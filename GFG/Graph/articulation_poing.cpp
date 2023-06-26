#include <iostream>
#include <vector>
using namespace std;

// returned values is lowest discovery time found
void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &articulationPoints, vector<int> &dis, vector<int> &lowDisReach, int &disCount, int src = 0, int parent = -1)
{

    visited[src] = true;
    int colSize = graph[src].size();
    disCount++;
    dis[src] = disCount;
    lowDisReach[src] = disCount; // it will help on comparison and also handle the case colSize == 1 || parent == -1
    int count = 0;               // This is to count how many times our graph went in graph[src][i] != 0 && visited[i] == false case
    // we will also construct the discovery time and smallest discovery time reachable
    // ? how will we find the lowest discovery time reachable from vertex, we'll return the vertex.
    // ? what are the candidates for that 1. parent ==-1, 2. it's own discovery time

    for (int i = 0; i < colSize; i++)
    {

        if (graph[src][i] != 0 && visited[i] == false)
        {
            count++;
            dfs(graph, visited, articulationPoints, dis, lowDisReach, disCount, i, src);
            // we are checking for root in another way
            if (dis[src] <= lowDisReach[i] && parent != -1)
            {
                articulationPoints.push_back(src);
            }
        }
        // there should be edge but we won't consider the parent one
        // if you see we are building it in bottom up manner.For lowDisReach
        if (graph[src][i] != 0 && i != parent)
        {
            lowDisReach[src] = min(lowDisReach[src], lowDisReach[i]);
        }

        // for checking the root .
        if (count > 1 && parent == -1)
        {
            articulationPoints.push_back(src);
        }
    }

    // Time complexity : o(V+E)
}

void articulationPointTest()
{
    vector<vector<int>> graph = {{0, 1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 1, 0}};
    vector<bool> visited(graph.size(), false);
    vector<int> articulationPoints;
    vector<int> dis(graph.size());
    vector<int> lowDisReach(graph.size());
    int disCount = 0;
    dfs(graph, visited, articulationPoints, dis, lowDisReach, disCount);
    // debugging
    cout << "v: ";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    cout << "d: ";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << dis[i] << "\t";
    }
    cout << endl;

    cout << "l: ";
    for (int i = 0; i < graph.size(); i++)
    {
        cout << lowDisReach[i] << "\t";
    }
    cout << endl;

    cout << "AP: ";
    for (auto point : articulationPoints)
    {
        cout << point << "\t";
    }
    cout << endl;
}

int main()
{
    articulationPointTest();
}