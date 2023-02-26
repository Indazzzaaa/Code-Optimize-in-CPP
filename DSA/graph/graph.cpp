#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define show(x) cout << "[" << x << "]"
#define LINK "-->"

struct graph
{
    vector<vector<int>> container;
    graph()
    {
        cout << "Graph initialization completd" << endl;
    }

    void insertVertices()
    {

        container.push_back(vector<int>());
        cout << "vertices count : " << container.size() << endl;
    }

    void insert_edge_undirected(int from, int to)
    {
        if (from >= container.size())
        {
            cout << "Your from : " << from << " Out of bound of container " << endl;
            return;
        }
        if (to >= container.size())
        {
            cout << "Your to : " << to << " Out of bound of container " << endl;
            return;
        }

        container[from].push_back(to);
        container[to].push_back(from);
        cout << "Edge from : " << from << " To : " << to << " inserted [Bidirectional]" << endl;
    }

    void insert_edge_directed(int from, int to)
    {

        if (from >= container.size())
        {
            cout << "Your from : " << from << " Out of bound of container " << endl;
            return;
        }
        if (to >= container.size())
        {
            cout << "Your to : " << to << " Out of bound of container " << endl;
            return;
        }

        container[from].push_back(to);

        cout << "Edge from : " << from << " To : " << to << " inserted " << endl;
    }

    int getVertexCount() const
    {
        return container.size();
    }

    void printGraph() const
    {
        for (int i = 0; i < container.size(); i++)
        {
            show(i);
            cout << LINK;
            cout << " (";
            for (int j = 0; j < container[i].size(); j++)
            {
                cout << container[i][j] << ",";
            }

            cout << ") ";
            cout << endl;
        }
    }

    void BFS(bool debug = true)
    {
        int vertexCount = getVertexCount();
        bool visited[vertexCount] = {false};
        queue<int> q;
        q.push(0);
        visited[0] = true;
        if (debug)
            cout << "BFS of graph is : ";
        while (!q.empty())
        {
            int curr = q.front();
            if (debug)
                cout << curr << " ";
            q.pop();
            auto &edges = container[curr];
            for (int i = 0; i < edges.size(); i++)
            {
                if (!visited[edges[i]])
                {
                    q.push(edges[i]);
                    visited[edges[i]] = true;
                }
            }
        }
        if (debug)
            cout << "\t[BFS Completed]  " << endl;
    }

    void countIslands_BFS()
    {
        bool visited[container.size()] = {false};
        int count = 0;
        for (int i = 0; i < container.size(); i++)
        {
            if (!visited[i])
            {
                BFS_for_islands(visited, i, false);
                count++;
            }
        }

        cout << "[BFS]Number of islands are : " << count << endl;
    }

    void DFS(bool *visited, int source)
    {
        auto &edges = container[source];
        cout << source << " ";
        visited[source] = true;
        for (int i = 0; i < edges.size(); i++)
        {
            if (!visited[edges[i]])
            {
                DFS(visited, edges[i]);
            }
        }
    }

    void testDFS()
    {
        cout << "DFS of graph is : ";
        bool visited[container.size()] = {false};
        int count = 0;
        for (int i = 0; i < container.size(); i++)
        {
            if (!visited[i])
            {
                DFS(visited, i);
                count++;
            }
        }
        cout << "\n[DFS completed] " << endl;

        cout << "[DFS]Number of islands are : " << count << endl;
    }

    void shortestPath()
    {

        int path[container.size()] = {0};
        bool visited[container.size()] = {false};
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            auto &v = container[curr];
            for (int i = 0; i < v.size(); i++)
            {
                if (!visited[v[i]])
                {
                    q.push(v[i]);
                    path[v[i]] = path[curr] + 1;
                    visited[v[i]] = true;
                }
            }
        }

        cout << " Shortest path we got is : ";
        for_each(path, path + container.size(), [](int element)
                 { cout << element << " "; });
        cout << "\t[Path compeleted]" << endl;
    }

    bool detectCycle_undirected(bool *visited, int source, int parent)
    {
        visited[source] = true;
        auto &v1 = container[source];
        for (int i = 0; i < v1.size(); i++)
        {
            if (!visited[v1[i]])
            {
                if (detectCycle_undirected(visited, v1[i], source))
                    return true;
            }
            else
            {
                if (v1[i] != parent)
                {
                    cout << " Found  cycle between : " << v1[i] << " and " << source << endl;
                    return true;
                }
            }
        }

        return false;
    }

    void cycle_test_undirected()
    {

        bool visited[container.size()] = {false};
        for (int i = 0; i < container.size(); i++)
        {
            if (!visited[i])
            {
                if (detectCycle_undirected(visited, 0, 0))
                {
                    return;
                }
            }
        }

        cout << "No cycle exist in this graph" << endl;
    }

    //  * Topoligical sort( application : deciding which file to compile first by compiler)
    void topological_sort(bool debug = true)
    {

        if (container.size() == 0)
        {
            cout << "No vertex exist " << endl;
            return;
        }

        int indegree[container.size()] = {0};
        queue<int> q; // to store the vertex having 0 indegrees
        // filling the indegree list
        for (int i = 0; i < container.size(); i++)
        {
            auto &edges = container[i];
            for (int i = 0; i < edges.size(); i++)
            {
                indegree[edges[i]]++;
            }
        }

        //  printing the indegrees
        if (debug)
            for (int i = 0; i < container.size(); i++)
            {
                cout << "Indegree of vertex : " << i << " is : " << indegree[i] << endl;
            }
        // putting those indegrees into the queue having 0 indegeres
        for (int i = 0; i < container.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                cout << curr << " ";
                // since this vertex has been printed now go to all edges from this vertex and decrease there indegree by 1 and if becomes 0 add to the queue
                auto &edges = container[curr];
                for (int i = 0; i < edges.size(); i++)
                {
                    indegree[edges[i]]--;
                    //  push the vertex to queue if there is not any indegree(==0)
                    if (indegree[edges[i]] == 0)
                    {
                        q.push(edges[i]);
                    }
                }
            }
            cout << endl;
        }
        cout << "[Topological Sort Completed]" << endl;
    }

private:
    void BFS_for_islands(bool *visited, int source, bool debug = true)
    {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        if (debug)
            cout << "BFS of graph is : ";
        while (!q.empty())
        {
            int curr = q.front();
            if (debug)
                cout << curr << " ";
            q.pop();
            auto &edges = container[curr];
            for (int i = 0; i < edges.size(); i++)
            {
                if (!visited[edges[i]])
                {
                    q.push(edges[i]);
                    visited[edges[i]] = true;
                }
            }
        }
        if (debug)
            cout << "\t[BFS Completed]  " << endl;
    }
};