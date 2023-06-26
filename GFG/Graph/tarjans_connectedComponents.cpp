#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &isInRecursionStack, stack<int> &st, vector<int> &dis, vector<int> &lowDisReach, int &disCount, int src = 0, int parent = -1)
{

    // * as we know this is for directed graph , here we using stack  as keeping track of vertices in recursion call stack
    // * which will help us to find the cross edges. (edges which have been processed and not part of the recursion call stack)
    visited[src] = true;
    int colSize = graph[src].size();
    disCount++;
    dis[src] = disCount;
    lowDisReach[src] = disCount;
    st.push(src);
    isInRecursionStack[src] = true;

    for (int i = 0; i < colSize; i++)
    {

        if (graph[src][i] != 0 && visited[i] == false)
        {
            dfs(graph, visited, isInRecursionStack, st, dis, lowDisReach, disCount, i, src);
        }

        //  * we using inInRecusionStack array to keep track of the vertices that are part of the recusion stack.
        //  * so we can deal with the cross edges
        if (graph[src][i] != 0 && i != parent)
        {
            if (visited[i] == true && isInRecursionStack[i] == true)
                lowDisReach[src] = min(lowDisReach[src], lowDisReach[i]);
        }
    }

    // once the all adjacent has been processed then go for the checking lowDisReach == dis
    if (lowDisReach[src] == dis[src])
    {
        while (st.top() != src)
        {

            // * for cross edge
            isInRecursionStack[st.top()] = false;
            cout << st.top() << " ";
            st.pop();
        }
        // print the last element of connected component.
        //  * for cross edge
        isInRecursionStack[st.top()] = false;
        cout << st.top() << " ";
        st.pop();
        cout << endl;
    }

    // Time complexity : o(V+E)
}

void tarjansTest()
{

    vector<vector<int>> graph1 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    // !test case having cross edge
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}};
    vector<bool> visited(graph.size(), false);
    vector<int> dis(graph.size());
    vector<int> lowDisReach(graph.size());
    stack<int> st;
    vector<bool> isInRecursionStack(graph.size());
    int disCount = 0;
    dfs(graph, visited, isInRecursionStack, st, dis, lowDisReach, disCount);
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
}

int main(int argc, char const *argv[])
{
    tarjansTest();
    return 0;
}
