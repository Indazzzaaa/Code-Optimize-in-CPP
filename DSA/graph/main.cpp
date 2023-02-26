#include <iostream>
#include <stdlib.h>
#include "graph.cpp"
using namespace std;

void graphTest_directed()
{
    graph g;
    for (int i = 0; i < 5; i++)
    {

        g.insertVertices();
    }
    g.insert_edge_directed(0, 1);
    g.insert_edge_directed(0, 2);
    g.insert_edge_directed(3, 2);
    g.insert_edge_directed(3, 4);
    g.printGraph();
    g.topological_sort();
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]\n\n";
    graphTest_directed();
    cout << "\n\n[Process Ended]\n\n";

    return 0;
}

void graphTest_undirected()
{
    graph g;
    for (int i = 0; i < 4; i++)
    {

        g.insertVertices();
    }
    g.insert_edge_directed(0, 1);
    g.insert_edge_directed(1, 2);
    g.insert_edge_directed(2, 3);
    g.insert_edge_directed(3, 1);

    g.printGraph();
    // g.BFS();
    // g.countIslands_BFS();
    // g.testDFS();
    // g.shortestPath();
    // g.cycle_test_undirected();
}