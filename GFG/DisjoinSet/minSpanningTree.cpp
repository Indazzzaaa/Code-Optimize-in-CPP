#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int src;
    int dest;
    int wt;

    Edge(int _src, int _dest, int _wt)
    {
        src = _src;
        dest = _dest;
        wt = _wt;
    }
};

class Graph
{
    int vertex, edges;
    vector<Edge> edgesArr;

public:
    Graph(int _vertext, int _edges)
    {
        vertex = _vertext;
        edges = _edges;
    }

    void addEdge(int src, int dest, int wt)
    {
        edgesArr.push_back({src, dest, wt});
    }

    vector<Edge> getEdges()
    {
        return edgesArr;
    }

    int getVertexCount()
    {
        return vertex;
    }
};

bool myComp(const Edge e1, const Edge e2)
{
    return e1.wt < e2.wt;
}

class Kruskal
{
    Graph *graph;
    vector<Edge> result;
    int *parent;
    int edgeIncludedCount;

    // find will use path compression
    int find(int vertex)
    {
        if (parent[vertex] == vertex)
            return vertex;
        parent[vertex] = find(parent[vertex]);
        return parent[vertex];
    }

    // union will be simple union function
    void union_do(Edge _edge)
    {
        int src_rep = find(_edge.src);
        int dest_rep = find(_edge.dest);
        // if src_rep == dest_rep then they are part of same set and adding edge between them will create the cycle
        if (src_rep == dest_rep)
            return;

        parent[dest_rep] = src_rep;
        edgeIncludedCount++;
        result.push_back(_edge);
    }

public:
    Kruskal(Graph &_graph)
    {
        graph = &_graph;
        edgeIncludedCount = 0;
        int tempSize = graph->getVertexCount();
        parent = new int[tempSize];
        for (int i = 0; i < tempSize; i++)
        {
            parent[i] = i;
        }
    }

    vector<Edge> getMinSpanningTree()
    {
        vector<Edge> edges = graph->getEdges();
        sort(edges.begin(), edges.end(), myComp);
        int tempVertexCount = graph->getVertexCount();
        for (Edge e : edges)
        {
            if (edgeIncludedCount == (tempVertexCount - 1))
                break;
            union_do(e);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Graph graph = Graph(4, 5);
    graph.addEdge(0, 2, 5);
    graph.addEdge(0, 1, 9);
    graph.addEdge(1, 3, 8);
    graph.addEdge(3, 2, 7);
    graph.addEdge(0, 3, 10);

    Kruskal k = Kruskal(graph);
    vector<Edge> edges = k.getMinSpanningTree();

    for (int i = 0; i < edges.size(); i++)
    {
        cout << "Edge (src, dest, wt) : " << edges[i].src << " " << edges[i].dest << " " << edges[i].wt << endl;
    }

    return 0;
}
