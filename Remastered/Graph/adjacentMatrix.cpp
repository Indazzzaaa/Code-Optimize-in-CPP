#include <iostream>
#include <vector>
#include "Graph.cpp"
using namespace std;

#define cout2(msg) std::cout << msg << std::endl
class AdjacentMatrix : public Graph
{
private:
    int **container;

public:
    AdjacentMatrix(int vertexCount, bool isDirected = false) : Graph(vertexCount)
    {
        this->isDirected = isDirected;
        container = new int *[vertexCount];
        for (int i = 0; i < vertexCount; i++)
        {
            container[i] = new int[vertexCount]{0};
        }
        cout << "Graph  created with : " << vertexCount << " vertex " << std::endl;
    }
    void insertEdge(int vertex_from, int vertex_to, int weight = 1)
    {
        if (vertex_from < 0 || vertex_from > (vertexCount - 1))
        {
            cout << "Vertex from is not a valid vertex " << endl;
            return;
        }

        if (vertex_to < 0 || vertex_to > (vertexCount - 1))
        {
            cout << "Vertex_to is not a valid vertex " << endl;
            return;
        }

        container[vertex_from][vertex_to] = weight;
        if (!isDirected)
        {
            container[vertex_to][vertex_from] = weight;
        }
    }

    void deleteEdge(int vertex_from, int vertex_to)
    {
        if (vertex_from < 0 || vertex_from > (vertexCount - 1))
        {
            cout << "Vertex from is not a valid vertex " << endl;
            return;
        }

        if (vertex_to < 0 || vertex_to > (vertexCount - 1))
        {
            cout << "Vertex_to is not a valid vertex " << endl;
            return;
        }

        container[vertex_from][vertex_to] = 0;
        if (!isDirected)
        {
            container[vertex_to][vertex_from] = 0;
        }
    }
    void insertVertex()
    {
        int **newContainer = new int *[vertexCount + 1];
        for (int i = 0; i < vertexCount; i++)
        {
            newContainer[i] = extendRow(container[i]);
        }
        newContainer[vertexCount] = extendRow(NULL);

        vertexCount += 1;
        cout << "Vertex no. : " << vertexCount - 1 << " Added ." << endl;
        container = newContainer;
    }

    int *extendRow(int *old)
    {
        int *newRow = new int[vertexCount + 1]{0};
        if (old == NULL)
        {
            return newRow;
        }

        for (int i = 0; i < vertexCount; i++)
        {
            newRow[i] = old[i];
        }
        // deleting the old rows
        delete[] old;

        return newRow;
    }
    void deleteVertex(int vertexNum) { std::cout << "vertex deleted"; }
    void traverseGraph()
    {
        cout << "  " << 0 << " ";
        for (int i = 1; i < vertexCount; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int row = 0; row < vertexCount; row++)
        {
            cout << row << " ";
            for (int col = 0; col < vertexCount; col++)
            {
                cout << container[row][col] << " ";
            }
            cout << endl;
        }
    }
    void serializeGraph() { std::cout << "Serialization of graph completed"; }
    void deserialzieGraph()
    {
        cout2("Deserialize graph completed ");
    }

    // This is for  displaying the graph in cpp
    std::ostream &print(std::ostream &os) const
    {
        for (int i = 0; i < vertexCount; i++)
        {
            os << "Vertex : " << i << " ==>";
            os << " Edges To : ";
            for (int j = 0; j < vertexCount; j++)
            {
                if (container[i][j] != 0)
                    os << " " << j << " ";
            }
            os << endl;
        }

        return os;
    }

    ~AdjacentMatrix()
    {
        cout << "Adjacent matrix destructor is called : " << endl;
        for (int i = 0; i < vertexCount; i++)
        {
            delete[] container[i];
        }
        delete[] container;
    }
};