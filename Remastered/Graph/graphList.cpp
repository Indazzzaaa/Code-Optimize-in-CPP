#include<iostream>
#include "Graph.cpp"

# define cout2(msg) std::cout<<msg<< std::endl
class graphList : public Graph
{
public:
    graphList(int vertexCount) : Graph(vertexCount) {}
    void insertEdge(int vertex_from , int vertex_to) { std::cout << "Edge inserted"; }
    void deleteEdge(int vertex_from , int vertex_to) { std::cout << "Edge deleted"; }
    void insertVertex() { std::cout << "Vertex inseted "; }
    void deleteVertex(int vertexNum) { std::cout << "vertex deleted"; }
    void traverseGraph() { std::cout << "Traversing finished"; }
    void serializeGraph() { std::cout << "Serialization of graph completed"; }
    void deserialzieGraph() {
        cout2("Deserialize graph completed ");
    }

    // This is for  displaying the graph in cpp
    virtual std::ostream &print(std::ostream &os) const
    {
        os << "Hello from adjacency list" << std::endl;
    }
};