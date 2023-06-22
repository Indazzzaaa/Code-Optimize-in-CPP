#include <iostream>
#include <vector>

class Graph
{
public:
    Graph(int numVertices) : adjList(numVertices) {}
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    std::ostream &print(std::ostream &os) const;

private:
    std::vector<std::vector<int>> adjList;
};

std::ostream &Graph::print(std::ostream &os) const
{
    for (int i = 0; i < adjList.size(); i++)
    {
        os << "Vertex " << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            os << adjList[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    return graph.print(os);
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    std::cout << g << std::endl;
    return 0;
}
