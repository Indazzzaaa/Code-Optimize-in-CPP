#include <iostream>
#include <vector>
using namespace std;

#define edge(x, y) cout << "( " << x << "," << y << " )" << endl

void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<pair<int, int>> &bridgeEdge, vector<int> &dis, vector<int> &lowDisReach, int &disCount, int src = 0, int parent = -1)
{

    visited[src] = true;
    int colSize = graph[src].size();
    disCount++;
    dis[src] = disCount;
    lowDisReach[src] = disCount;

    for (int i = 0; i < colSize; i++)
    {

        if (graph[src][i] != 0 && visited[i] == false)
        {
            dfs(graph, visited, bridgeEdge, dis, lowDisReach, disCount, i, src);
            // we are checking for root in another way
            // * this is the change from articulation point here we are only checking for greater not  greater equal
            if (dis[src] < lowDisReach[i] && parent != -1)
            {
                bridgeEdge.push_back({src, i});
            }
        }
        // there should be edge but we won't consider the parent one
        // if you see we are building it in bottom up manner.For lowDisReach
        if (graph[src][i] != 0 && i != parent)
        {
            lowDisReach[src] = min(lowDisReach[src], lowDisReach[i]);
        }
    }

    // Time complexity : o(V+E)
}

void bridgesTest()
{
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}};

    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}};
    vector<bool>
        visited(graph.size(), false);
    vector<pair<int, int>> bridgeEdge;
    vector<int> dis(graph.size());
    vector<int> lowDisReach(graph.size());
    int disCount = 0;
    dfs(graph, visited, bridgeEdge, dis, lowDisReach, disCount);
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

    cout << "Edges:  (src,dest)" << endl;
    for (auto point : bridgeEdge)
    {
        edge(point.first, point.second);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    bridgesTest();
    return 0;
}
