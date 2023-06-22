#include <iostream>

class Graph
{

protected:
    int vertexCount = 0;
    bool isDirected = false;

public:
    Graph(int initialVertex)
    {
        vertexCount = initialVertex;
    }

    virtual void insertEdge(int vertex_from, int vertex_to, int) = 0;
    virtual void deleteEdge(int vertex_from, int vertex_to) = 0;
    virtual void insertVertex() = 0;
    virtual void deleteVertex(int vertexNum) = 0;
    virtual void traverseGraph() = 0;
    virtual void serializeGraph() = 0;
    virtual void deserialzieGraph() = 0;

    // This is for  displaying the graph in cpp
    virtual std::ostream &print(std::ostream &os) const
    {
        os << "Hello from graph itself " << std::endl;
    }

    virtual ~Graph()
    {
        std::cout << "Graph destructor is called " << std::endl;
    }
};

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    return graph.print(os);
}
