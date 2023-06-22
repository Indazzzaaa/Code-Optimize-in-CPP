#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfsTraversal(vector<vector<int>> &graph, stack<int> &st, vector<bool> &visited, int source)
{
    visited[source] = true;
    for (int vertex : graph[source])
    {
        if (visited[vertex] == false)
        {
            dfsTraversal(graph, st, visited, vertex);
        }
    }
    st.push(source);
}

void dfsTraversal_normal(vector<vector<int>> &graph, vector<bool> &visited, int source)
{
    cout << source << " ";
    visited[source] = true;
    for (int vertex : graph[source])
    {
        if (visited[vertex] == false)
        {
            dfsTraversal_normal(graph, visited, vertex);
        }
    }
}

void dfs(vector<vector<int>> &graph, stack<int> &st)
{
    vector<bool> visited(graph.size(), false);
    int row = graph.size();
    for (int i = 0; i < row; i++)
    {
        if (visited[i] == false)
        {
            dfsTraversal(graph, st, visited, i);
        }
    }
}

void connectedComponent_KosaRajus(vector<vector<int>> &graph)
{
    // step1. find the vertices in order of there finish time
    stack<int> finishTime;
    dfs(graph, finishTime);
    while (!finishTime.empty())
    {
        cout << finishTime.top() << endl;
        finishTime.pop();
    }
    // step2. revers all the edges in the graph
    //  m1 create the all new graph
    vector<vector<int>> reverseEdgesGraph(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        for (int vertex : graph[i])
        {
            reverseEdgesGraph[vertex].push_back(i);
        }
    }

    // step3. do dfs again but now on the stack we got and print all the connected components
    cout << endl
         << "Printing the connected components" << endl;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == false)
        {

            dfsTraversal_normal(reverseEdgesGraph, visited, i);
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph(5);
    graph[0] = {1};
    graph[1] = {2, 3};
    graph[2] = {0};
    graph[3] = {4};
    connectedComponent_KosaRajus(graph);
    cout << endl
         << "Program finished !" << endl;

    return 0;
}
